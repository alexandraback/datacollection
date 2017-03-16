#include <stdio.h>

int main() {
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  int test;
  scanf("%d", &test);
  for(int t=1; t<=test; ++t) {
    int R, C, N, W;
    scanf("%d %d %d", &R, &C, &W);
    N = R*C;
    printf("Case #%d: %d\n", t, (N-1)/W + W);
  }
  return 0;
}