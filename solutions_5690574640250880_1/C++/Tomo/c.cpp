#include <algorithm>
#include <queue>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cassert>
using namespace std;

const int MAXR = 64;
const int MAXN = MAXR * MAXR;
const int dr[] = { -1, -1, -1, 0, 0, 1, 1, 1 };
const int dc[] = { -1, 0, 1, -1, 1, -1, 0, 1 };

bool visited[MAXR][MAXR];
int  grid[MAXR][MAXR], good[MAXR][MAXR];
int  R, C, M, N, K, sr, sc;

inline bool inside(int r, int c) {
  return r >= 0 && c >= 0 && r < R && c < C;
}

void dfs(int r, int c) {
  visited[r][c] = true;
  if (!good[r][c]) {
    return;
  }

  for (int d = 0; d < 8; ++d) {
    int nr = r + dr[d], nc = c + dc[d];
    if (inside(nr, nc) && !visited[nr][nc]) {
      assert(grid[nr][nc]);
      dfs(nr, nc);
    }
  }
}

void print_grid() {
  for (int i = 0; i < R; ++i) {
    for (int j = 0; j < C; ++j) {
      if (i == sr && j == sc) printf("c");
      else printf(grid[i][j] ? "." : "*");
    }
    printf("\n");
  }
}

bool check() {
  sr = 0; sc = 0;

  for (int r = 0; r < R; ++r)
    for (int c = 0; c < C; ++c) {
      int cnt = 0;

      if (!grid[r][c]) {
        good[r][c] = false;
        continue;
      }

      for (int d = 0; d < 8; ++d) {
        int nr = r + dr[d], nc = c + dc[d];
        if (inside(nr, nc)) {
          cnt += (grid[nr][nc] == 0);
        }
      }

      good[r][c] = (cnt == 0);
    }

  memset(visited, 0, sizeof(visited));
  dfs(sr, sc);

  for (int r = 0; r < R; ++r)
    for (int c = 0; c < C; ++c)
      if ((grid[r][c] ^ visited[r][c]) != 0)
        return false;

  return true;
}

bool meh() {
  for (int r = 1; r <= min(K, R); ++r) {
    int c = K / r, c_last = K - c*r;
    if (c + (c_last > 0) > C) continue;
    if (c_last == 1 && r <= 2) continue;

    memset(grid, 0, sizeof(grid));
    for (int i = 0; i < r; ++i)
      for (int j = 0; j < c+1; ++j)
        grid[i][j] = j < c || i < c_last;

    if (c_last == 1) {
      assert(grid[0][c]);

      grid[1][c] = 1;
      grid[r-1][c-1] = 0;
    }

    if (check()) return true;
  }

  for (int c = 1; c <= min(K, C); ++c) {
    int r = K / c, r_last = K - c*r;
    if (r + (r_last > 0) > R) continue;
    if (r_last == 1 && c <= 2) continue;

    memset(grid, 0, sizeof(grid));
    for (int i = 0; i < r+1; ++i)
      for (int j = 0; j < c; ++j)
        grid[i][j] = i < r || j < r_last;

    if (r_last == 1) {
      assert(grid[r][0]);
      grid[r][1] = 1;
      grid[r-1][c-1] = 0;
    }

    if (check()) return true;
  }

  return false;
}

void solve() {
  N = R*C; K = N-M;

  if (!meh()) {
    printf("Impossible\n");
    return;
  }

  print_grid();
}

int main() {
  int T; scanf("%d", &T);
  for (int tc = 1; tc <= T; ++tc) {
    scanf("%d%d%d", &R, &C, &M);

    printf("Case #%d:\n", tc);
    solve();
  }
  return EXIT_SUCCESS;
}
