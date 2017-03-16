#include <algorithm>
#include <queue>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cassert>
using namespace std;

const int MAXR = 5;
const int MAXN = MAXR * MAXR;
const int dr[] = { -1, -1, -1, 0, 0, 1, 1, 1 };
const int dc[] = { -1, 0, 1, -1, 1, -1, 0, 1 };

bool visited[MAXR][MAXR];
int  grid[MAXR][MAXR], good[MAXR][MAXR];
int  res[MAXN];
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
  sr = -1; sc = -1;

  memset(grid, 0, sizeof(grid));

  for (int i = 0; i < K; ++i) {
    int r = res[i] / C, c = res[i] % C;
    grid[r][c] = 1;
  }

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
      if (good[r][c] && (sr == -1 || sc == -1)) {
        sr = r; sc = c;
      }
    }

  if (sr == -1 || sc == -1) {
    sr = res[0] / C; sc = res[0] % C;
  }

  memset(visited, 0, sizeof(visited));
  dfs(sr, sc);

  for (int r = 0; r < R; ++r)
    for (int c = 0; c < C; ++c)
      if ((grid[r][c] ^ visited[r][c]) != 0)
        return false;

  return true;
}

bool rek(int i, int next) {
  if (i < K) {
    assert(next < N);
    for (int k = next; k < N - (K-i) + 1; ++k) {
      res[i] = k;
      if (rek(i+1, k+1)) {
        return true;
      }
    }
    return false;
  }

  return check();
}

void solve(int R, int C, int M) {
  N = R*C; K = N-M;

  if (!rek(0, 0)) {
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
    solve(R, C, M);
  }
  return EXIT_SUCCESS;
}
