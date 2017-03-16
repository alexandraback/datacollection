#include <cstdio>
#include <cstring>

long solve(char* str, int len) {
  long nflips = 0;
  for (; len--; ) {
    if ((str[len] == '-' && nflips % 2 == 0) || (str[len] == '+' && nflips % 2 == 1))
      ++nflips;
  }
  return nflips;
}

int main()
{
  long T;
  char str[200];
  scanf("%ld ", &T);
  for (long i = 0; i < T; ++i) {
    scanf("%s ", str);
    printf("Case #%ld: %ld\n", i + 1, solve(str, strlen(str)));
  }
}
