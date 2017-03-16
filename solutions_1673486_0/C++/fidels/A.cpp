#include <iostream>
#include <cstdio>
using namespace std;

#define MAXN 131072

typedef double tint;

tint p[MAXN];

int main() {
    int N, M, i, t, T;
    tint prob, tmp, RES;

    cin >> T;
    for (t=1; t<=T; t++) {
        cin >> N;
        cin >> M;
        for (i=0; i<N; i++) cin >> p[i];
    
        prob = 1.0; RES = 2.0+M;
        for (i=0; i<=N; i++) {
            tmp = N-i + M-i + 1.0;;
            RES = min(RES, tmp*prob + (tmp+M+1.0)*(1.0-prob));
            if (i < N) prob *= p[i];
        }
        printf("Case #%d: %.6lf\n", t, RES);
    }

    return 0;
}
