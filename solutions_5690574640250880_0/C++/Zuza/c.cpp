#include <cassert>
#include <cstring>

#include <algorithm>
#include <iostream>
#include <set>

using namespace std;

#define REP(i, n) FOR(i, 0, n)
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define TRACE(x) cout << #x << " = " << (x) << endl

typedef long long llint;

int R, S, m;
char grid[123][123];

template<typename T>
ostream& operator << (ostream& os, const vector<T>& vect) {
  for (typename vector<T>::const_iterator it = vect.begin(); it != vect.end(); ++it) {
    os << *it << ", ";
  }  
  return os;
}

int get_sus(int x, int y) {
  int sus = 0;
  for (int dx = -1; dx <= 1; ++dx)
    for (int dy = -1; dy <= 1; ++dy) {
      int nx = x + dx;
      int ny = y + dy;
      if (nx >= 0 && ny >= 0 && nx < R && ny < S && grid[nx][ny] == '*')
        ++sus;
    }
  return sus;
}

char bio[123][123];

void dfs(int x, int y) {
  bio[x][y] = true;
  if (get_sus(x, y) > 0) return;

  for (int dx = -1; dx <= 1; ++dx)
    for (int dy = -1; dy <= 1; ++dy) {
      int nx = x + dx;
      int ny = y + dy;
      if (nx >= 0 && ny >= 0 && nx < R && ny < S) {
        if (!bio[nx][ny] && grid[nx][ny] != '*') {
          dfs(nx, ny);
        }
      }
    }
}

int calc_add(int r, int kol, int last) {
  int add = 0;
  if (r == 0) {
    add = max(0, S - (kol+1));
  } else {
    if (last > 0)
      add = max(0, S - (last+1));
    else
      add = S;
  }
  return add;
}

bool solve() {
  if (m == R*S - 1) {
    REP(r, R) REP(s, S) if (!(r == 0 && s == 0)) grid[r][s] = '*';
    return true;
  }

  static bool dp[51][51][50*50+1]; // 6 MB
  static char rec_last[51][51][50*50+1]; // 6MB
  static short rec_uk[51][51][50*50+1];  // 12 MB

  REP(a, R+1) REP(b, S+1) REP(c, m+1) dp[a][b][c] = false;

  dp[0][S][0] = true;
  for (int r = 0; r < R; ++r) {
    for (int last = 0; last <= S; ++last) {
      for (int uk = 0; uk <= m; ++uk) {
        if (!dp[r][last][uk]) continue;
        auto upd = [r, last, uk](int xr, int xlast, int xuk) {
          if (xuk > m) return;
          dp[xr][xlast][xuk] = true;
          rec_last[xr][xlast][xuk] = last;
          rec_uk[xr][xlast][xuk] = uk;
        };

        for (int kol = 0; kol <= last; ++kol) {
          if (r == 0 && kol == 0) continue;
          int add = calc_add(r, kol, last);
          upd(r+1, kol, uk+add);
        }
      }
    }
  }

  bool ok = false;
  int last_ind = -1;
  REP(last, S+1) if (dp[R][last][m]) { ok = true; last_ind = last; }

  if (ok) {
    int r = R, last = last_ind, uk = m;
    while (r >= 0) {
      assert(dp[r][last][uk]);
      int kol = last; 
      int ex_last = rec_last[r][last][uk];
      int add = calc_add(r-1, kol, ex_last);
      for (int i = S-add; i < S; ++i)
        grid[r-1][i] = '*';
      tie(r, last, uk) = make_tuple(r-1, rec_last[r][last][uk], rec_uk[r][last][uk]);
    }
  }
  return ok;
}

int main(void)
{
  int ntc; scanf("%d", &ntc);
  REP(tc, ntc) {
    scanf("%d %d %d", &R, &S, &m);

    REP(i, R) { REP(j, S) grid[i][j] = '.'; grid[i][S] = 0; }
    grid[0][0] = 'c';

    bool ok = solve();

    if (ok) {
      memset(bio, 0, sizeof bio);
      int cnt = 0;
      REP(r, R) REP(s, S) if (grid[r][s] != '*' && !bio[r][s]) { ++cnt; dfs(r, s); }
      assert(cnt == 1);
    }

    printf("Case #%d:\n", tc+1);
    if (ok)
      REP(i, R) puts(grid[i]);
    else
      puts("Impossible");
    fflush(stdout);
  }
  return 0;
}
