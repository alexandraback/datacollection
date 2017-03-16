#include <cstdio>
#include <cstring>
#include <cmath>
#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <list>
#include <queue>
using namespace std;
typedef long long ll;

ll r0, t;
bool ok(ll x) {
  return 2 * x * r0 + x * (2 * x - 1) <= t;
}
int main()
{
#ifdef _ZZZ_
  freopen("in.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
#endif
  int T;
  cin >> T;
  for(int tt = 1; tt <= T; ++ tt) {

    cin >> r0 >> t;
    ll ans = 0;
    if (2 * r0 + 1 > t) {
      ans = 0;
    } else {
      ll l = 1, r = min((ll)sqrt(t) + 1LL, ll(t * 1.0 / 2 / r0) + 1LL);
      //cout << l << " " << r << endl;
      while(l + 1 < r) {
        //cout <<
        ll mid = (l + r) >> 1;
        if (ok(mid)) l = mid;
        else r = mid;
      }
      ans = l;
    }
    //cout << ok(50) << endl;
    cout << "Case #" << tt << ": " << ans << endl;
  }


}















