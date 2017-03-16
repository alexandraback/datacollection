#include <algorithm>
#include <iomanip>
#include <iostream>
#include <cmath>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <vector>

#define FR first
#define SC second

#define debug(x) cerr << #x << " = " << x << endl

using namespace std;

typedef long long ll;

template <class Ta, class Tb> inline Tb cast(Ta a) {
  stringstream ss;
  ss << a;
  Tb b;
  ss >> b;
  return b;
}

const ll LINF = 1000000000000000000LL;
const int INF = 1000000000;

ll paint(ll r, ll n) {
  return n*(2*r+1)+2*(n-1)*n;
}

int main() {
  ios_base::sync_with_stdio(false);
  int T;
  cin >> T;
  for (int ca = 1; T--; ++ca) {
    ll r, t;
    cin >> r >> t;
    ll lo = 1, hi = 2;
    for (; paint(r, hi) <= t;) hi *= 2;
    for (; hi-lo > 1;) {
      ll md = lo+(hi-lo)/2;
      if (paint(r, md) <= t) lo = md;
      else hi = md;
    }
    cout << "Case #" << ca << ": " << lo << endl;
  }
}
