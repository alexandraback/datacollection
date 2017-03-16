#include <stdio.h>
#include <string.h>


const size_t SMAX = 100;


int main(void) {
  int num_cases;
  scanf("%d", &num_cases);

  for (int case_idx = 1; case_idx <= num_cases; ++case_idx) {
    static char states[SMAX + 1];
    scanf("%s", states);

    int ans = 0;
    char* last = states + strlen(states) - 1;

    while (true) {
      while (states <= last && *last == '+') --last;
      if (last < states) break;
      for (char* ptr = states; ptr <= last; ++ptr) *ptr = '+' + '-' - *ptr;
      ++ans;
    }
    printf("Case #%d: %d\n", case_idx, ans);
  }
  return 0;
}
