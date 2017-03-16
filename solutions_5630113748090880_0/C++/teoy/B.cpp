#include "iostream"
#include "cstring"
#include "cstdio"
using namespace std;
const int N = 60;
int vis[2510];
int a[N][N];
int main(void)
{
    int T;
    scanf("%d", &T);
    int g = 0, n;
    while(T--){
        printf("Case #%d: ", ++g);
        scanf("%d", &n);
        memset(vis, 0, sizeof(vis));
        for (int i = 1; i < 2 * n; ++ i){
            for(int j = 1; j <= n; ++j){
                scanf("%d", &a[i][j]);
                vis[a[i][j]]++;
            }
        }
        int aa[N], num = 0;
        for(int i = 1; i <= 2500; ++ i){
            if (vis[i] % 2 == 1){
                aa[num++] = i;
            }
        }
        for(int i = 0; i < n; ++ i){
            printf("%d%c", aa[i], i == n - 1 ?'\n':' ');
        }
    }
    return 0;
}