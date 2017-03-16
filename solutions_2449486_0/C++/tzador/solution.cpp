#include <algo/macros.hpp>

#define MAX 110

int B[MAX][MAX];
int H[MAX];
int V[MAX];
int N, M;

int main() {
  FREOPEN("small.in");
  FREOPEN_OUT("small.out");
  int T;
  scanf("%d", &T);

  for (int t = 1; t <= T; t++) {
    scanf("%d %d", &N, &M);

    for (int i = 0; i < N; i++)
      V[i] = 0;
    for (int j = 0; j < M; j++)
      H[j] = 0;

    for (int i = 0; i < N; i++)
      for (int j = 0; j < M; j++) {
        scanf("%d\n", &B[i][j]);
        V[i] = max(V[i], B[i][j]);
        H[j] = max(H[j], B[i][j]);
      }

    bool is_possible = true;
    for (int i = 0; is_possible && i < N; i++)
      for (int j = 0; is_possible && j < M; j++)
        if (B[i][j] != min(V[i], H[j]))
          is_possible = false;

    printf("Case #%d: %s\n", t, is_possible ? "YES" : "NO");

  }
}
