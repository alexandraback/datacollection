#include <cstdio>
#include <algorithm>

using namespace std;

int T;
int E, R, N, v[100];
int bWay[100][100];
int ans;

void reset() {
    for (int i = 0; i < 100; i++) {
        for (int p = 0; p < 100; p++) {
            bWay[i][p] = 0;
        }
    }
    ans = 0;
    return;
}

int main() {
    freopen ("q2.in", "r", stdin);
    freopen ("q2.out", "w", stdout);
    scanf ("%d", &T);
    for (int _t=1; _t<=T; _t++) {
        printf ("Case #%d: ", _t);
        reset();
        scanf ("%d %d %d", &E, &R, &N);
        if (R > E) R = E;
        for (int i = 0; i < N; i++) {
            scanf ("%d", &v[i]);
        }
        for (int i = 0; i < N; i++) {
            for (int p = E; p >= 0; p--) {
                for (int t = 0; t <= p; t++) {
                    //DP: on ith item, w/ p energy use t
                    bWay[i+1][p-t+R] = max (bWay[i+1][p-t+R], bWay[i][p]+t*v[i]);
                }
            }
        }
        for (int i = 0; i <= E; i++) {
            ans = max (ans, bWay[N][i]);
        }
        printf ("%d\n", ans);
    }
    return 0;
}
