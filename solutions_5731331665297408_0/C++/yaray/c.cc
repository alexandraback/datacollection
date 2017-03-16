#include <algorithm>
#include <cstdio>
#include <cstring>
#include <functional>
#include <map>
#include <set>
#include <utility>
#include <vector>
using namespace std;

#define REP(i, n) for (int i = 0; i < (n); i++)
#define REP1(i, n) for (int i = 1; i <= (n); i++)
#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define ROF(i, a, b) for (int i = (b); --i >= (a); )
#define pb push_back
#define mp make_pair
#define fi first
#define se second

typedef vector<int> VI;
typedef pair<int, int> PII;

int ri()
{
  int x;
  scanf("%d", &x);
  return x;
}

const int N = 8;
char a[N][5+1];
int pi[N], ord[N], nei[N], n, st[N], ans[N];
bool g[N][N];

bool dfs(int u, int vis, int nst, int nans)
{
  if (vis == (1<<n)-1) return true;
  int neigh = nei[u];
  REP(i, nst)
    neigh |= nei[st[i]];
  int cand = neigh & ~vis & ~(1<<u);
  int saved[N];
  copy(st, st+nst, saved);
  REP(v, n)
    if (1<<v & cand) {
      int nst2 = nst, uu = u;
      copy(saved, saved+nst, st);
      while (nst2 > 1 && ! g[uu][v])
        uu = st[--nst2-1];
      if (! g[uu][v]) continue;
      ans[nans] = v;
      st[nst2++] = v;
      if (dfs(v, vis|1<<v, nst2, nans+1))
        return true;
    }
  return false;
}

int main()
{
  int cases = ri();
  REP1(cc, cases) {
    n = ri();
    int m = ri();
    REP(i, n) {
      scanf("%s", a[i]);
      pi[i] = i;
      fill_n(g[i], n, false);
      nei[i] = 0;
    }
    sort(pi, pi+n, [&](int x, int y) {
         return strcmp(a[x], a[y]) < 0;
         });
    REP(i, n)
      ord[pi[i]] = i;

    REP(i, m) {
      int u = ord[ri()-1], v = ord[ri()-1];
      g[u][v] = g[v][u] = true;
      nei[u] |= 1 << v;
      nei[v] |= 1 << u;
    }

    REP(i, n) {
      ans[0] = i;
      st[0] = i;
      if (dfs(i, 1<<i, 1, 1))
        break;
    }
    printf("Case #%d: ", cc);
    REP(i, n)
      printf("%s", a[pi[ans[i]]]);
    puts("");
  }
}
