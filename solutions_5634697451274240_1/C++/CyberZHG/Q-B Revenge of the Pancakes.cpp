#include <bits/stdc++.h>
using namespace std;
const int MAXN = 100 + 5;
const int INF = 0x3f3f3f3f;

char s[MAXN];
int dp[MAXN][2];

int main() {
    int T;
    freopen("B-large.in", "r", stdin);
    freopen("B-large.out", "w", stdout);
    scanf("%d", &T);
    for (int t = 1; t <= T; ++t) {
        scanf("%s", s + 1);
        int n = strlen(s + 1);
        for (int i = 1; i <= n; ++i) {
            if (s[i] == '+') {
                dp[i][0] = min(dp[i - 1][0] + 2, dp[i - 1][1] + 1);
                dp[i][1] = min(dp[i - 1][0] + 1, dp[i - 1][1]);
            } else {
                dp[i][0] = min(dp[i - 1][0], dp[i - 1][1] + 1);
                dp[i][1] = min(dp[i - 1][0] + 1, dp[i - 1][1] + 2);
            }
        }
        printf("Case #%d: %d\n", t, dp[n][1]);
    }
    return 0;
}
