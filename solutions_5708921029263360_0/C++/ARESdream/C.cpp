#include <bits/stdc++.h>
using namespace std;
const int maxn = 20;
typedef long long LL;
typedef pair<int, int> P;
int T, n, sj, sp, ss, K, S, tt;
int ans, ma;
int f[30][3];
int nb[4][4][4];
int main() {
    freopen("C-small-attempt2.in", "r", stdin);
    freopen("C-small-attempt2.out", "w", stdout);
    scanf("%d", &T);
    while (T--) {
        scanf("%d %d %d %d", &sj, &sp, &ss, &K);
        n = 0;
        for (int i = 1; i <= sj; ++i) {
            for (int j = 1; j <= sp; ++j) {
                for (int k = 1; k <= ss; ++k) {
                    f[n][0] = i;
                    f[n][1] = j;
                    f[n][2] = k;
                    ++n;
                }
            }
        }
        S = (1 << n);
        if (K >= ss) {
            printf("Case #%d: %d\n", ++tt, sj * sp * ss);
            for (int i = 0; i < n; ++i) if ((S - 1) & (1 << i)) {
                printf("%d %d %d\n", f[i][0], f[i][1], f[i][2]);
            }
            continue;
        }
        ans = 0;
        ma = 0;
        for (int i = S - 1; i > 0; --i) {
            int num = 0;
            for (int j = 0; j < n; ++j) if (i & (i << j)) ++num;
            if (num < ma) continue;
            num = 0;
            memset(nb, 0, sizeof nb);
            bool ok = true;
            for (int j = 0; j < n; ++j) if (i & (1 << j)) {
                ++num;
                int a = f[j][0], b = f[j][1], c = f[j][2];
                nb[1][a][b]++; if (nb[1][a][b] > K) {ok = false; break;}
                nb[2][b][c]++; if (nb[2][b][c] > K) {ok = false; break;}
                nb[3][a][c]++; if (nb[3][a][c] > K) {ok = false; break;}
            }
            if (ok && num > ma) {
                ma = num;
                ans = i;
            }
        }
        printf("Case #%d: %d\n", ++tt, ma);
        for (int i = 0; i < n; ++i) if (ans & (1 << i)) {
            printf("%d %d %d\n", f[i][0], f[i][1], f[i][2]);
        }
    }
    return 0;
}
