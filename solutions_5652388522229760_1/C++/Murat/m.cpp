#include <bits/stdc++.h>

using namespace std;

template<class T> inline T sqr(const T& a) {
  return a * a;
}

template<class T> inline T middle(const T &a, const T &b) {
  return (a + b) / 2;
}

template<class T> inline int len(const T &c) {
  return static_cast<int>(c.size());
}

typedef long long li;
typedef long double ld;
typedef pair<int, int> pt;

const ld EPS = 1e-9;
const ld PI = 2 * acos(0.0);
const int N = 100;

void HandleCase() {
  int n;
  scanf("%d", &n);
  if (n == 0) {
    puts("INSOMNIA");
    return;
  }
  int seen = 0;
  const int goal = ((1 << 10) - 1);
  for (li m = 1; m < 1e9; ++m) {
    li x = n * m;
    while (x) {
      int d = (int) (x % 10);
      x /= 10;
      seen |= 1 << d;
    }
    if (seen == goal) {
      printf("%lld\n", n * m);
      return;
    }
  }
  fprintf(stderr, "not found for n %d\n", n);
  throw 1;
}

int main() {
  int tests;
  scanf("%d", &tests);
  for (int test = 1; test <= tests; ++test) {
    printf("Case #%d: ", test);
    HandleCase();
  }
  return 0;
}
