#include <stdio.h>


typedef long long lnt;


const size_t NMAX = 32;


int main(void) {
  int num_cases;
  scanf("%d", &num_cases);
  
  for (int case_idx = 1; case_idx <= num_cases; ++case_idx) {
    printf("Case #%d:\n", case_idx);

    int n, j;
    scanf("%d %d", &n, &j);

    int num_digits = 2;
    for (int j2 = 1; j2 < j; j2 *= 2, num_digits += 1) {}

    static char s[NMAX + 1];
    for (int i = 0; i < n; ++i) {
      s[i] = '0';
    }
    s[n] = '\0';

    for (int a = (1 << num_digits - 1) + 1, ct = 0; ct < j; ++ct, a += 2) {
      for (int i = 0; i < num_digits; ++i) {
        s[i] = '0' + (a >> num_digits - i - 1 & 1);
        s[n - i - 1] = '0' + (a >> i & 1);
      }
      printf("%s", s);
      for (lnt base = 2; base <= 10; ++base) {
        lnt value = 0;
        for (lnt bn = 1, aa = a; aa > 0; aa >>= 1, bn *= base) {
          value += bn * (aa & 1);
        }
        printf(" %lld", value);
      }
      printf("\n");
    }
  }
  return 0;
}
