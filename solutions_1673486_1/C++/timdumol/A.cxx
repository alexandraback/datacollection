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

int main() {
  setvbuf(stdin, NULL, _IOFBF, 10000);
  setvbuf(stdout, NULL, _IOFBF, 10000);
 
  int n_cases;
  scanf("%d", &n_cases);
  double prob[100000];
  double mat[100000];
  for (int ctr = 0; ctr < n_cases; ++ctr) {
    memset(mat, 0, sizeof(mat));
    int a, b;
    scanf("%d%d", &a, &b);
    for (int i = 0; i < a; ++i) {
      scanf("%lf", &prob[i]);
    }
    double ent = 2 + b;
    double p = 1;
    double q = 0;
    double best = ent;
    for (int v = 0; v <= a; ++v) {
      double u = a - v;
      double x = (q)*(u + (b - (a-u)) + b + 2) + (1-q)*(u + (b - (a-u)) + 1);
      best = min(best, x);
      /*for (int u = 0; u <= a; ++u) {
        if (k >= a-u) {
          mat[u] += p*(1-prob[k])*(u + (b - (a-u)) + 1);
        } else {
          mat[u] += p*(1-prob[k])*(u + (b - (a-u)) + b + 2);
        }
      }*/
      if (v < a) {
        q += p*(1-prob[v]);
        p *= prob[v];
      }
    }
    printf("Case #%d: %.6f\n", ctr+1, best);
  }
  

  return 0;
}
