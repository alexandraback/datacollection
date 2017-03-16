#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <stdint.h>
#include <cassert>
using namespace std;

#define rep(i, n) for (int i = 0; i < int(n); ++i)

int64_t gcd(const int64_t a, const int64_t b) {
  if (a == 0) {
    return b;
  }
  else {
    return gcd(b % a, a);
  }
}

void solve(int testcaseIndex) {
  int64_t p, q;
  char c;
  cin >> p >> c >> q;

  {
    const int64_t tmp = gcd(p, q);
    p /= tmp;
    q /= tmp;
  }

  int64_t pow = 1ULL << 40;
  {
    const int64_t tmp = gcd(pow, q);
    pow /= tmp;
    q /= tmp;
  }

  const int64_t prod = pow * p;

  cout << "Case #" << (testcaseIndex + 1) << ": ";

  if (prod % q != 0) {
    cout << "impossible" << endl;
    return;
  }

  const int64_t k = prod / q;

  assert(k >= 1);

  for (int i = 40; i >= 0; --i) {
    const int64_t pow2 = 1ULL << i;

    if (k >= pow2) {
      cout << (40 - i) << endl;
      return;
    }
  }
}

int main() {
  int n;
  cin >> n;

  rep(i, n) {
    solve(i);
  }

  return 0;
}
