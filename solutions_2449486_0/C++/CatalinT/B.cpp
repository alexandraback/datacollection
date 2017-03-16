#include <cstdio>
#include <string>

#define MAX_D 111

using namespace std;

int N, M;
int ok[MAX_D][MAX_D];
int A[MAX_D][MAX_D];
int row_max[MAX_D], col_max[MAX_D];

int ans() {
  for (int i = 1; i <= N; ++i)
    row_max[i] = -1;

  for (int j = 1; j <= M; ++j)
    col_max[j] = -1;

  for (int i = 1; i <= N; ++i)
    for (int j = 1; j <= M; ++j) {
      if (A[i][j] > row_max[i])
        row_max[i] = A[i][j];
      if (A[i][j] > col_max[j])
        col_max[j] = A[i][j];
    }

  for (int i = 1; i <= N; ++i)
    for (int j = 1; j <= M; ++j)
      if (A[i][j] < row_max[i] && A[i][j] < col_max[j])
        return 0;

  return 1;
}

int main() {
  int T;
  scanf("%d", &T);
  for (int i = 1; i <= T; ++i) {
    scanf("%d %d", &N, &M);
    for (int a = 1; a <= N; ++a)
      for (int b = 1; b <= M; ++b)
        scanf("%d", &A[a][b]);

    printf("Case #%d: %s\n", i, ans() ? "YES" : "NO");      
  }

  return 0;
}
