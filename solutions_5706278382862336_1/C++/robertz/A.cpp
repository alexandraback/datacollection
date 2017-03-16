#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <utility>
#include <algorithm>
#include <cmath>
#include <climits>
#include <cassert>

using namespace std;

typedef unsigned int uint;
typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;

vector<ll> g_exp2;

inline void prepare() {
  g_exp2.reserve(41);
  ll n = 1;
  for (int i = 0; i <= 40; i++) {
    g_exp2.push_back(n);
    n *= 2;
  }
}

inline int foo(ll q) {
  for (int i = 0; i <= 40; i++) {
    if (g_exp2[i] == q) {
      return i;
    }
  }
  return -1;
}

inline ll gcd(ll a, ll b)
{
  while(b != 0)
  {
    ll r = b;
    b = a % b;
    a = r;
  }
  return a;
}

inline void bar(ll & p, ll & q) {
  ll g = gcd(p, q);
  p /= g;
  q /= g;
}

void resolve(ll p, ll q) {
  bar(p, q);
  int n = foo(q);
  if (n == -1) {
    cout << "impossible";
    return;
  }
  int t = 0;
  while (p / 2) {
    t++;
    p /= 2;
  }
  n -= t;
  cout << n;
}

int main() {
  prepare();
  int T;
  cin >> T;
  for (int t = 1; t <= T; t++) {
    clog << t << endl;
    ll p, q;
    char sep;
    cin >> p >> sep >> q;
    cout << "Case #" << t << ": ";
    resolve(p, q);
    cout << endl;
  }
  return 0;
}

