#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <vector>
#include <algorithm>
using namespace std;

typedef unsigned long long ull;
typedef long long ll;

ll p, q;
int ans;

ll gcd(ll a, ll b) {
  if (!b)
    return a;
  return gcd(b, a%b);
}

bool is_2pow(ll a) {
  while (a != 1) {
    if (a%2)
      return false;
    a /= 2;
  }
  return true;
}

int main() {
  freopen("test.in", "r", stdin);
  freopen("test.out", "w", stdout);

  int T;
  int cases = 0;
  cin >> T;
  while (T--) {
    scanf("%lld/%lld", &p, &q);
    ll m_gcd = gcd(p, q);
    p /= m_gcd;
    q /= m_gcd;

    bool is_valid = is_2pow(q);
    int cnt = 0;
    while (p < q) {
      if (q%2) {
        is_valid = false;
        break;
      }
      ++cnt;
      q /= 2;
    } 
    cout << "Case #" << ++cases << ": "; 
    if (2*q > p && p%2 == 1 && is_valid) {
      cout << cnt << endl;
    } else {
      cout << "impossible" << endl;
    }

  }
  return 0;
} 
