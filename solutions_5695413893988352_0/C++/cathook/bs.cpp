#include <stdio.h>
#include <stdlib.h>
#include <string.h>


bool check(int k, int n, const char* s) {
  for (int i = n - 1; i >= 0; --i, k /= 10) {
    if (s[i] != '?' && s[i] - '0' != k % 10) {
      return false;
    }
  }
  return true;
}


int main(void) {
  int num_cases;
  scanf("%d", &num_cases);

  for (int case_idx = 1; case_idx <= num_cases; ++case_idx) {
    static char s1[5], s2[5];
    scanf("%s %s", s1, s2);
    
    int n = strlen(s1);

    int max = 1;
    for (int i = 0; i < n; ++i) {
      max *= 10;
    }

    int ii = -1, jj;
    for (int i = 0; i < max; ++i) {
      if (check(i, n, s1)) {
        for (int j = 0; j < max; ++j) {
          if (check(j, n, s2)) {
            if (ii == -1 ||
                abs(ii - jj) > abs(i - j) ||
                abs(ii - jj) == abs(i - j) && i < ii ||
                abs(ii - jj) == abs(i - j) && i == ii && j < jj) {
              ii = i;
              jj = j;
            }
          }
        }
      }
    }

    static char fmt[1000];
    sprintf(fmt, "Case #%%d: %%0%dd %%0%dd\n", n, n);
    printf(fmt, case_idx, ii, jj);
  }

  return 0;
}
