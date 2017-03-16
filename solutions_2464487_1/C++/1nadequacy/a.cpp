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

typedef unsigned long long ll;
typedef long double ld;
typedef pair<int,int> pii;

#define pb push_back
#define mp make_pair
#define sz(a) int((a).size())
#define forn(i, n) for (int i=0; i<(n); ++i)

ll func(ll n, ll r) {
    return 2*n*r+n*(2*n-1);
}

ll solve(ll R, ll t) {
   ll l = 0, r = min((ll)sqrt(t)+1, t/R/2);
   while (r-l>1) {
       ll mid = (l+r)>>1;
       ll x = func(mid, R);
       if (x <= t) l = mid;
       else r = mid;
   }
   if (func( r, R) <= t) return r;
   return l;
}


int main()
{
    freopen("a.out", "w", stdout);

    int tc; scanf("%d", &tc);
    for (int tt=1; tt<=tc; ++tt) {
        ll r, t; cin >> r >> t;
        printf("Case #%d: ", tt);
        cout << solve(r, t) << endl;
    }

    return 0;
}
