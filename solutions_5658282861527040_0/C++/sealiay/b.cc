
#include <cstdio>

int p() {
  int a, b, c;
  scanf("%d%d%d", &a, &b, &c);
  int w = 0;
  for (int i = 0; i < a; ++i)
    for (int j = 0; j < b; ++j)
      if ( (i & j) < c ) ++w;
  return w;
}

int main() {
  int t;
  scanf("%d", &t);
  for (int i = 1; i <= t; ++i)
    printf("Case #%d: %d\n", i, p());
  return 0;
}
