#include <bits/stdc++.h>
using namespace std;
const int maxn = 55;
typedef long long LL;
int ans[maxn][maxn];
int T, n, tt;
LL m, p[55];
int main() {
    freopen("B-large.in", "r", stdin);
    freopen("B-large.out", "w", stdout);
    p[1] = 1;
    for (int i = 2; i <= 50; ++i) {
        p[i] = (1LL << (i - 2));
    }
    scanf("%d", &T);
    while (T--) {
        scanf("%d%I64d", &n, &m);
        memset(ans, 0, sizeof ans);
        printf("Case #%d: ", ++tt);
        if (m > (1LL << (n - 2))) {
            printf("IMPOSSIBLE\n");
            continue;
        }
        printf("POSSIBLE\n");
        for (int i = 2; i < n; ++i) {
            for (int j = 1; j < i; ++j)
                ans[j][i] = 1;
        }
        for (int i = n - 1; i >= 1; --i) {
            if (m >= p[i]) {
                ans[i][n] = 1;
                m -= p[i];
            }
        }
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= n; ++j)
                printf("%d", ans[i][j]);
            printf("\n");
        }
    }
    return 0;
}
