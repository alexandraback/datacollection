#include <stdio.h>

int main(void) {
  int N;
  scanf("%d", &N);
  getchar();

  char shyness[1000];
  int nshyness;

  for (int n = 1; n <= N; n++) {
    scanf("%d %s", &nshyness, shyness);

    int nstanding = 0,
        max       = -1;
    for (int i = 0; i <= nshyness; i++) {
      int v = shyness[i] - '0';
      if (v > 0) {
        // Need additional  i - nstanding
        int delta = i - nstanding;
        if (delta > max) max = delta;
      }
      nstanding += v;
    }

    printf("Case #%d: %d\n", n, max);
  }
}
