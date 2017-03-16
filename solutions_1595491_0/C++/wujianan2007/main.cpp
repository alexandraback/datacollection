#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int dp[105][105];
int tot[105];
int n, s, p;

int check(int x, bool f) {
    if (!f) {
        if (x % 3 == 0) return x / 3;
        if (x % 3 == 1) return x / 3 + 1;
        if (x % 3 == 2) return x / 3 + 1;
    }
    if (x % 3 == 0) return x / 3 + 1;
    if (x % 3 == 1) return x / 3 + 1;
    if (x % 3 == 2) return x / 3 + 2;
}

int max(int x, int y) {
    return x > y ? x : y;
}

int main() {
    int t;
    freopen("B-small-attempt0.in", "r", stdin);
    freopen("B-small-attempt0.out", "w", stdout);
    scanf("%d", &t);
    for (int tt = 1; tt <= t; tt++) {
        scanf("%d%d%d", &n, &s, &p);
        for (int i = 1; i <= n; i++) scanf("%d", &tot[i]);
        sort(tot + 1, tot + n + 1);
        memset(dp, -1, sizeof (dp));
        int pp;
        dp[0][0] = 0;
        for (pp = 1; tot[pp] < 2 && pp <= n; pp++) dp[pp][0] = dp[pp - 1][0]+(check(tot[pp], 0) >= p);
        for (int i = pp; i <= n; i++) {
            dp[i][0] = dp[i - 1][0] + (check(tot[i], 0) >= p);
            for (int j = 1; j <= s; j++) {
                if (dp[i - 1][j - 1] != -1) dp[i][j] = max(dp[i][j], dp[i - 1][j - 1]+(check(tot[i], 1) >= p));
                if (dp[i - 1][j] != -1) dp[i][j] = max(dp[i][j], dp[i - 1][j]+(check(tot[i], 0) >= p));
            }
        }
        printf("Case #%d: %d\n", tt, dp[n][s]);
    }
    return 0;
}