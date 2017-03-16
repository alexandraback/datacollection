/*#include <iostream>
#include <stdio.h>
#include <string.h>
#define ll long long
using namespace std;

int n, m;
ll a[105], b[105], aa[105], bb[105], res;

void f(int x, ll t1, int y, ll t2, ll sum) {
    if (x > n || y > m) {
        res = max(res, sum);
        return;
    }
    if (aa[x] == bb[y]) {
        if (t1 < t2) f(x + 1, a[x + 1], y, t2 - t1, sum + t1);
        else f(x, t1 - t2, y + 1, b[y + 1], sum + t2);
        return;
    }
    f(x + 1, a[x + 1], y, t2, sum);
    f(x, t1, y + 1, b[y + 1], sum);
}

int main() {
    freopen("C-small-attempt0.in", "r", stdin);
    freopen("C-small-attempt0.out", "w", stdout);
    int icase, tt = 0, i;
    scanf("%d", &icase);
    while (icase--) {
        scanf("%d%d", &n, &m);
        for (i = 1; i <= n; i++) scanf("%lld%lld", &a[i], &aa[i]);
        for (i = 1; i <= m; i++) scanf("%lld%lld", &b[i], &bb[i]);
        res = 0;
        f(1, a[1], 1, b[1], 0);
        printf("Case #%d: %lld\n", ++tt, res);

    }
    return 0;
}*/
#include <stdio.h>
#include <string.h>
#include <iostream>
#define ll long long
using namespace std;

int n, m;
ll a[105], b[105], aa[105], bb[105], res, s1[105][105], s2[105][105];
ll dp[105][105];

int main() {
    freopen("C-large.in", "r", stdin);
    freopen("C-large.out", "w", stdout);
    int icase, tt = 0, i, j, x, y;
    scanf("%d", &icase);
    while (icase--) {
        memset(s1, 0, sizeof(s1));
        memset(s2, 0, sizeof(s2));
        scanf("%d%d", &n, &m);
        for (i = 0; i < n; i++) scanf("%lld%lld", &a[i], &aa[i]);
        for (i = 0; i < m; i++) scanf("%lld%lld", &b[i], &bb[i]);
        for (i = 0; i < n; i++) s1[aa[i]][i + 1] = a[i];
        for (i = 0; i < m; i++) s2[bb[i]][i + 1] = b[i];
        for (i = 0; i < n; i++)
            for (j = 0; j <= 100; j++) s1[j][i + 1] += s1[j][i];
        for (i = 0; i < m; i++)
            for (j = 0; j <= 100; j++) s2[j][i + 1] += s2[j][i];
        memset(dp, 0, sizeof(dp));
        for (i = 1; i <= n; i++)
            for (j = 1; j <= m; j++) {
                if (aa[i - 1] != bb[j - 1]) dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                else {
                    for (x = 0; x < i; x++) for (y = 0;y < j; y++)
                        dp[i][j] = max(dp[i][j], dp[x][y] + min(s1[aa[i - 1]][i] - s1[aa[i - 1]][x], s2[bb[j - 1]][j] - s2[bb[j - 1]][y]));
                }
            }
        ll res = 0;
        for (i = 0; i <= n; i++)
            for (j = 0; j <= m; j++)
                res = max(res, dp[i][j]);
        printf("Case #%d: %lld\n", ++tt, res);
    }
    return 0;
}
