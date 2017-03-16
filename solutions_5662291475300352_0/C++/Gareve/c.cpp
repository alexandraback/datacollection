#include <iostream>
#include <cstdio>
#include <string>
#include <cmath>
#include <vector>
#include <algorithm>
#include <cstring>
#include <map>
#include <cassert>

using namespace std;

int N;
double S[2], T[2], V[2];
double DEST = 360.0;
int solve() {
    scanf("%d", &N);
    int idx=0;
    int s,q,t;
    for (int i = 1; i<=N; i++) {
        scanf("%d %d %d", &s, &q, &t);
        for(int j=1;j<=q;j++) {
            S[idx] = s;
            T[idx] = t + j - 1;
            V[idx] = T[idx] / 360;
            idx++;
        }
    }
    assert(idx <= 2);

    if (idx == 1)return 0;

    if (T[0] == T[1]) return 0;
    double delta = 1e-7;

    int a=0;
    int b=1;

    double xa = S[a] + V[a] * delta;
    double xb = S[b] + V[b] * delta;

    if (xa > xb)swap(xa, xb);

    double lfta = (DEST - xa);
    double ta = lfta / V[a];

    double lftb = (DEST - xb);
    double tb = lftb / V[b];

    assert(ta != tb);
    if (ta < tb) {
        if (ta + T[a] < tb) return 1;
        if (ta + T[a] == tb) return 2;
    }
    if (ta > tb) {
        if (tb + T[b] < ta) return 1;
        if (tb + T[b] == ta) return 2;
    }

    return 0;
}
int main() {
    int NC;scanf("%d", &NC);
    for (int i=1; i<= NC; i++) {
        int ans = solve();
        printf("Case #%d: %d\n", i, ans);
    }
}