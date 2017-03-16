#include <cstdio>
#include <algorithm>

#define MAX_N 1000005
#define INF 1000000005
using namespace std;

long long T, E, R, N;
long long v[1000000];
long long cAns;
long long nE, bestE, cE;

void reset() {
    cAns = 0;
    cE = E;
    return;
}

int main() {
    freopen ("q2l.in", "r", stdin);
    freopen ("q2l.out", "w", stdout);
    scanf ("%lld", &T);
    for (int _t=1; _t<=T; _t++) {
        printf ("Case #%d: ", _t);
        scanf ("%lld %lld %lld", &E, &R, &N);
        if (R > E) R = E;
        for (int i = 0; i < N; i++) {
            scanf ("%lld", &v[i]);
        }
        reset();
        for (int i = 0; i < N; i++) {
            nE = E;
            bestE = INF;
            for (int p = i; p <= N; p++) {
                //Check energy required to be full after p
                if (p == N) {
                    //Means we've considered everything, use all our energy
                    bestE = 0;
                    break;
                }
                nE -= R;
                if (v[p] > v[i]) {
                    //Stop it
                    break;
                }
                bestE = nE;
                if (nE <= 0) break;
            }
            if (bestE < 0) bestE = 0;
            if (bestE < cE) {
                cAns += v[i] * (cE - bestE);
            } else {
                bestE = cE;
            }
            cE = min (E, bestE+R);
        }
        printf ("%lld\n", cAns);
    }
    return 0;
}
