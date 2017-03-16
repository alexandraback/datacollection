#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdio>
#include <string>
#include <vector>
#include <map>
#include <set>

using namespace std;

const int MAXN = 3000;

int N, X, Y;
double cnk[MAXN+1][MAXN+1];

int mabs(int a) { return (a >= 0) ? a : -a; }

void solve()
{
    int d = (mabs(X) + mabs(Y)) / 2;

    int Q = 1, r = 0;

    while (N > Q) {
        ++r; Q += 4*r + 1;
    }

    if (d < r) { printf("1.0"); return; }
    if (d > r) { printf("0.0"); return; }
    if (N == Q) { printf("1.0"); return; }
    if (Y == 2*r) { printf("0.0"); return; }

    Q -= 4*r + 1;
    N -= Q;
    r *= 2;

    double ans = 0.0;

    for (int j = 0; j <= N; ++j) {
        int tj = j;
        if (N-j > r) tj += (N-j)-r;
        if (tj > Y) ans += cnk[N][j];
    }

    printf("%.6lf", ans);
}

int main()
{
    cnk[0][0] = 1;

    for (int n = 1; n <= MAXN; ++n) {
        cnk[n][0] = 0.5 * cnk[n-1][0];

        for (int k = 1; k <= n; ++k)
            cnk[n][k] = 0.5 * (cnk[n-1][k-1] + cnk[n-1][k]);
    }

    int T; scanf("%d", &T);
    for (int t = 0; t < T; ++t) {
        scanf("%d%d%d", &N, &X, &Y);

        printf("Case #%d: ", t+1);
        solve();
        printf("\n");
    }

    return 0;
}
