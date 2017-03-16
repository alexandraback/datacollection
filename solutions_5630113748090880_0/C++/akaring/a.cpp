// {{{
#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second
#define MP make_pair
#define MT make_tuple
#define PB push_back
#define EB emplace_back
#define SZ(c) int((c).size())
#define ALL(c) (c).begin(),(c).end()
#define REP(i,n) for(int i=0;i<int(n);++i)
template<class T>inline void check_min(T&a,T b){if(b<a)a=b;}
template<class T>inline void check_max(T&a,T b){if(a<b)a=b;}
typedef long long lint;
typedef vector<int> VI;
typedef pair<int, int> PII;
// }}}

int n;
vector<VI> a;
VI row[64], col[64];

bool check(int i, VI *ps, VI &v) {
  REP (k, i) {
    if (ps[k].empty()) {
      continue;
    }
    if (ps[k][i] != v[k]) {
      return false;
    }
  }
  return true;
}

bool dfs(int i) {
  if (i >= n) return true;

  int mi = 1e9;
  REP (j, SZ(a)) check_min(mi, a[j][i]);

  // printf("@%d: %d\n", i, mi);

  VI is;
  REP (j, SZ(a)) if (a[j][i] == mi) is.PB(j);
  sort(ALL(is), greater<int>());

  vector<VI> vs;
  for (int j: is) {
    vs.PB(a[j]);
    a.erase(a.begin() + j);
  }

  if (SZ(vs) == 1) {
    if (check(i, row, vs[0])) {
      col[i] = vs[0];
      if (dfs(i + 1)) return true;
      col[i].clear();
    }
    if (check(i, col, vs[0])) {
      row[i] = vs[0];
      if (dfs(i + 1)) return true;
      row[i].clear();
    }
  } else if (SZ(vs) == 2) {
    if (check(i, row, vs[0]) && check(i, col, vs[1])) {
      col[i] = vs[0];
      row[i] = vs[1];
      if (dfs(i + 1)) return true;
      col[i].clear();
      row[i].clear();
    }
    if (check(i, col, vs[0]) && check(i, row, vs[1])) {
      row[i] = vs[0];
      col[i] = vs[1];
      if (dfs(i + 1)) return true;
      col[i].clear();
      row[i].clear();
    }
  }

  for (VI &v: vs) {
    a.PB(v);
  }
  return false;
}

void gao() {
  scanf("%d", &n);

  REP (i, n) {
    row[i].clear();
    col[i].clear();
  }

  a.clear();
  REP (i, 2 * n - 1) {
    VI v(n);
    REP (j, n) {
      scanf("%d", &v[j]);
    }
    a.PB(v);
  }

  if (!dfs(0)) {
    assert(false);
  }

  /*
  REP (i, n) {
    int mi = 1e9;
    REP (j, SZ(a)) {
      check_min(mi, a[j][i]);
    }

    VI is;
    REP (j, SZ(a)) {
      if (a[j][i] == mi) {
        is.PB(j);
      }
    }
    sort(ALL(is), greater<int>());

    vector<VI> vs;
    for (int j: is) {
      vs.PB(a[j]);
      a.erase(a.begin() + j);
    }

    if (SZ(vs) == 1) {
      if (check(i, row, vs[0])) {
        col[i] = vs[0];
      } else {
        row[i] = vs[0];
      }
    } else {
      if (check(i, row, vs[0]) && check(i, col, vs[1])) {
        col[i] = vs[0];
        row[i] = vs[1];
      } else {
        col[i] = vs[1];
        row[i] = vs[0];
      }
    }
  }
  */

  REP (i, n) {
    if (row[i].empty()) {
      REP (j, n) {
        printf(" %d", col[j][i]);
      }
      printf("\n");
      return;
    } else if (col[i].empty()) {
      REP (j, n) {
        printf(" %d", row[j][i]);
      }
      printf("\n");
      return;
    }
  }
}

int main() {
  int n_case;
  scanf("%d", &n_case);
  for (int index = 1; index <= n_case; ++index) {
    printf("Case #%d:", index);
    gao();
  }
  return 0;
}
