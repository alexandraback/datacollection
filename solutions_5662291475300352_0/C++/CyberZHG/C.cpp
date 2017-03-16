#include <bits/stdc++.h>
using namespace std;
const int MAXN = 20;

int N, D[MAXN], H[MAXN], M[MAXN];

int main() {
    freopen("C-small-1-attempt0.in", "r", stdin);
    freopen("C-small-1-attempt0.out", "w", stdout);
    int T;
    scanf("%d", &T);
    for (int t = 1; t <= T; ++t) {
        scanf("%d", &N);
        for (int i = 0; i < N; ++i) {
            scanf("%d%d%d", &D[i], &H[i], &M[i]);
        }
        int ans = 1;
        if (N == 1 && H[0] == 2) {
            N = 2;
            D[1] = D[0];
            M[1] = M[0] + 1;
        }
        double x1 = (360.0 - D[0]) / 360.0 * M[0];
        double x2 = (360.0 - D[1]) / 360.0 * M[1];
        double x3 = (720.0 - D[0]) / 360.0 * M[0];
        double x4 = (720.0 - D[1]) / 360.0 * M[1];
        if (x2 < x1 && x4 > x1) {
            ans = 0;
        }
        if (x1 < x2 && x3 > x2) {
            ans = 0;
        }
        printf("Case #%d: %d\n", t, ans);
    }
    return 0;
}
