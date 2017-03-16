#include <iostream>
#include <cstdio>
#include <algorithm>

typedef long long int big;

using namespace std;

big divs[11];

big is_prime(big n) {
  if (n == 2) {
    return 0;
  }
  if (n % 2 == 0) {
    return 2;
  }
  for (big d = 3; d * d <= n; d++) {
    if (n % d == 0) {
      return d;
    }
  }
  return 0;
}

big interp(big n, int b) {
  big t = 0, m = 1;
  while (n > 0) {
    t += m * (n % 10);
    n /= 10;
    m *= b;
  }
  return t;
}

int main() {
  int t, n, j;
  cin >> t >> n >> j;
  int max = 1 << n, ji = 0;
  printf("Case #%i:\n", t);
  for (int i = (1 << (n - 1)) + 1; i < 1 << n; i += 2) {
    int b = i;
    big d = 0;
    for (int p = 0; p < n; p++) {
      d = d * 10 + (b % 2);
      b /= 2;
    }
    //printf("%lli\n", d);
    bool jamcoin = true;
    for (int b = 2; b <= 10; b++) {
      big db = interp(d, b);
      divs[b] = is_prime(db);
      jamcoin &= divs[b] > 0;
      //printf("  %i => %lli [%lli]\n", b, db, divs[b]);
    }
    if (jamcoin) {
      printf("%lli", d);
      for (int b = 2; b <= 10; b++) {
        printf(" %lli", divs[b]);
      }
      printf("\n");
      ++ji;
    }
    if (ji >= j) {
      break;
    }
  }
}
