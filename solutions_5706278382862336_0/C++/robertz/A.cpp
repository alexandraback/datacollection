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

void resolve(ll p, ll q) {
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

