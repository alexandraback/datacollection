#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int dp[15][15];
int e, r, n, v[15];

int main() {
    freopen("in", "r", stdin);
    freopen("out", "w", stdout);
    int T;
    scanf("%d", &T);
    for (int cas = 1; cas <= T; cas++) {
        scanf("%d%d%d", &e, &r, &n);
        for (int i = 1; i <= n; i++) scanf("%d", &v[i]);
        memset(dp, 0, sizeof (dp));
        for (int i = 0; i < n; i++)
            for (int j = 0; j <= e; j++) {
                for (int k = 0; k <= j; k++) {
                    int p = j - k + r;
                    if (p > e) p = e;
                    dp[i + 1][p] = max(dp[i + 1][p], dp[i][j] + k * v[i + 1]);
                }
            }
        int ans = 0;
        for (int i = 0; i <= e; i++) ans = max(ans, dp[n][i]);
        printf("Case #%d: %d\n", cas, ans);
    }
    return 0;
}

