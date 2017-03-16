#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <set>
#include <string>
#include <map>
#include <functional>
#include <utility>
#include <vector>
#include <list>

using namespace std;

typedef unsigned long long ullong;
typedef long long llong;
typedef list<int> EdgeList;
typedef vector<EdgeList> AdjList;
typedef pair<int, int> ii;
typedef vector<ii> vii;

#define FOR_EDGE(adj,v,it) for (EdgeList::iterator it = adj[v].begin(); \
    it != adj[v].end(); ++it)

int n;
int best = 0;
int a[1000];
int b[1000];
int comp[1000];

// branch and bound
void f(int n_stars, int n_lev, int n_comp) {
  if (n_comp == n) {
    if (best == 0) {
      best = n_lev;
    } else {
      best = min(best, n_lev);
    }
    return;
  }
  if (best > 0 && n_lev + (n - n_comp) >= best) return;
  for (int i = 0; i < n; ++i) {
    if (comp[i] < 2 && n_stars >= b[i]) {
      int old = comp[i];
      comp[i] = 2;
      f(n_stars + (2 - old), n_lev+1, n_comp+1);
      comp[i] = old;
    } else if (comp[i] < 1 && n_stars >= a[i]) {
      int old = comp[i];
      comp[i] = 1;
      f(n_stars + (1 - old), n_lev+1, n_comp);
      comp[i] = old;
    }
  }
}


int main() {
  setvbuf(stdin, NULL, _IOFBF, 10000);
  setvbuf(stdout, NULL, _IOFBF, 10000);
 
  int n_cases;
  scanf("%d", &n_cases);
  for (int ctr = 0; ctr < n_cases; ++ctr) {
    memset(comp, 0, sizeof(comp));
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
      scanf("%d%d", &a[i], &b[i]);
    }
    best = 0;
    f(0, 0, 0);
    printf("Case #%d: ", ctr+1);
    if (best > 0) {
      printf("%d\n", best);
    } else {
      puts("Too Bad");
    }
  }

  return 0;
}
