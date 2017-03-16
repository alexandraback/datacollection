#include "cmath"
#include "cstdio"
#include "iostream"
#include "sstream"
#include "algorithm"
#include "map"
#include "numeric"
#include "queue"
#include "set"
#include "string"
#include "utility"
#include "vector"

using namespace std;

typedef long long i64;

int first_div(i64 n) {
  i64 m = (i64)sqrt(n);
  for (i64 d = 3; d <= m; d += 2)
    if (n % d == 0)
      return d;
  return 1;
}

void solve(int n, int j) {
  i64 min = (1LL << (n - 1)) + 1; 
  i64 max = 1LL << n; 
  for (i64 i = min; i < max; i += 2) {
    //fprintf(stderr, "i = %lld\n", i);
    ostringstream s;
    bool ok = true;
    i64 display = 0;
    for (int b = 2; b <= 10; b++) {
      i64 cur = i, bb = 1, n = 0;
      while (cur > 0) {
        if (cur % 2 == 1)
          n += bb;
        cur >>= 1;
        bb *= b;
      }
      if (b == 10)
        display = n;
      int d = first_div(n);
      if (d == 1) {
        ok = false;
        break;
      }
      s << " " << d;
    }
    if (ok) {
      printf("%lld%s\n", display, s.str().c_str());
      if (--j == 0)
        break;
    }
  }
}

int main() {
  int T;
  scanf("%d", &T);
  for (int Ti = 1; Ti <= T; ++Ti) {
    fprintf(stderr, "Case #%d of %d...\n", Ti, T);
    int n, j;
    scanf("%d %d", &n, &j);
    printf("Case #%d: \n", Ti);
    solve(n, j);
  }
  return 0;
}
