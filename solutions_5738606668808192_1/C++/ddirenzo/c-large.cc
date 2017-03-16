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
  return (x << (31-i)) | x;
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

int main() {
  cout << "Case #1:\n";
  for (int i = 1, cnt = 0; cnt < 500; ++i) {
    ll N = construct(i);
    cout << bitset<32>(N) << " ";
    for (int k = 2; k <= 10; ++k) {
      cout << get(i,k) << " ";
    }
    cout << "\n";
    ++cnt;
  }
  return 0;
}
