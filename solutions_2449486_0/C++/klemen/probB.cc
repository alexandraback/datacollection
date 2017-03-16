#include <stdio.h>
#include <stdint.h>

#define MAXN 110
#define MAXM 110

int T = 0, N = 0, M = 0;
int yard[MAXN][MAXM];
int row[MAXN];
int col[MAXM];

int max(int a, int b) {
  return a > b ? a : b;
}

int min(int a, int b) {
  return a < b ? a : b;
}

bool mow() {
  for (int i = 0; i < N; i++)
    row[i] = 0;
  for (int j = 0; j < M; j++)
    col[j] = 0;

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      row[i] = max(row[i], yard[i][j]);
      col[j] = max(col[j], yard[i][j]);
    }
  }

  for (int i = 0; i < N; i++)
    for (int j =0; j < M; j++)
      if (yard[i][j] != min(row[i], col[j]))
        return false;
  return true;
}

int main() {
  scanf("%d", &T);
  for (int t = 0; t < T; t++) {
    scanf("%d %d", &N, &M);
    for (int i = 0; i < N; i++)
      for (int j = 0; j < M; j++)
        scanf("%d", &yard[i][j]);
    printf("Case #%d: %s\n", t + 1, mow() ? "YES" : "NO");
  }
}
