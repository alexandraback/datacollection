#include <cstdio>

int main()
{
  int T;
  scanf("%d\n", &T);
  for (int I = 1; I <= T; I++) {
    int previous = 0;
    int change = 0;
    int ch;
    while((ch = getchar()) != '\n') {
      if (previous != 0 && ch != previous) {
        change++;
      }
      previous = ch;
    }
    if (previous == '-') {
      ++change;
    }

    printf("Case #%d: %d\n", I, change);
  }

  return 0;
}
