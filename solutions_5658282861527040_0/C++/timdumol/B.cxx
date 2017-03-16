#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <complex>
#include <numeric>
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

typedef unsigned long long ullong;
typedef long long llong;
typedef list<int> EdgeList;
typedef vector<EdgeList> AdjList;
typedef pair<int, int> ii;
typedef vector<ii> vii;

#define FOR_EDGE(adj,v,it) for (EdgeList::iterator it = adj[v].begin(); \
    it != adj[v].end(); ++it)

int main() {
  int n_cases;
  scanf("%d", &n_cases);
  for (int ctr = 0; ctr < n_cases; ++ctr) {
    int a, b, k;
    scanf("%d %d %d", &a, &b, &k);
    int cnt = 0;
    for (int i = 0; i < a; ++i) {
      for (int j = 0; j < b; ++j) {
        if ((i&j) < k) {
          ++cnt;
        }
      }
    }
    printf("Case #%d: %d\n", ctr+1, cnt);
  }
  return 0;
}
