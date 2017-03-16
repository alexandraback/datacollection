#include <stdio.h>

int main()
{
  int T;
  scanf("%d\n", &T);

  for (int t=1; t<=T; ++t) {
    int N, M;
    scanf("%d %d\n", &N, &M);

    int lawn[N][M];
    int maxLines[N];
    int maxColumns[M];

    for (int i=0; i<N; ++i) {
      for (int j=0; j<M; ++j) {
        int tmp;
        scanf("%d", &tmp);
        lawn[i][j] = tmp;
      }
    }

    // Get the maximum for lines.
    for (int i=0; i<N; ++i) {
      int max = -1;
      for (int j=0; j<M; ++j) {
        if (max < lawn[i][j]) {
          max = lawn[i][j];
        }
      }
      maxLines[i] = max;
    }

    // Get the maximum for columns.
    for (int i=0; i<M; ++i) {
      int max = -1;
      for (int j=0; j<N; ++j) {
        if (max < lawn[j][i]) {
          max = lawn[j][i];
        }
      }
      maxColumns[i] = max;
    }

    bool result = true;

    for (int i=0; i<N && result; ++i) {
      for (int j=0; j<M; ++j) {
        if (lawn[i][j] != maxLines[i] &&
            lawn[i][j] != maxColumns[j]) {
          result = false;
          break;
        }
      }
    }

    if (result) {
      printf("Case #%d: YES\n", t);
    } else {
      printf("Case #%d: NO\n", t);
    }
  }

  return 0;
}
