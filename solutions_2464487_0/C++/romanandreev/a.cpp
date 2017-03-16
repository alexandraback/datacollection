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
ld calc(ll x, ll R) {
    return (ld)x * (2 * R + 1) + (ld)x * (x - 1) * 2;
}
int main()
{
    #ifdef home
        assert(freopen(TASK".in", "r", stdin));
        assert(freopen(TASK".out", "w", stdout));
    #endif
    int T;
    cin>>T;
    for (int ti = 0; ti < T; ti++) {
        ll R, T;
        cin>>R>>T;
        ll l, r, m;
        l = 0;
        r = T;
        while (l < r) {
            m = (l + r + 1) / 2;
            if (calc(m, R) > T) {
                r = m - 1;
            } else {
                l = m;
            }
        }
        printf("Case #%d: %I64d\n", ti + 1, l);
    }
    #ifdef home
        eprintf("Time: %d ms\n", (int)(clock() * 1000. / CLOCKS_PER_SEC));
    #endif
    return 0;
}
 