#include <bits/stdc++.h>

#define fori(i,b,e) for (int i = (b); i < (e); i++)
#define mp make_pair
#define pb push_back
#define all(a) (a).begin(), (a).end()
#define elsif else if
#define sz(a) ((int)(a).size())
#define X first
#define Y second

using namespace std;

typedef long long int int64;
typedef pair<int, int> pii;
typedef vector<int> vi;

inline int getInt() { int res;  scanf("%d", &res);  return res; }
inline double getDbl() { double res;  scanf("%lf", &res);  return res; }

const int maxn = 2000;
int f[maxn];
vector<int> e[maxn], re[maxn];
int col[maxn];
bool incycle[maxn];
vector<vi> cycles;
int st[maxn];
int len;

void clear() {
}

void read() {
}

void dfs1(int u) {
  col[u] = 1;
  st[len++] = u;
  for (auto v : e[u]) {
    if (col[v] == 0) {
      dfs1(v);
    }
    else if (col[v] == 1) {
      vi cycle;
      for (int i = len - 1; i >= 0; i--) {
        cycle.pb(st[i]);
        incycle[st[i]] = true;
        if (st[i] == v)
          break;
      }
      assert(st[0] == v);
      cycles.pb(cycle);
    }
  }
  col[u] = 2;
  len--;
}

int dfs2(int u) {
  int d = 0;
  for (auto v : e[u]) {
    if (!incycle[v]) {
      d = max(d, dfs2(v));
    }
  }
  return d + 1;
}

void solve() {
  cycles.clear();
  int n = getInt();
  fori(i,0,n) {
    col[i] = 0;
    incycle[i] = false;
    e[i].clear();
    re[i].clear();
    f[i] = getInt() - 1;
  }
  fori(i,0,n) {
    e[f[i]].pb(i);
  }
  fori(i,0,n) {
    assert(len == 0);
    if (col[i] == 0)
      dfs1(i);
  }
  //cerr << "aaaa\n";
  int res = 0;
  for (auto cycle : cycles) {
    if (sz(cycle) > 2) {
      res = max(res, sz(cycle));
    }
  }
  int d = 0;
  for (auto cycle : cycles) {
    if (sz(cycle) == 2) {
      for (auto u : cycle) {
        d += dfs2(u);
      }
    }
  }
  res = max(res, d);
  printf("%d\n", res);
}

int main() {
  freopen("in.txt", "rt", stdin);
  freopen("out.txt", "wt", stdout);
  srand(time(0));
  int N = getInt();
  fori(T,1,N+1) {
    clear();
    read();
    //cerr << "Case #" << T << endl;
    printf("Case #%d: ", T);
    solve();
  }
  return 0;
}
