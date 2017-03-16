#include <stdio.h>

int solve(int X, int R, int C) {
  // R <= C
  if (X > C) return 0;
  if (R*C % X != 0) return 0;
  if (R < X - 1) return 0;
  return 1;
}

int main(void) {
  int N;
  scanf("%d", &N);
  getchar();

  for (int n = 1; n <= N; n++) {
    int X, R, C;
    scanf("%d %d %d", &X, &R, &C);

    if (R > C) {
      int t = R;
      R = C;
      C = t;
    }
    printf("Case #%d: %s\n", n, solve(X,R,C)? "GABRIEL" : "RICHARD");
  }
}
