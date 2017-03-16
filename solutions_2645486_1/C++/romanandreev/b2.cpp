#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <ctime>
#include <cassert>

#define x first
#define y second
#define pb push_back
#define mp make_pair
#define forn(i, n) for(int i = 0 ; (i) < (n) ; ++i)
#define forit(it,v) for(typeof((v).begin()) it = v.begin() ; it != (v).end() ; ++it)
#define eprintf(...) fprintf(stderr, __VA_ARGS__),fflush(stderr)
#define sz(a) ((int)(a).size())
#define all(a) (a).begin(),a.end()

using namespace std;

typedef long long ll;
typedef double ld;
typedef vector<int> vi;
typedef pair<int, int> pi;

const int inf = (int)1e9;
const ld eps = 1e-9;


#define TASK "a"
ll E, R;
int n;
ll v[100000];
ll calc(int l, int r, ll SE, ll EE) {
    SE = min(SE, E);
    EE = min(EE, E);
    if (l > r) return 0;
    if (l == r) {
        assert(SE >= EE);
        return (ll)(SE - EE) * v[l];
    }
    assert(SE >= R);
    int mx = l;
    ll ME = 0;
    for (int i = l; i <= r; i++) {
        ll ff = min(SE + (ll)(i - l) * R, (ll)E);
        ll C = min(ff + (ll)(r - i) * R - EE, ff);
        assert(C >= 0);
        if (v[i] >= v[mx]) {
            mx = i;
            ME = C;
        }
    }
    return calc(l, mx - 1, SE, min(SE + (ll)(mx - l) * R, (ll)E) - R) + (ll)ME * v[mx] + calc(mx + 1, r, min(SE + (ll)(mx - l) * R, (ll)E) - ME + R, EE);

}
int main()
{
    #ifdef home
        assert(freopen(TASK".in", "r", stdin));
        assert(freopen(TASK".out", "w", stdout));
    #endif
    int T;
    scanf("%d", &T);
    for (int ti = 0; ti < T; ti++) {
//        cerr<<ti<<endl;
        scanf("%I64d %I64d %d", &E, &R, &n);
        R = min(R, E);
        for (int i = 0; i < n; i++) {
            scanf("%I64d", &v[i]);
        }
        ll ans = calc(0, n - 1, E, 0);
        printf("Case #%d: %I64d\n", ti + 1, ans);
    }
    #ifdef home
        eprintf("Time: %d ms\n", (int)(clock() * 1000. / CLOCKS_PER_SEC));
    #endif
    return 0;
}
 