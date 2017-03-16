#include <stdio.h>

int solve(int R, int C, int W)
{
  return R * (C/W) + W - (C%W==0);
}

int main(void)
{
  int T, cases;
  scanf("%d", &T);
  for (cases = 1; cases <= T; ++cases) {
    int R, C, W;
    scanf("%d%d%d", &R, &C, &W);
    printf("Case #%d: %d\n", cases, solve(R, C, W));
  }
  return 0;
}
