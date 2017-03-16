#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cfloat>
#include <climits>
#include <cctype>
#include <cmath>
#include <cassert>
#include <ctime>
   
#include <iostream>
#include <iomanip>
#include <algorithm>
#include <sstream>
#include <string>
#include <vector>
#include <deque>
#include <list>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <bitset>
#include <complex>
#include <limits>
#include <functional>
#include <numeric>

using namespace std;

#define fr(a,b,c) for(int (a) = (b); (a) < (c); ++(a))
#define rp(a,b) fr(a,0,b)
#define cl(a,b) memset((a), (b), sizeof(a))
#define sc(a) scanf("%d", &a)
#define sc2(a,b) scanf("%d%d", &a, &b)
#define sc3(a,b,c) scanf("%d%d%d", &a, &b, &c)
#define scs(s) scanf("%s", s)
#define pri(x) printf("%d\n", x)
#define fre(a,b) for(int a = adj[b]; ~a; a = ant[a])

#define iter(a) __typeof((a).begin())
#define fore(a,b) for(iter(b) a = (b).begin(); a != (b).end(); ++a)

#define st first
#define nd second
#define mp make_pair
#define pb push_back

#define db(x) cerr << #x << " == " << x << endl
#define _ << ", " <<

#define MAXN 120000
#define MAXM 110000
#define add(a,b,c) to[z] = b, cap[z] = c, ant[z] = adj[a], adj[a] = z++
int to[MAXM], cap[MAXM], ant[MAXM], z;
int adj[MAXN], copy_adj[MAXN], fila[MAXN], level[MAXN];

const int oo = 0x3f3f3f3f;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef vector<int> vi;

map<string, int> ids1, ids2;
int sz1, sz2;
char str[100100];
int cas = 1;

int bfs(int source, int sink) {
  memset(level,-1,sizeof level);
  level[source] = 0;
  int front = 0, size = 0, v;
  fila[size++] = source;
  while (front < size) {
    v = fila[front++];
    for (int i = adj[v]; i != -1; i = ant[i]) {
      if (cap[i] && level[to[i]] == -1) {
        level[to[i]] = level[v] + 1;
        fila[size++] = to[i];
      }
    }
  }
  return level[sink] != -1;
}

int dfs(int v, int sink, int flow) {
  if (v == sink) return flow;
  int f;
  for (int &i = copy_adj[v]; i != -1; i = ant[i]) {
    if (cap[i] && level[to[i]] == level[v]+1 && (f = dfs(to[i], sink, min(flow, cap[i])))) {
      cap[i]-=f, cap[i^1]+=f;
      return f;
    }
  }
  return 0;
}

int maxflow(int source, int sink) {
  int ret = 0, flow;
  while (bfs(source, sink)) {
    memcpy(copy_adj, adj, sizeof adj);
    while ((flow = dfs(source, sink, 1<<30))) ret += flow;
  }
  return ret;
}

void proc() {
  cl(adj,-1); z = 0;
  ids1.clear(), ids2.clear();
  sz1 = sz2 = 0;
  int n; sc(n);
  rp(i,n) {
    scs(str);
    if (ids1.count(str) == 0) ids1[str] = sz1++;
    int a = ids1[str];
    scs(str);
    if (ids2.count(str) == 0) ids2[str] = sz2++;
    int b = ids2[str] + n;
    add(a,b,1);
    add(b,a,0);
  }

  rp(i,sz1) {
    add(2*n+1, i, 1);
    add(i, 2*n+1, 0);
  }
  rp(i,sz2) {
    add(i+n, 2*n+2, 1);
    add(2*n+2, i+n, 0);
  }


  int mf = maxflow(2*n+1, 2*n+2);
  int q = mf - sz1 - sz2 + n;
  printf("Case #%d: %d\n", cas++, q);
}

int main() {
  int t; sc(t);
  while (t--) {
    proc();
  }
  return 0;
}






