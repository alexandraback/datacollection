#include<bitset>
#include<stdio.h>

int main(void) {
  size_t T = 0;
  size_t B = 0;
  size_t M = 0;
  scanf("%zu\n", &T);
  for (size_t t = 1; t <= T; t++) {
    scanf("%zu %zu\n", &B, &M);
    std::bitset<64> bits(M);
    if (M > (1 << (B - 2))) {
      printf("Case #%zu: IMPOSSIBLE\n", t);
    } else {
      printf("Case #%zu: POSSIBLE\n", t);

      //handle individual slides
      if (M == (1 << (B-2))) {
        putchar('0');
        for (size_t i = 0; i < B-1; i++) {
          putchar('1');
        }
      } else {
        putchar('0');
        for (size_t i = 0; i < B-2; i++) {
          putchar(bits[B-3-i]? '1' : '0');
        }
        putchar('0');
      }
      putchar('\n');
      
      //draw the "complete" graph
      for (size_t i = 1; i < B; i++) {
        for (size_t j = 0; j < B; j++) {
          if (j > i) {
            putchar('1');
          } else {
            putchar('0');
          }
        }
        putchar('\n');
      }
    }
  }
  return 0;
}
