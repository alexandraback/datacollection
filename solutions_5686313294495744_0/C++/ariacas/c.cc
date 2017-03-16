#include <cstdio>
#include <cstdlib>
#include <cassert>
#include <iostream>
#include <set>
#include <vector>
#include <cstring>
#include <string>
#include <algorithm>
#include <numeric>
#include <cmath>
#include <map>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<vi> vvi;
typedef vector<vl> vvl;
typedef vector<double> vd;
typedef pair<int, int> pii;
typedef pair<double, double> pdd;
typedef vector<pii> vii;
typedef vector<string> vs;

int main() {
  int T;
  cin >> T;
  for (int test = 1; test <= T; ++test) {
    printf("Case #%d: ", test);
    int n;
    cin >> n;
    vs a(n), b(n);
    for (int i = 0; i < n; ++i) cin >> a[i] >> b[i];
    int res = 0;
    for (int mask = 0; mask < (1 << n); ++mask) {
      set<string> x, y;
      int cnt = 0;
      for (int i = 0; i < n; ++i) if (mask & (1 << i)) {
        x.insert(a[i]);
        y.insert(b[i]);
        ++cnt;
      }
      bool fail = 0;
      for (int i = 0; i < n; ++i) if (!(mask & (1 << i))) {
        if (!x.count(a[i]) || !y.count(b[i])) fail = 1;
      }
      if (!fail) res = max(res, n - cnt);
    }
    cout << res << endl;
  }
  return 0;
}
