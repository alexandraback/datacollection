#include "iostream"
#include "cstring"
#include "cstdio"
#include "algorithm"
using namespace std;
#define PB push_back
#define MP make_pair
const int N = 3000;
const int M = 400000;
int vis[3][20][20];
int ans[N];
int main(void)
{
    int T, a, b, c, num;
    scanf("%d", &T);
    int g = 0, n;
    while(T--){
        printf("Case #%d: ", ++g);
        scanf("%d %d %d %d",&a, &b, &c, &num);
        memset(vis, 0, sizeof(vis));
        int sum = 0;
        int sz = 0;
        for(int i = 1; i <= a; ++ i){
            for (int j = 1; j <= b; ++ j){
                for (int k = 1; k <= c; ++ k){
                    if (vis[0][i][j] < num && vis[1][j][k] < num && vis[2][i][k] < num){
                        sum ++;
                        ans[sz++] = i;ans[sz++] = j;ans[sz++] = k;
                        vis[0][i][j] ++;
                        vis[1][j][k] ++;
                        vis[2][i][k] ++;
                    }
                }
            }
        }
        printf("%d\n", sum);
        for(int i = 0; i < sz; i += 3){
            printf("%d %d %d\n", ans[i], ans[i + 1], ans[i + 2]);
        }
    }
    return 0;
}