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

llong vals[16];
llong r, n, max_e;
void recurse(int idx,  int e, llong val) {
  if (idx == n) {
    best = max(best, val);
    return;
  }
  for (int i = 0; i <= e; ++i) {
    recurse(idx+1, min(e - i + r, max_e), val + vals[idx]*i);
  }
}

int main() {
  int n_cases;
  scanf("%d", &n_cases);
  for (int ctr = 0; ctr < n_cases; ++ctr) {
    scanf("%lld %lld %lld", &max_e, &r, &n);
    for (int i = 0; i < n; ++i) {
      scanf("%lld", &vals[i]);
    }
    best = 0;
    recurse(0, max_e, 0);
    printf("Case #%d: %lld\n", ctr+1, best);
  }
  return 0;
}
