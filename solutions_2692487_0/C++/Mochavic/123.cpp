#include <stdio.h>
#include <algorithm>
using namespace std;
int dp[110][110];
int c[110];
int main(){
    int n, i, T, ri = 1, j, x, ans;
    freopen("A-small-attempt0(1).in", "r", stdin);
    freopen("out.txt", "w", stdout);
    scanf("%d", &T);
    while (T--){
        scanf("%d%d", &x, &n);
        for (i = 0; i < n; i++) scanf("%d", &c[i]);
        sort(c, c + n);
        for (i = 0; i <= n; i++){
            for (j = 0; j <= n; j++){
                dp[i][j] = -1;
            }
        }
        dp[0][0] = x;
        ans = n;
        for (i = 0; i <= n; i++){
            for (j = 0; j <= n; j++){
                if (dp[i][j] < 0) continue;
                ans = min(ans, j + n - i);
                if (i == n) continue;
                if (dp[i][j] > c[i]){
                    dp[i + 1][j] = max(dp[i + 1][j], dp[i][j] + c[i]);
                }
                if (dp[i][j] < 1000001) dp[i][j + 1] = max(dp[i][j + 1], dp[i][j] + dp[i][j] - 1);
            }
        }
        printf("Case #%d: %d\n", ri++, ans);
    }
    return 0;
}
