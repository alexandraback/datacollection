#include <iostream>
#include <vector>
using namespace std;

typedef long long ll;

ll gcd(ll a, ll b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}

void solve() {
  ll a, b;
  cin >> a;
  cin.ignore(1);
  cin >> b;
  ll g = gcd(a, b);
  a /= g;
  b /= g;
  if (__builtin_popcount(b) != 1) {
    cout << "impossible" << endl;
    return;
  }
  int k = 0;
  while (a < b) {
    b /= 2;
    ++k;
  }
  cout << k << endl;
}

int main() {
  int t;
  cin >> t;
  for (int z = 0; z < t; ++z) {
    cout << "Case #" << z + 1 << ": ";
    solve();
  }
}