#include <algorithm>
#include <cstring>
#include <cstdio>

using namespace std;

const double INF = 1e10;
const int MAXL = 100;
const int dr[] = { 0, -1, 0, 1 }, dc[] = { 1, 0, -1, 0 };

int H, N, M;
int C[MAXL][MAXL], F[MAXL][MAXL];
double d[MAXL][MAXL];
bool mark[MAXL][MAXL];

void dfs(int r, int c)
{
  mark[r][c] = true; d[r][c] = 0.0;

  for (int i = 0; i < 4; ++i) {
    int nr = r+dr[i], nc = c+dc[i];
    if (nr < 0 || nr >= N || nc < 0 || nc >= M) continue;

    if (H+50 > C[nr][nc] || F[r][c]+50 > C[nr][nc] || F[nr][nc]+50 > C[nr][nc]) continue;
    if (F[nr][nc]+50 > C[r][c]) continue;

    if (!mark[nr][nc]) dfs(nr, nc);
  }
}

void solve()
{
  for (int i = 0; i < N; ++i)
    for (int j = 0; j < M; ++j) d[i][j] = INF;

  memset(mark, 0, sizeof(mark));
  dfs(0, 0);

  memset(mark, 0, sizeof(mark));
  while (true) {
    int br = -1, bc;

    for (int r = 0; r < N; ++r)
      for (int c = 0; c < M; ++c)
        if (!mark[r][c] && (br == -1 || d[r][c] < d[br][bc])) { br = r; bc = c; }

    if (br == -1 || d[br][bc]*2 > INF) break;

    mark[br][bc] = true;

    for (int i = 0; i < 4; ++i) {
      int nr = br+dr[i], nc = bc+dc[i];
      if (nr < 0 || nr >= N || nc < 0 || nc >= M) continue;

      if (F[br][bc]+50 > C[nr][nc] || F[nr][nc]+50 > C[nr][nc] || F[nr][nc]+50 > C[br][bc]) continue;

      double dt = d[br][bc];
      if (H-10*d[br][bc]+50 > C[nr][nc]) dt += ((H-10*d[br][bc]+50) - C[nr][nc]) / 10.0;
      if (H-10*dt-20 >= F[br][bc]) dt += 1; else dt += 10;

      if (d[nr][nc] > dt) d[nr][nc] = dt;
    }
  }

  printf("%.6lf\n", d[N-1][M-1]);
}

int main()
{
  int T; scanf("%d", &T);

  for (int t = 0; t < T; ++t) {
    scanf("%d%d%d", &H, &N, &M);

    for (int i = 0; i < N; ++i)
      for (int j = 0; j < M; ++j) scanf("%d", &C[i][j]);

    for (int i = 0; i < N; ++i)
      for (int j = 0; j < M; ++j) scanf("%d", &F[i][j]);

    printf("Case #%d: ", t+1);
    solve();
  }

  return 0;
}
