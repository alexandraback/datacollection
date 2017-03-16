#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXN 100
int n, x, y;
int map[MAXN][2 * MAXN];
void print(){
        for (int j = 0; j <= 5; j++){
    for (int i = -10; i <= 10; i++)
            printf("%d ", map[j][i + MAXN]);
        printf("\n");
    }
}
void go(int &i, int &j){
    while(!((i == 1 || map[i - 2][MAXN + j]) && map[i - 1][MAXN + j - 1] && map[i - 1][MAXN + j + 1]) && i > 0){
//        printf("move %d,%d", i, j);
        if (map[i - 1][MAXN + j - 1] == 0) i--, j--;
        else i--, j++;
 //       printf(" to %d,%d\n", i, j);
    }
}
double dfs(int step){
 //   printf("step = %d\n", step);
    double ret = 0;
    int i, j;
    if (step > n) return 0;
    for (i = MAXN - 1; i >= 0; i--)
        if (map[i][MAXN + 0] == 1) break;
    i++;
    if (i == 0){
 //       printf("at ground %d,%d\n", i, j);
        map[0][MAXN + 0] = 1;
        if (x == 0 && y == 0) ret = 1;
        else ret = dfs(step + 1);
        map[0][MAXN + 0] = 0;
    }else{
        i += 1, j = 0;
 //       print();
        if (map[i - 1][MAXN + j - 1] == 0 && map[i - 1][MAXN + j + 1] == 0){
            int p = i, q = j;
            i = p - 1, j = q - 1;
            go(i, j);
            map[i][MAXN + j] = 1;
 //           printf("at 0.5 %d,%d\n", i, j);
 //           print();
            if (x == i && y == j) ret = 0.5;
            else ret = 0.5 * dfs(step + 1);
            map[i][MAXN + j] = 0;

            i = p - 1, j = q + 1;
            go(i, j);
            map[i][MAXN + j] = 1;
 //           printf("at 0.5 %d,%d\n", i, j);
 //           print();
            if (x == i && y == j) ret += 0.5;
            else ret += 0.5 * dfs(step + 1);
            map[i][MAXN + j] = 0;
        }else{
            go(i, j);
            map[i][MAXN + j] = 1;
  //          printf("at 1.0 %d,%d\n", i, j);
 //           print();
            if (x == i && y == j) ret = 1;
            else ret = dfs(step + 1);
            map[i][MAXN + j] = 0;
//            printf("at %d,%d ret = 1.0*dfs = %0.6f\n", i, j, ret);
        }
    }
    return ret;
}
int main(){
    int k, T;
    freopen("B-small-attempt1.in","r", stdin);
    freopen("B-small-attempt1.out","w",stdout);
    scanf("%d", &T);
    for (k = 1; k <= T; k++){
        scanf("%d%d%d", &n, &y, &x);
        memset(map, 0, sizeof(map));
        printf("Case #%d: %0.8f\n", k, dfs(1));
    }
    return 0;
}
