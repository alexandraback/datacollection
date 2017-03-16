#include <cstdio>


int main(void) {
  char str[104];
  int T;
  scanf("%d", &T);

  for (int t = 1; t <= T; ++t) {
    scanf("%s", str);

    int k = 0;
    char last = 0;
    for (int i = 0; str[i]; ++i) {
      if (str[i] != last) {
        last = str[i];
        ++k;
      }
    }

    int result = last == '-' ? k : k - 1;
    printf("Case #%d: %d\n", t, result);
  }

  return 0;
}
