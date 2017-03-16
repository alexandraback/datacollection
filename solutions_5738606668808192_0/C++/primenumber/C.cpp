#include <bits/stdc++.h>

#define REP(i,n)    for(int i=0;i<(n);++i)

using namespace std;

uint64_t fac(int base, const bitset<32>& bs, int n) {
  for (int i = 2; i < 10000; ++i) {
    uint64_t rem = 0;
    uint64_t pow = 1;
    for (int j = 0; j < n; ++j) {
      if (bs[j]) {
        rem += pow;
        rem %= i;
      }
      pow *= base;
      pow %= i;
    }
    if (rem == 0) return i;
  }
  return 0;
}

int main() {
  int t;
  cin>>t;
  int n, j;
  cin>>n>>j;
  cout << "Case #1:" << endl;
  int cnt = 0;
  for (uint32_t bits = 1ul << (n-1) | 1; cnt < j; bits += 2) {
    bitset<32> bs(bits);
    bool ok = true;
    array<uint64_t, 9> divisors;
    for (int i = 2; i <= 10; ++i) {
      uint64_t divisor = fac(i, bs, n);
      if (divisor == 0) {
        ok = false;
        break;
      }
      divisors[i-2] = divisor;
    }
    if (ok) {
      REP(i, n) cout << bs[n-i-1];
      for (uint64_t divisor : divisors) {
        cout << ' ' << divisor;
      }
      cout << endl;
      ++cnt;
    }
  }
  return 0;
}
