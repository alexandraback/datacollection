#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>
#include <vector>
#include <deque>
#include <queue>
#include <set>
#include <map>
#include <algorithm>
#include <functional>
#include <iterator>
#include <utility>
#include <cmath>
#include <complex>

using namespace std;

typedef long long int LL;
typedef pair<int, int> PII;
typedef pair<LL, int> PLI;
typedef vector<int> VI;
typedef vector<LL> VL;
typedef vector<string> VS;
typedef vector<PII> VP;

int main() {
  int nc; cin >> nc;
  for (int cur = 1; cur <= nc; ++cur) {
    int e, r, n; cin >> e >> r >> n;
    r = min(r, e);

    VL val(n);
    for (int i = 0; i < n; ++i)
      cin >> val[i];

    set<PLI> cancel; LL ans = 0;
    for (int i = 0; i < n; ++i) {
      int avail = (i > 0) ? 0 : e;

      while ((avail < r) && !cancel.empty()) {
        PLI t = *cancel.rbegin(); cancel.erase(cancel.find(t));
        int inc = min(t.second, r-avail);
        avail += inc; t.second -= inc;
        if (t.second)
          cancel.insert(t);
        }

      while ((avail < e) && !cancel.empty() && (cancel.begin()->first <= val[i])) {
        PLI t = *cancel.begin(); cancel.erase(cancel.begin());
        int inc = min(t.second, e-avail);
        avail += inc; t.second -= inc; ans -= t.first*inc;
        if (t.second)
          cancel.insert(t);
        }

      ans += avail*val[i];
      cancel.insert(PLI(val[i], avail));
      }

    cout << "Case #" << cur << ": " << ans << '\n';
    }
  }

