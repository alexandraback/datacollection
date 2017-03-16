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

int main() {
  int n_cases;
  scanf("%d", &n_cases);


  for (int ctr = 0; ctr < n_cases; ++ctr) {
    int r,c,w;
    scanf("%d%d%d", &r, &c, &w);

    int ans = 0;
    ans += (r-1) * c/w;

    
    if (c % w == 0) {
      ans += c/w + w-1;
    } else {
      ans += c/w + w;
    }

    printf("Case #%d: %d\n",  ctr+1, ans);
  }
  return 0;
}
