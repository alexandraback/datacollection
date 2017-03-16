#include <stdio.h>

int E, R, N, v[99], max;

void solve(int now, int energy, int gain) {
  if (now == N || !energy) {
    if (gain > max) max = gain;
    return;
  }
  int i;
  for (i = 0; i <= energy; i++)
    solve(now + 1, energy - i + R > E ? E : energy - i + R, gain + i * v[now]);
}

int main() {
  int T, C = 1;
  scanf("%d", &T);
  while (T--) {
    scanf("%d%d%d", &E, &R, &N);
    int i;
    for (i = 0; i < N; i++)
      scanf("%d", &v[i]);
    max = 0;
    solve(0, E, 0);
    printf("Case #%d: %d\n", C++, max);
  }
  return 0;
}
