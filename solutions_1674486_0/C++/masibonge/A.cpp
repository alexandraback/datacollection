#include <iostream>
#include <sstream>
#include <cstdio>
#include <string>
#include <cstring>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <complex>
#include <cmath>
#include <iomanip>
#include <cstdlib>

using namespace std;
#define pb         push_back
#define all(a)     (a).begin(),(a).end()
#define sz(a)      (int)((a).size())
#define rep(i,n)   for(int i=0; i<n; ++i)
#define REP(i,j,k) for(int i=j; i<k; ++i)
#define itr(T,v,i) for(T::iterator       i=v.begin(); i!=v.end(); i++)
#define ITR(T,v,i) for(T::const_iterator i=v.begin(); i!=v.end(); i++)n
typedef long long ll;
int    INF = 100000000;
double EPS = 1e-8;
struct Edge{
  int s, d;
  Edge(int s, int d) : 
    s(s), d(d) { }
};
typedef vector<Edge> Edges;
typedef vector<Edges> Graph;

bool bfs(Graph &g, int r) {
  int n = sz(g);
  vector<bool> v(n, 0);
  v[r] = 1;
  queue<int> q;
  q.push(r);
  while (!q.empty()) {
    int p = q.front();
    q.pop();
    itr (Edges, g[p], e) {
      if (v[e->d]) return 1;
      v[e->d] = 1;
      q.push(e->d);
    }
  }
  return 0;
}

int main () {
  int TC; scanf("%d", &TC);
  rep (tc, TC) {
    int n; scanf("%d", &n);
    Graph g(n);
    rep (i, n) {
      int m; scanf("%d", &m);
      rep (j, m) {
	int d;
	scanf("%d", &d);
	g[i].pb(Edge(i, d-1));
      }
    }
    bool f = 0;
    rep (i, n) {
      f = bfs(g, i);
      if (f) break;
    }
    if (f) printf("Case #%d: Yes\n", tc+1);
    else   printf("Case #%d: No\n", tc+1);
  }
  return 0;
}
