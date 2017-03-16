#include <bits/stdc++.h>
#define FOR(i, n) for (int i = 0; i < (n); ++i)
#define REP(i, n) for (int i = 1; i <= (n); ++i)
using namespace std;

int T, J, P, S, K;
int all[27][3];

int main() {
  scanf("%d", &T);
  REP (tc, T) {
    scanf("%d%d%d%d", &J, &P, &S, &K);

    int a = 0;
    REP (j, J) REP (p, P) REP (s, S) {
      all[a][0] = j;
      all[a][1] = p;
      all[a][2] = s;
      ++a;
    }

    int ans = -1, best = 0;
    for (int m = 0; m < (1 << a); ++m) {
      int s = __builtin_popcount(m);
      if (s <= best) continue;

      map<pair<int, int>, int> jp, ps, js;
      bool ok = true;
      FOR (i, a) if ((m >> i) & 1) {
        if (++jp[make_pair(all[i][0], all[i][1])] > K) { ok = false; break; }
        if (++ps[make_pair(all[i][1], all[i][2])] > K) { ok = false; break; }
        if (++js[make_pair(all[i][0], all[i][2])] > K) { ok = false; break; }
      }

      if (ok) {
        ans = m;
        best = s;
      }
    }

    printf("Case #%d: %d\n", tc, best);
    FOR (i, a) if ((ans >> i) & 1) {
      printf("%d %d %d\n", all[i][0], all[i][1], all[i][2]);
    }

  }
  return 0;
}
