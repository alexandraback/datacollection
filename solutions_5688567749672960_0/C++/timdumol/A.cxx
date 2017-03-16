#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <cassert>
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

ullong reverse(ullong x) {
  if (!x) return x;
  ullong z = 0;
  while (x) {
    ullong m = x % 10;
    z = z*10 + m;
    x /= 10;
  }
  return z;
}

int main() {
  int n_cases;
  scanf("%d", &n_cases);

  ullong best[1000001];
  best[1] = 1;
  for (int i = 1; i <= 1000000; ++i) {
    auto r = reverse(i);
    if (i % 10 != 0 && r < i) {
      best[i] = min(best[i-1] + 1, best[r] + 1);
    } else {
      best[i] = best[i-1] + 1;
    }
  }
  for (int ctr = 0; ctr < n_cases; ++ctr) {
    ullong n;
    scanf("%llu", &n);
    
    printf("Case #%d: %llu\n", ctr+1, best[n]);
  }
  return 0;
}
