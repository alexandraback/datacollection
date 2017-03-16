#include <bits/stdc++.h>
#define FORE(i, c) for (__typeof ((c).begin()) i = (c).begin(); i != (c).end(); ++i)
#define FOR(i, a, b) for (int i = (a); i <= (b); ++i)
#define FORD(i, a, b) for (int i = (a); i >= (b); --i)
#define REP(i, n) for (int i = 0; i < (n); ++i)
#define REPD(i, n) for (int i = (int) (n) - 1; i >= 0; --i)
#define PB push_back
#define MP make_pair
#define fi first
#define se second
#define __ cerr <<
#define _ << " " <<
#define NL endl
using namespace std;
typedef pair<int, int> PII;
typedef long long LL;
typedef double DD;
typedef long double LD;
const LL LLINF = 1e18;
const int INF = 1e9;
const double EPS = 1e-7;
inline const int &INT() { static int x; scanf("%d", &x); return x; }
inline const LL &LONG() { static LL x; scanf("%lld", &x); return x; }
template<class T> inline void MIN(T &a, const T &b) { if (b < a) a = b; }
template<class T> inline void MAX(T &a, const T &b) { if (b > a) a = b; }
// ---------------------------------------------------------------- //

#define BIT(x, i) (((x) >> (i)) & 1)
#define FLIP(x, i) ((x) ^= (1 << (i)))
int bit[5], R, C, grid[5], M, ch[5], nch[5];
char ans[5][5];
vector<int> vi[6];
int dx[] = {0, -1, 1, 0}, dy[] = {-1, 0, 0, 1};

bool rec(int r) {
  if (r >= R) {
    REP(i, R) grid[i] = 0;
    REP(i, R) {
      int m = ch[i] | (ch[i] << 1) | (ch[i] >> 1);
      m &= (1 << C) - 1;
      grid[i] |= m;
      if (i > 0) grid[i - 1] |= m;
      if (i + 1 < R) grid[i + 1] |= m;
    }
    int cnt = 0;
    REP(i, R) cnt += __builtin_popcount(grid[i]);

    if (cnt == M) {
      REP(i, R) REP(j, C) if (BIT(ch[i], j)) {
        REP(k, R) nch[k] = ch[k];
        vector<PII> qu;
        qu.PB(PII(i, j));
        FLIP(nch[i], j);
        REP(k, qu.size()) {
          int u = qu[k].fi, v = qu[k].se;
          REP(t, 4) {
            int uu = u + dx[t], vv = v + dy[t];
            if (uu < 0 || vv < 0 || uu >= R || vv >= C) continue;
            if (BIT(nch[uu], vv)) {
              FLIP(nch[uu], vv);
              qu.PB(PII(uu, vv));
            }
          }
        }
        REP(k, R) if (nch[k]) return 0;
        return 1;
      }
      return 1;
    }
    return 0;
  }
//  REP(i, R) { REP(j, C) if (BIT(grid[i], j)) __ '.'; else __ '*'; __ NL; } __ NL;

  FORE(i, vi[C]) {
    if (r == 0) memset(grid, 0, sizeof grid);
    int m = (*i | (*i << 1) | (*i >> 1));
    m &= (1 << C) - 1;

    ch[r] = *i;
    if (rec(r + 1)) return 1;
  }
  return 0;
}

int main() {
//  ios::sync_with_stdio(false);
//  freopen("in", "r", stdin);
  FOR(x, 1, 5) {
    vector<int> best;
    REP(mask, 1 << x) {
      REP(i, x) bit[i] = BIT(mask, i);
      bool bad = 0;
      REP(i, x) if (bit[i] == 1 && i > 0 && bit[i - 1] == 0) {
        if (i > 1 && bit[i - 2] == 1) bad = 1;
        if (i > 2 && bit[i - 2] == 0 && bit[i - 3] == 1) bad = 1;
      }
      if (!bad) {
        best.PB(mask);
//        REP(i, x) __ bit[i]; __ NL;
      } else {
//        REP(i, x) __ bit[i]; __ NL;
      }
    }
//    __ best.size() _ NL;
    vi[x] = best;
  }

  int TC = INT();
  REP(tc, TC) {
    printf("Case #%d:\n", tc + 1);
    R = INT();
    C = INT();
    M = INT();
    if (R > 5 || C > 5) continue;
    M = R * C - M;
//    __ R _ C _ M _ NL;
    REP(i, R) REP(j, C) ans[i][j] = '*';
    if (M == 1) {
      ans[0][0] = 'c';
    } else {
      if (!rec(0)) goto fail;
      REP(i, R) REP(j, C) if (BIT(grid[i], j)) ans[i][j] = '.';
      bool mark = 0;
      REP(i, R) REP(j, C) if (BIT(ch[i], j) && !mark) ans[i][j] = 'c', mark = 1;
    }
    REP(i, R) { REP(j, C) printf("%c", ans[i][j]); printf("\n"); }
    continue;
    fail: printf("Impossible\n");
  }
  return 0;
}
