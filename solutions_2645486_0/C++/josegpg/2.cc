#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <iostream>
#include <queue>
#include <stack>
#include <map>

using namespace std;
int test, E, R, N;
int m[6][11];
int v[10000000];
int dp(int e, int a) {
    if (a >= N) return 0;
    if (m[e][a] != -1) return m[e][a];
    int resAux, maxAux = 0;
    e = min(E, e);
    for (int i = 0; i <=e; i++) {
        resAux = i*v[a] + dp(e-i+R, a+1);
        maxAux= max(maxAux, resAux);
    }
    m[e][a] = maxAux;
    return maxAux;
}

main () {
    scanf("%d", &test);
    for (int i = 0; i < test; i++) {
        scanf("%d %d %d", &E, &R, &N);
        memset(m, -1, sizeof(m));
        for (int j = 0; j < N; j++) {
            scanf("%d", &v[j]);
        }
        printf("Case #%d: %d\n", i+1, dp(E, 0));
    }
}
