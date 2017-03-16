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
int g[6][6];
int a[6], b[6];
int main(void)
{
    int T;
    scanf("%d", &T);
    int gg = 0, n, m;
    while(T--){
        printf("Case #%d: ", ++gg);
        scanf("%d %d",&n, &m);
        bool flag = true;
        int num = n * (n - 1) / 2;
        for (int i = 0; i < (1 << num); ++ i){
            int cnt = 0;
            for (int j = 0; j < n; ++ j){
                for (int k = j + 1; k < n; ++ k) {
                    if (i & (1 << cnt)) {
                        g[j][k] = 1;
                    }else{
                        g[j][k] = 0;
                    }
                    cnt++;
                }
            }
            for (int k = 0; k < n; ++ k){
                a[k] = g[0][k];
            }
            memset(b, 0, sizeof(b));
            for(int j = 1; j < n - 1; ++ j){
                for(int k = 0; k < n; ++ k){
                    b[k] += a[j] * g[j][k];
                }
            }
            for(int j = 0; j < n; ++ j){
                a[j] += b[j];
            }
            if (a[n - 1] == m){
                printf("POSSIBLE\n");
                for (int j = 0; j < n; ++ j){
                    for(int k = 0; k < n; ++k){
                        printf("%d",g[j][k]);
                    }
                    printf("\n");
                }
                flag = false;
                break;
            }
        }    
        if (flag){
            puts("IMPOSSIBLE");
        }
            
    }
    return 0;
}