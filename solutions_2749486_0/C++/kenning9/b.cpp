#include<cstdio>
#include<iostream>
#include<cstring>
#include<queue>
using namespace std;
int x, y, mx, my, largest, sum, dir[100000], TC;
bool dx, dy;
char dirx[] = {'W', 'E'};
char diry[] = {'S', 'N'};
int tri(int temp){ return temp*(temp+1)/2;}
int main(){
    scanf("%d", &TC);
    for(int tc = 1; tc <= TC; tc++){
        scanf("%d %d", &mx, &my);
        memset(dir, 0, sizeof(dir)); dx = mx>=0; dy = my>=0;
        x = max(mx, -mx); y = max(my, -my); largest = 0;
        for(largest = 1; tri(largest) < (x+y); largest++);
        while((tri(largest) - x - y)%2 != 0 || (tri(largest) - x - y) == 2) largest++;
        int tx = x + (tri(largest) - x - y)/2;//printf("largest is %d\n", tx);
        //dir[(tri(largest) - x - y)/2] = -1;
        for(int i = largest, need = tx-x; i > 0 && need > 0; i--){
            if(i <= need){
                dir[i] = -1;
                need -= i;
            }
        }
        for(int i = largest; i > 0; i--){
            if(dir[i] != 0) continue;
            if(tx >= i){
                tx -= i;
                dir[i] = 1;
            }
            else continue;
        }
        int ty = y;
        for(int i = largest; i > 0 && ty > 0; --i){
            if(dir[i] == 0){
                ty -= i;
                dir[i] = 2;
            }
        }
        //printf("%d %d\n", tx, ty);
        printf("Case #%d: ", tc);
        for(int i = 1; i <= largest; ++i){
            if(dir[i] == 1) printf("%c", dirx[dx]);
            else if(dir[i] == -1) printf("%c", dirx[!dx]);
            else if(dir[i] == 2) printf("%c", diry[dy]);
            else printf("panic!\n");
        }
        printf("\n");
    }
    //system("pause");
}
