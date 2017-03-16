#include <cassert>
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <ctime>
#include <cmath>
#include <string>
#include <iomanip>
#include <vector>
#include <set>
#include <map>
#include <cassert>
#include <queue>

using namespace std;

#define FOR(a, b) for (int a = 0; a < (b); ++a)
#define clr(a) memset(a, 0, sizeof(a))
#define pb(i) push_back(i)
#define forab(i, a, b) for(int i = int(a); i < int(b); ++i)
#define forba(i, b, a) for(int i = int(b) - 1; i >= int(a); --i)
#define forn(i, n) forab(i, 0, n)

typedef long long ll;
typedef long double ldb;

const int INF = 1e9;
const ldb EPS = 1e-8;
const int MAXN = 1e5;

struct man {
    int d;
    ll m;
    man() : d(0), m (0) {}
    man(int d, int m) : d(d), m (m) {}
    bool operator < (const man & o) const {
        return m < o.m;
    }
};

int main() {
#ifdef LOCAL
    freopen("c.in", "r", stdin);
    freopen("c.out", "w", stdout);
    //freopen("", "w", stderr);
#endif
     
    int T;
    scanf("%d", &T);
    for (int t = 1; t <= T; ++t) {
        int n;
        scanf("%d", &n);
        vector<man> v;
        FOR(i, n) {
            int d, h, m;
            scanf("%d%d%d", &d, &h, &m);
            FOR(i, h) {
                v.push_back(man(d, m + i));
            }
        }
        int m = v.size();
        sort(v.begin(), v.end());
        ll ans = m - 1;
        FOR(i, m) {
            ll cur = 0;
            FOR(j, i) {
            //    if (v[j].m == v[i].m)
            //        continue;
                cur += max((ll)0, (v[i].m * (360 - v[i].d) + v[j].m * v[j].d) / (360 * v[j].m) - 1);
            }
            for (int j = 0; j < m; ++j) {
            //    if (v[j].m == v[i].m)
            //        continue;
                if (v[i].m * (360 - v[i].d) < v[j].m * (360 - v[j].d))
                    cur++;
            }
            ans = min(ans, cur);
        }


        if (m == 2) {
            ll ans1 = 0;
            ll t1 = ((ll)(2 * 360 - v[0].d)) * v[0].m;
            ll t2 = ((ll)(360 - v[1].d)) * v[1].m;
            if (t1 <= t2) {
                ans1 = 1;
            }
            assert(ans == ans1);
        }
        printf("Case #%d: %lld\n", t, ans);
    }
    return 0;
}

