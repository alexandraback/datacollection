#include <iostream>
#include <cstdio>
#include <memory.h>
#include <string.h>
#include <vector>
#include <string>
#include <utility>
#include <algorithm>
#include <cmath>
#include <map>
#include <set>
#include <queue>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;

#define pb push_back
#define mp make_pair
#define sz(a) int((a).size())
#define forn(i, n) for (int i=0; i<(n); ++i)

int E, N, R;
int v[32];
int f[32][32];

int solve(int e, int i) {
    if (i >= N) return 0;
    int& res = f[e][i];
    if (res != -1) return res;
    res = 0;
    for (int x=0; x<=e; ++x) {
        res = max(res, solve(min(e-x+R, E), i+1)+x*v[i]);
    }
    return res;
}


int main()
{
    freopen("a.out", "w", stdout);

    int tc; scanf("%d", &tc);
    for (int tt=1; tt<=tc; ++tt) {
        scanf("%d %d %d", &E, &R, &N);
        forn (i, N) scanf("%d", v+i);
        memset(f, 0xff, sizeof(f));
        int res = solve(E, 0);
        printf("Case #%d: %d\n", tt, res);
    }

    return 0;
}
