#include <cstdio>
#include <queue>
#include <cmath>
#include <algorithm>
#include <vector>

using namespace std;

int main(){
    int t;
    scanf("%d", &t);
    int dx, dy;
    int ca = 1;
    char x[2] = {'E', 'W'},
         y[2] = {'N', 'S'};
    while(t--){
        scanf("%d %d", &dx, &dy);
        int sx = 0, sy = 0;
        if(dx > 0){
            sx = 1;
        }else{
            dx = -dx;
        }
        if(dy > 0){
            sy = 1;
        }else{
            dy = -dy;
        }
        printf("Case #%d: ", ca++);
        for(int i = 0; i < 2 * dx; i++){
            printf("%c", x[sx]);
            sx ^= 1;
        }
        for(int i = 0; i < 2 * dy; i++){
            printf("%c", y[sy]);
            sy ^= 1;
        }
        printf("\n");
    }
}