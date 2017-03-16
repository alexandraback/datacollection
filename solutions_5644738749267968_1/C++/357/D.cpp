#include <stdio.h>

int n;
double a[1001], b[1001];

int main(int argc, char* argv[]) {
  freopen("D-small-attempt0.in", "r", stdin);
  freopen("output.txt", "w", stdout);
  int T;
  scanf("%d", &T);
  for (int o = 1; o <= T; ++o) {
    printf("Case #%d: ", o);

    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
      scanf("%lf", &a[i]);
    double t;
    for (int i = 1; i < n; ++i)
      for (int j = 1; j <= n-i; ++j)
        if (a[j] > a[j+1])
          t = a[j], a[j] = a[j+1], a[j+1] = t;
    for (int i = 1; i <= n; ++i)
      scanf("%lf", &b[i]);
    for (int i = 1; i < n; ++i)
      for (int j = 1; j <= n-i; ++j)
        if (b[j] > b[j+1])
          t = b[j], b[j] = b[j+1], b[j+1] = t;

    int x, y = 1, ans = 0;
    for (x = 1; x <= n; ++x)
      if (a[x] > b[y])
        ++ans, ++y;
    printf("%d ", ans);
    ans = n; y = 1;
    for (x = 1; x <= n; ++x)
      if (b[x] > a[y])
        --ans, ++y;
    printf("%d\n", ans);
  }
  return 0;
}
