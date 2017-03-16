
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

int n;
int c[128];
int d[128];
char a[128];
char b[128];
int best_x = 0;
int best_y = 0;
int best_delta = -1;

void recurse(int idx) {
  if (idx == 2*n) {
    int x = 0;
    int y = 0;
    for (int i = 0; i < n; ++i) {
      x = 10*x + c[i];
      y = 10*y + d[i];
    }

    auto delta = abs(x-y);
    if (best_delta == -1 || delta < best_delta || delta == best_delta && (x < best_x || (x == best_x && y < best_y))) {
      best_delta = delta;
      best_x = x;
      best_y = y;
    }
    return;
  }
  if (idx < n) {
    if (a[idx] == '?') {
      for (int i = 0; i <= 9; ++i) {
        c[idx] = i;
        recurse(idx+1);
      }
    } else {
      c[idx] = a[idx] - '0';
      recurse(idx+1);
    }
  } else {
    if (b[idx-n] == '?') {
      for (int i = 0; i <= 9; ++i) {
        d[idx-n] = i;
        recurse(idx+1);
      }
    } else {
      d[idx-n] = b[idx-n] - '0';
      recurse(idx+1);
    }
  }
}

int main() {
  int n_cases;
  scanf("%d", &n_cases);

  for (int ctr = 0; ctr < n_cases; ++ctr) {
    scanf("%s %s", a, b);
    n = strlen(a);

    best_x = 0;
    best_y = 0;
    best_delta = -1;

    recurse(0);

    printf("Case #%d: %0*d %0*d\n", ctr+1, n, best_x, n, best_y);
  }
  
  return 0;
}
