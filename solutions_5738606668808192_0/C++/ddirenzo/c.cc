#include <iostream>
#include <bitset>
using namespace std;
using ll = long long;
using ld = long double;

ll construct(ll x) {
  ll y = x;
  int i = 0;
  while (y > 0) { ++i; y >>= 1; };
  x = (x<<1) | 1;
  return (x << (15-i)) | x;
}

ll get(ll i, ll k) {
  i = (i << 1) | 1;
  ll n = 0;
  ll x = 1;
  while (i > 0) {
    if (i & 1) {
      n+=x;
    }
    x*=k;
    i>>=1;
  }
  return n;
}

int isprime(int i) {
  for (int k = 2; k*k <= i; ++k) {
    if (i % k == 0) return 0;
  }
  return 1;
}

int main() {
  cout << "Case #1:\n";
  for (int i = 2, cnt = 0; cnt < 50; ++i) {
    if (isprime(i)) continue;
    ll N = construct(i);
    cout << bitset<16>(N) << " ";
    for (int k = 2; k <= 10; ++k) {
      cout << get(i,k) << " ";
    }
    cout << "\n";
    ++cnt;
  }
  return 0;
}
