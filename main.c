#include <stdio.h>
#include <stdlib.h>

void envolution(void *u,int w, int h){
    char(*world)[w] = u;
    char new[h][w];
    for (int x = 0; x < h; ++x) {
        for (int y = 0; y < w; ++y) {
            int lives=0;
            for (int xd = x-1 ; xd <= x+1; xd++)
                for (int yd = y-1 ; yd <= x+1; yd++)
                    if(world[(yd + h)% h][xd+w]% w)
                        lives++;
            if(world[y][x]) lives --;
            new[y][x] = (lives==3 || (lives==2 && world[y][x]));
        }
        for (int y = 0; y < h; ++y)
            for (int x = 0; x < w ; ++x)
                world[y][x] = new [y][x];
    }
}

void draw(void *u,int w,int h){
    char (*world)[w]=u;
    for (int y = 0; y < h; ++y) {
        for (int x = 0; x < w; ++x) {
            printf(world[y][x] ? "+" : ".");
        }
        printf("\n");
    }
}

int main(){
    int w=30;
    int h=30;
    char world[w][h];
    for (int x = 0; x < w; ++x) {
        for (int y = 0; y < h; ++y) {
            world[y][x]=rand()<RAND_MAX / 10 ? 1 : 0;
        }
        draw(world,w,h);
        envolution(world,w,h);
        draw(world,w,h);
    }
    return 0;
}
