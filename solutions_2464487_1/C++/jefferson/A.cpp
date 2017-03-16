#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <cmath>
#include <algorithm>

using namespace std;

typedef long long int ll;
typedef unsigned long long int ull;

typedef vector <   int  > vi;
typedef vector <   vi   > vvi;
typedef vector < double > vd;
typedef vector <   vd   > vvd;
typedef vector < string > vs;

ll sum (ll a1, ll n) {
  return ((a1 + ((4LL * (n-1LL)) + a1)) * n) / 2LL;
}

ll bs (ll x, ll a1, ll i, ll f) {
  ll meio, v;
  while (i <= f) {
    meio = (i+f) / 2LL;
    v = sum(a1,meio);


    if (v == x)
      return meio;
    if (v < x)
      i = meio + 1LL;
    else
      f = meio - 1LL;
  }

  return f;
}

ll search (ll a1, ll sn) {
  return bs(sn, a1, 1LL, min(1000000000LL, sn/a1));
}

int main () {
  int T; ll r, t, ans;
  cin >> T;

  for (int x = 1; x <= T; x++) {
    cin >> r >> t; ans = 0LL;
    ans = search( ((r+1)*(r+1)) - (r*r), t);

    cout << "Case #" << x << ": " << ans << endl;
  }

  return 0;
}
