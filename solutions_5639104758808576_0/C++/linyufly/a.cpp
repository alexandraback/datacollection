#include <cstdio>

const int maxl = 10000;

char str[maxl];
int s_max;

int main() {
  int tt;
  scanf("%d", &tt);
  for (int t = 1; t <= tt; t++) {
    printf("Case #%d: ", t);
    scanf("%d %s", &s_max, str);

    int ans = 0, pop = 0;
    for (int i = 0; i <= s_max; i++) {
      if (pop < i) {
        ans += i - pop;
        pop = i;
      }
      pop += str[i] - '0';
    }
    printf("%d\n", ans);
  }

  return 0;
}

