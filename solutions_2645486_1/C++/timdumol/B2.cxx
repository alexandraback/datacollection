#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <complex>
#include <numeric>
#include <ext/numeric>
#include <iostream>
#include <algorithm>
#include <set>
#include <string>
#include <map>
#include <functional>
#include <utility>
#include <vector>
#include <list>
#include <queue>
#include <bitset>
#include <cassert>

using namespace std;
using namespace __gnu_cxx;

typedef unsigned long long ullong;
typedef long long llong;
typedef list<int> EdgeList;
typedef vector<EdgeList> AdjList;
typedef pair<int, int> ii;
typedef vector<ii> vii;

#define FOR_EDGE(adj,v,it) for (EdgeList::iterator it = adj[v].begin(); \
    it != adj[v].end(); ++it)

llong best;

llong vals[10000002];
llong r, n, max_e;

int main() {
  int n_cases;
  scanf("%d", &n_cases);
  for (int ctr = 0; ctr < n_cases; ++ctr) {
    scanf("%lld %lld %lld", &max_e, &r, &n);
    for (int i = 0; i < n; ++i) {
      scanf("%lld", &vals[i]);
    }
    best = 0;
    llong e = max_e;
    for (int i = 0; i < n; ++i) {
      assert(e >= 0);
      assert(e <= max_e);
      // free uses!
      llong delta = max(r - (max_e - e), 0LL);
      llong cv = vals[i];
      llong to_use = min(delta, e);
      bool found_better = false;
      // look ahead, see if you've got something better
      for (int j = i+1; j < n; ++j) {
        llong v = vals[j];
        if (v > cv) {
          // only time worth considering skipping
          llong will_recover = (j-i-1)*r;
          llong free = max(will_recover - max(max_e - e - r, 0LL), 0LL);
          // we can use will_recover, free! otherwise we're paying opportunity
          to_use = min(e, delta + free);
          found_better = true;
          break;
        }
      }
      if (!found_better) {
        // then let's just use it all now.
        to_use = e;
      }
      assert(to_use >= 0);
      assert(e >= 0);
      assert(e <= max_e);
      best += to_use * vals[i];
      e -= to_use;
      assert(e >= 0);
      assert(e <= max_e);
      e = min(e + r, max_e);
      assert(e >= 0);
      assert(e <= max_e);
    }
    printf("Case #%d: %lld\n", ctr+1, best);
  }
  return 0;
}
