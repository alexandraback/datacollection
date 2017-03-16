#include <math.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

int main() {
  int num_tests = 0;
  scanf("%d", &num_tests);
  for (int test = 1; test <= num_tests; ++test) {
    unsigned long long r, t, x;
    scanf("%llu%llu", &r, &t);
    //printf("DEBUG r=%llu t=%llu\n", r, t);
    int k = 0;
    while (true) {
      x = (r + r + 1);
      r += 2;
      if (t < x)
        break;
      t -= x;
      ++k;
      //printf("DEBUG r=%llu t=%llu k=%u\n", r, t, k);
    }
    printf("Case #%d: %d\n", test, k);
  }
  return 0;
}
