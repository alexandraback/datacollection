#pragma comment(linker, "/STACK:46777216")

#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <queue>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <sstream>
#include <algorithm>
#include <memory.h>
#include <cmath>

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned char byte;
typedef pair<int, int> pii;
#define forn(i,n) for (ll i = 0; i < ll(n); ++i)
#define mp make_pair

bool check(ll v) {
  int d[256];
  int c = 0;
  while (v) { d[c++] = v % 10; v /= 10; }
  forn (i, c / 2) if (d[i] != d[c - 1 - i]) return false;
  return true;
}

ll sqrt(ll v) {
  ll l = 0, r = std::min(v, 1000000000LL);
  while (l != r) {
    ll x = (l + r) / 2;
    if (x * x >= v) r = x;
    else l = x + 1;
  }
  if (l * l > v) --l;
  return l;
}

int data[20000000];

int main() {
  data[0] = 1;
  forn (i, 20000000) {
    if (i == 0) continue;
    data[i] = data[i - 1];
    if (!check(i)) continue;
    if (!check(i * i)) continue;
    ++data[i];
  }

  int T;
  cin >> T;
  forn (_, T) {
    cout << "Case #" << (_ + 1) << ": ";
    ll a, b; cin >> a >> b;
    b = sqrt(b);
    a = sqrt(a - 1);
    cout << data[b] - data[a];

    cout << endl;
  }


  return 0;
}