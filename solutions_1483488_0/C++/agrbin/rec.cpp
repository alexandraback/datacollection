#include <cstdio>
#include <cstring>
#include <cstdlib>

const int maxn = 2000001;

int gdim(int x) {
  int dim = 1;
  for (;dim <= x; dim *= 10); dim/=10;
  return dim;
}

int rcirc(int x, int dim) {
  return (x / 10) + (x%10) * dim;
}

int koliko(int a, int b) {
  int dim = gdim(a), sol = 0;
  for (int x = rcirc(a, dim); x != a; x = rcirc(x, dim))
    if (x <= b && x > a)
      ++sol;
  return sol;
}

int solve(int a, int b) {
  int sol = 0;
  for (int j = a; j <= b; ++j)
    sol += koliko(j, b);
  return sol;
}

int main() {
  int casen, a, b;
  scanf("%d", &casen);
  for (int j = 0; j < casen; ++j) {
    scanf("%d%d", &a, &b);
    printf("Case #%d: %d\n", j + 1, solve(a, b));
  }
  return 0;
}
