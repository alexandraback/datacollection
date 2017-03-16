#include <bits/stdc++.h>

#define pb push_back
#define mp make_pair
#define pii pair<int,int>
#define pdd pair<double,double>
#define uint unsigned int
#define LL __int128
#define ULL unsigned LL
#define VI vector<int>
#define X first
#define Y second
#define reads(_s) getline(cin,_s)
#define sz(_v) ((int)_v.size())
#define all(_v) (_v).begin(),(_v).end()
#define FOR(_i,a,b) for (int _i(a),_l(b); _i<=_l; ++_i)
#define rept(i,a) FOR(i,0,(int)(a)-1)
#define x1 X1
#define y1 Y1
#define sqr(a) ((a)*(a))
#define C(a) memset((a),0,sizeof (a))
#define MS(a,x) memset((a),(x),sizeof (a))
#define INF 1000000000
#define INFL INF*1ll*INF
#define PI 3.141592653589
#define eps 1e-6
#define MOD 1000000007
#define PRIME 312427

using namespace std;

int tst;

const int MAXN = 2010;
 
struct edge {
  int a, b, cap, flow;
};
 
int n, s, t, d[MAXN], ptr[MAXN], q[MAXN];
vector<edge> e;
vector<int> g[MAXN];
 
void add_edge (int a, int b, int cap) {
  edge e1 = { a, b, cap, 0 };
  edge e2 = { b, a, 0, 0 };
  g[a].push_back ((int) e.size());
  e.push_back (e1);
  g[b].push_back ((int) e.size());
  e.push_back (e2);
}
 
bool bfs() {
  int qh=0, qt=0;
  q[qt++] = s;
  memset (d, -1, n * sizeof d[0]);
  d[s] = 0;
  while (qh < qt && d[t] == -1) {
    int v = q[qh++];
    for (size_t i=0; i<g[v].size(); ++i) {
      int id = g[v][i],
        to = e[id].b;
      if (d[to] == -1 && e[id].flow < e[id].cap) {
        q[qt++] = to;
        d[to] = d[v] + 1;
      }
    }
  }
  return d[t] != -1;
}
 
int dfs (int v, int flow) {
  if (!flow)  return 0;
  if (v == t)  return flow;
  for (; ptr[v]<(int)g[v].size(); ++ptr[v]) {
    int id = g[v][ptr[v]],
      to = e[id].b;
    if (d[to] != d[v] + 1)  continue;
    int pushed = dfs (to, min (flow, e[id].cap - e[id].flow));
    if (pushed) {
      e[id].flow += pushed;
      e[id^1].flow -= pushed;
      return pushed;
    }
  }
  return 0;
}
 
int dinic() {
  int flow = 0;
  for (;;) {
    if (!bfs())  break;
    memset (ptr, 0, n * sizeof ptr[0]);
    while (int pushed = dfs (s, INF))
      flow += pushed;
  }
  return flow;
}

map<string, int> do_it(vector<vector<string>> &d) {
  map<string, vector<string>> MAP;
  map<string, int> have2;
  map<string, int> can2;
  rept(i,sz(d)) {
    MAP[d[i][0]].pb(d[i][1]);
    have2[d[i][1]]++;
  }
  int res(0);
  for (auto &kv : MAP) {
    int can(0);
    for (auto &v : kv.Y) {
      can+=have2[v]>1;
    }
    can2[kv.X]=min(can,sz(kv.Y)-1);
  }
  return can2;
}

int another_solve(vector<vector<string>> &dt) {
  rept(i,MAXN) g[i].clear();
  e.clear();
  C(d); C(ptr); C(q);
  map<string, int> can1(do_it(dt));
  rept(i,sz(dt)) swap(dt[i][0],dt[i][1]);
  map<string, int> can2(do_it(dt));
  rept(i,sz(dt)) swap(dt[i][0],dt[i][1]);
  map<string, int> ONE;
  map<string, int> TWO;
  int mn(1);
  for (auto &kv : can1) {
    const string &w(kv.X);
    const int &lm(kv.Y);
    ONE[w]=mn;
    add_edge(0,mn,lm);
    ++mn;
  }
  int hm(sz(can2));
  int sink(mn+hm);
  for (auto &kv : can2) {
    const string &w(kv.X);
    const int &lm(kv.Y);
    TWO[w]=mn;
    add_edge(mn,sink,lm);
    ++mn;
  }
  rept(i,sz(dt)) {
    add_edge(ONE[dt[i][0]],TWO[dt[i][1]],1);
  }
  n=mn+1;
  s=0,t=sink;
  return dinic();
}

void solve_test() {
  int n;
  scanf("%d\n",&n);
  vector<vector<string>> d(n,vector<string>(2));
  rept(i,n) {
    getline(cin,d[i][0],' ');
    reads(d[i][1]);
  }
  int brute(another_solve(d));
  printf("%d\n",brute);
}

void solve() {
  int n;
  scanf("%d\n",&n);
  rept(t,n) {
    tst=t+1;
    printf("Case #%d: ",t+1);
    solve_test();
  }
}

int main() {
#ifdef yeti
  freopen("input.txt","r",stdin); freopen("output.txt","w",stdout);
#endif

#ifdef yeti
  clock_t tm = clock();
  cout<<setprecision(10);
#endif
  solve();
#ifdef yeti
  cerr<<setprecision(3)<<(clock()-tm+0.)/CLOCKS_PER_SEC<<endl;
#endif
  return 0;
}