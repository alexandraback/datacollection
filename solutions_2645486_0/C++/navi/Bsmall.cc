#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int T, E, R, n;
int a[10];
int dp[11][6];

int main() {
    scanf("%d", &T);
    for (int caseNum = 1; caseNum <= T; ++caseNum) {
        scanf("%d%d%d", &E, &R, &n);
        for (int i = 0; i < n; ++i) {
            scanf("%d", &a[i]);
        }
        memset(dp, -1, sizeof(dp));
        dp[0][E] = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j <= E; ++j) {
                if (dp[i][j] != -1) {
                    for (int k = 0; k <= j; ++k) {
                        dp[i + 1][min(E, j - k + R)] = max(dp[i + 1][min(E, j - k + R)], dp[i][j] + a[i] * k);
                    }
                }
            }
        }
        int res = 0;
        for (int i = 0; i <= E; ++i) {
            res = max(res, dp[n][i]);
        }
        printf("Case #%d: %d\n", caseNum, res);
    }
    return 0;
}
