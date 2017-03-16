#include <cstdio>
#include <algorithm>

#ifdef DEBUG
#define D(x...) fprintf(stderr, x)
#else
#define D(x...)
#endif

#define FO(i,a,b) for(int i=(a);i<(b);i++)
#define fit(c,i) \
    for (typeof((c).begin()) i=(c).begin(); i != (c).end(); i++)

using namespace std;

int v[15];
int e, r, n, Z;

int best(int i, int m) {
    if (i == n) return 0;
    int res = 0;
    FO(j,0,m+1) {
        res = max(res, best(i+1,min(m-j+r,e)) + j*v[i]);
    }
    return res;
}

int main() {
#ifndef DEBUG
    // freopen("energy.in", "r", stdin);
    // freopen("energy.out", "w", stdout);
#endif

    scanf("%d", &Z);
    FO(T,0,Z) {
        scanf("%d %d %d", &e, &r, &n);
        FO(i,0,n) scanf("%d", &v[i]);
        printf("Case #%d: %d\n", T+1, best(0, e));
    }

    return 0;
}

