#include <ctype.h>
#include <stdio.h>

const char *transf = "ynficwlbkuomxsevzpdrjgthaq";

char line[1000];

int main() {
  int T;
  scanf("%d", &T);
  gets(line);
  for (int i = 1; i <= T; ++i) {
    gets(line);
    printf("Case #%d: ", i);
    for (const char *p = line; *p; ++p) {
      if (isalpha(*p)) {
        for (int j = 0; j < 26; ++j)
          if (transf[j] == *p) putchar(j + 'a');
      } else {
        putchar(*p);
      }
    }
    puts("");
  }
  return 0;
}
