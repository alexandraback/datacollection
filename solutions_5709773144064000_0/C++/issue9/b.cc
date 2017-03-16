#include <cstdio>

long double c, f, x, b;

int main(int argc, char const *argv[]) {
  int tc;
  scanf("%d", &tc);
  for (int ti = 1; ti <= tc; ++ti) {
    scanf("%Lf%Lf%Lf", &c, &f, &x);
    long double a = 0, s = 2, t; // curr time, curr speed
    b = x / s; // best
    fprintf(stderr, "  %Lf\n", b);
    while (a < b) {
      a += c / s;
      s += f;
      t = a + x / s;
      if (t < b) b = t;
    }
    printf("Case #%d: %.8Lf\n", ti, b);
  }
  return 0;
}
