#include <stdio.h>

int main() {
  int t, a, b, k, i;
  int x, y, z, m;
  unsigned long total = 0;
  scanf("%u\n", &t);

  for (i = 0; i < t; i++) {
    scanf("%u %u %u\n", &a, &b, &k);

    total = 0;
    for (y = 0; y < a; y++) {
      for (z = 0; z < b; z++) {
        if ((y&z) < k)
          total++;
      }
    }
    printf("Case #%u: %u\n", i+1, total);
  }
}
