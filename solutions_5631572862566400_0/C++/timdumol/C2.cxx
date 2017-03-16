#include <cstdio>
#include <cassert>
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
#define FOR(v, it) for (auto it = v.begin(); it != v.end(); ++it)

int main() {
  int n_cases;
  scanf("%d", &n_cases);
  for (int ctr = 0; ctr < n_cases; ++ctr) {
    int n;
    scanf("%d", &n);
    int arr[1024];
    for (int i = 0; i < n; ++i) {
      scanf("%d", &arr[i]);
      --arr[i];
    }

    int best = 0;
    for (ullong mask = 1; mask < (1ULL << n); ++mask) {
      int perm[1024];
      int n_ok = 0;
      for (int i = 0; i < n; ++i) {
        if ((mask >> i) & 1) {
          perm[n_ok] = i;
          n_ok += 1;
        }
      }
      if (n_ok <= 1) continue;
      do {
        bool ok = true;
        #ifdef DEBUG
        for (int i = 0; i < n_ok; ++i) {
          printf("%d ", perm[i]);
        }
        puts("");
#endif
        
        for (int i = 0; i < n_ok; ++i) {
          int prev = ((i-1) + n_ok) % n_ok;
          int next = ((i+1) + n_ok) % n_ok;
          if (! (arr[perm[i]] == perm[prev] || arr[perm[i]] == perm[next]) ){
            
            ok = false;
            break;
          }
        }
        if (ok) {
          best = max(best, n_ok);
          break;
        }
      } while (next_permutation(perm, perm+n_ok));
    }
    printf("Case #%d: %d\n", ctr+1, best);
  }
  return 0;
}
