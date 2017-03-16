#include <stdio.h>

#include <vector>


using std::vector;


typedef long long lnt;


int main(void) {
  int num_cases;
  scanf("%d", &num_cases);
  for (int case_idx = 1; case_idx <= num_cases; ++case_idx) {
    lnt n;
    scanf("%lld", &n);

    if (n == 0) {
      printf("Case #%d: INSOMNIA\n", case_idx);
      continue;
    }

    vector<bool> exists(10, false);
    int num_zero = 10;
    lnt last_num = n;

    for (int i = 1; num_zero > 0; ++i) {
      for (lnt m = last_num = n * i; m > 0; m /= 10) {
        if (exists[m % 10] == false) {
          num_zero -= 1;
          exists[m % 10] = true;
        }
      }
    }

    printf("Case #%d: %lld\n", case_idx, last_num);
  }
  return 0;
}
