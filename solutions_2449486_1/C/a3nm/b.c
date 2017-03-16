#include <stdio.h>

int main() {
  int T, ncase;
  scanf("%d", &T);
  for (ncase = 0; ncase < T; ncase++) {
    printf("Case #%d: ", ncase + 1);
    int N, M;
    scanf("%d", &N);
    scanf("%d", &M);
    int x, y, xb, yb;
    int grid[100][100];
    for (x = 0; x < N; x++)
      for (y = 0; y < M; y++)
        scanf("%d", &grid[x][y]);
    int ok = 1;
    for (x = 0; x < N; x++)
      for (y = 0; y < M; y++) {
        int cellxok = 1;
        for (xb = 0; xb < N; xb++) {
          if (grid[xb][y] > grid[x][y]) {
            cellxok = 0;
            break;
          }
        }
        int cellyok = 1;
        for (yb = 0; yb < M; yb++) {
          if (grid[x][yb] > grid[x][y]) {
            cellyok = 0;
            break;
          }
        }
        if (!(cellxok || cellyok))
          ok = 0;
      }
    printf("%s\n", ok ? "YES" : "NO");
  }
  return 0;
}

