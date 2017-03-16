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
llong comb(int n, int k) {
  if (n-k < k) k = n-k;
  if (k < 0 || k > n) return 0;
  llong x = 1;
  for (int i = 1; i <= k; ++i) {
    x *= n - k + i;
    x /= i;
  }
  return x;
}

int c, d, v;
int denoms[1000];
bool taken[1000];
int best;
int n_covered;

int main() {
  int n_cases;
  scanf("%d", &n_cases);

  for (int ctr = 0; ctr < n_cases; ++ctr) {
    memset(taken, 0, sizeof(taken));
    scanf("%d%d%d", &c, &d, &v);


    for (int i = 0; i < d; ++i) {
      scanf("%d", &denoms[i]);
    }

    int split = v/2 + 1;
    best = split;

    for (unsigned mask = 0; mask < (1U << (split + 1)); ++mask) {
      int arr[1000];
      int k = 0;
      memset(taken, 0, sizeof(taken));
      for (int i = 0; i < v/2 + 1; ++i) {
        if ((mask >> i) & 1) {
          arr[k++] = i +1;
          taken[i+1] = 1;
        }
      }
      bool ok = true;
      for (int i = 0; i < d; ++i) {
        if (!taken[denoms[i]]) {
          arr[k++] = denoms[i];
          taken[denoms[i]] = true;
        }
      }

      if (!ok) continue;
      bool covered[100];
      bool pcovered[100];
      memset(covered, 0, sizeof(covered));
      memset(pcovered, 0, sizeof(pcovered));

        
      pcovered[0] = 1;

      for (int i = 0; i < k; ++i) {
        int x = arr[i];
        covered[0] = 1;
        for (int j = x; j <= v; ++j) {
          covered[j] = pcovered[j] || pcovered[j-x];
        }
        for (int j = 0; j <= v; ++j) {
          pcovered[j] = covered[j];
        }
      }

#ifdef DEBUG
      for (int i = 1; i <= v; ++i) {
        printf("%d:%d ", i, covered[i]);
      }
      puts("");
#endif

      n_covered = accumulate(covered+1, covered+v+1, 0);

      if (n_covered == v) {
        best = min(best, k);
      }
    }
    


    printf("Case #%d: %d\n", ctr+1, best-d);
    //printf("Case #%d: %lf", ctr+1, (high*(double)cnt - given)/(double)cnt);
  }
  return 0;
}
