#include <algorithm>
#include <cassert>
#include <cstring>
#include <iostream>

using namespace std;

#define TRACE(x) cout << #x << " = " << x << endl
#define REP(i, n) for (int i = 0; i < (n); ++i)

typedef long long llint;

char a[55][55];

bool solve(int n, int m, int k) {
  if (k == 1) {
    REP(i, n) REP(j, m) a[i][j] = '*';
    a[0][0] = 'c';
    return true;
  }
  if (n == 1) {
    REP(i, m) a[0][i] = (i < k) ? '.' : '*';
    a[0][0] = 'c';
    return true;
  }
  if (m == 1) {
    REP(i, n) a[i][0] = (i < k) ? '.' : '*';
    a[0][0] = 'c';
    return true;
  }
      
  for (int A = 2; A <= m; ++A)
    for (int B = 2; B <= n; ++B) {
      int lo = 2*A + 2*B - 4;
      int hi = A*B;

      if (lo <= k && k <= hi) {
        REP(i, n) REP(j, m) a[i][j] = '*';
        REP(j, A) a[0][j] = a[1][j] = '.';
        REP(i, B) a[i][0] = a[i][1] = '.';
        a[0][0] = 'c';
        k -= lo;
        for (int i = 2; i < B && k > 0; ++i)
          for (int j = 2; j < A && k > 0; ++j)
            a[i][j] = '.', k--;
        return true;
      }
    }
  return false;
}

bool bio[55][55];
int n, m;

bool valid(int x, int y) {
  return x >= 0 && x < n && y >= 0 && y < m;
}

void dfs(int x, int y) {
  if (bio[x][y]) return;
  bio[x][y] = true;
  bool ok = true;
  for (int dx = -1; dx <= 1; ++dx)
    for (int dy = -1; dy <= 1; ++dy)
      if (valid(x+dx, y+dy) && a[x+dx][y+dy] == '*') { ok = false; break; }
  if (ok)
    for (int dx = -1; dx <= 1; ++dx)
      for (int dy = -1; dy <= 1; ++dy)
        if (valid(x+dx, y+dy)) dfs(x+dx, y+dy);
}
 
bool check(int n, int m, int k) {
  ::n = n, ::m = m;
  int sx = -1, sy = -1;
  REP(i, n) REP(j, m)
    if (a[i][j] == 'c') {
      assert(sx == -1);
      sx = i, sy = j;
    }

  REP(i, n) REP(j, m) bio[i][j] = false;
  assert(sx != -1);
  dfs(sx, sy);
  int c = 0;
  REP(i, n) REP(j, m)
    if (a[i][j] != '*') {
      c++;
      if (!bio[i][j]) return false;
    }
  
  return c == k;
}
      
int main(void) {
  int T;
  scanf("%d", &T);
  for (int tp = 1; tp <= T; ++tp) {
    int n, m, k;
    scanf("%d %d %d", &n, &m, &k);

    printf("Case #%d:\n", tp);

    if (solve(n, m, n*m - k)) {
      REP(i, n) {
        a[i][m] = '\0';
        puts(a[i]);
      }
      
      assert(check(n, m, n*m-k) == true);
    } else
      puts("Impossible");

  }
  return 0;
}
