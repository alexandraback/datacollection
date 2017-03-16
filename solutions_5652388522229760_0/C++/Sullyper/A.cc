#include <stdio.h>

bool digit[10];
int nbD = 0;

void reset() { for (int i = 0; i < 10; i++) digit[i] = false; nbD = 0;}

void add(int d) {
  if (d == 0) return;
  if (!digit[d%10]) { digit[d%10] = true; nbD++; }
  add(d/10);
}

int main() {
  int T;
  scanf("%d", &T);
  for (int t = 1; t <= T; t++) {
    int N = t;
    scanf("%d", &N);
    if (N == 0) { printf("Case #%d: INSOMNIA\n", t); continue; }
    int ans = 0;
    reset();
    for (int m = 1; nbD != 10; m++) add(ans = N * m);
    printf("Case #%d: %d\n", t, ans);
  }
  return 0;
}
