#include <cstdio>

#define MIN(a,b) ((a)<(b)?(a):(b))
#define MAXN 1111111
#define INF 1111111111

int dp[MAXN];

int flip(int x) {
    int ret = 0;
    while (x) {
        ret *= 10;
        ret += (x - x / 10 * 10);
        x /= 10;
    }
    return ret;
}

int main() {
    int T, i, n, f;
    dp[1] = 1;
    for (i = 2; i < MAXN; i++) {
        f = flip(i);
        if (i == i / 10 * 10 || f >= i) dp[i] = dp[i - 1] + 1;
        else dp[i] = MIN(dp[f], dp[i - 1]) + 1;
    }
    scanf("%d", &T);
    for (int t = 1; t <= T; t++) {
        scanf("%d", &n);
        printf("Case #%d: %d\n", t, dp[n]);
    }
    return 0;
}
