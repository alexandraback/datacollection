#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <sstream>
#include <set>
#include <map>
#include <iomanip>

#define fr(i,n) for(i=0;i<(int)(n);i++)
#define fit(a,b) for(typeof(b.begin()) a = b.begin(); a != b.end(); a++)
#define pb push_back
#define MP make_pair
#define F first
#define S second
#define SZ(u) ((int)u.size())
#define WT(x) cout << #x << ": " << x << endl

using namespace std;

typedef long long ll;
typedef pair<int,int> p2;
typedef vector<int> vi;
typedef long double ld;

int main() {
  int tc, cn = 0;
  cin >> tc;
  while (cn++ < tc) {
    ll r, t;
    cin >> r >> t;
    ll res = 0, st = 1, en = 1000000000LL;
    while (st <= en) {
      ll mid = (st + en) / 2;
      if (mid * (2*(double)r + 1) + 2 * mid * (mid - 1) <= t &&
        mid * (2*r + 1) + 2*mid*(mid - 1) <= t) {
        res = mid;
        st = mid + 1;
      } else en = mid - 1;
    }
    cout << "Case #" << cn << ": " << res << endl;
  }
  return 0;
}
