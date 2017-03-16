#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <cassert>
#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <deque>
#include <bitset>
#include <complex>
#include <functional>
#include <numeric>
#include <limits>
#include <utility>

#include <array>
#include <unordered_map>
#include <unordered_set>
#include <tuple>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

const int I = 2, J = 3, K = 4;
const int QT[4][4] = {
  {1, I, J, K},
  {I, -1, K, -J},
  {J, -K, -1, I},
  {K, J, -I, -1}
};

int mul(int x, int y) {
  int s = (x * y) / abs(x * y);
  x = abs(x);
  y = abs(y);
  return s * QT[x - 1][y - 1];
}

const int MAX_L = 11000;

ll L, X;
int a[MAX_L];

ll find_i() {
  set<int> used;
  int v = 1;
  ll p = 0;
  for (;;) {
    if (used.count(v)) return -1;
    used.insert(v);
    if (p >= L * X) return -1;
    for (int i = 0; i < L; i++) {
      v = mul(v, a[i]);
      p++;
      if (v == I) return p;
    }
  }
}

ll find_k() {
  set<int> used;
  int v = 1;
  ll p = L * X - 1;
  for (;;) {
    if (used.count(v)) return  -1;
    used.insert(v);
    if (p < 0) return -1;
    for (int i = L - 1; i >= 0; i--) {
      v = mul(a[i], v);
      p--;
      if (v == K) return p;
    }
  }
}

bool solve() {
  ll pi = find_i();
  ll pk = find_k();
  if (pi == -1 || pk == -1) return false;
  if (pi > pk) return false;
  ll bi = pi / L;
  ll bk = pk / L;
  if (bi == bk) {
    int v = 1;
    for (int i = pi; i <= pk; i++) {
      v = mul(v, a[i % L]);
    }
    return v == J;
  } else {
    int lv = 1;
    for (int i = 0; i < L; i++) {
      lv = mul(lv, a[i]);
    }
    int v = 1;
    for (int i = pi % L; i < L; i++) {
      v = mul(v, a[i]);
    }
    int d = (pk / L) - (pi / L + 1);
    while (d > 0) {
      if (d & 1) v = mul(v, lv);
      lv = mul(lv, lv);
      d >>= 1;
    }
    for (int i = 0; i <= pk % L; i++) {
      v = mul(v, a[i]);
    }
    return v == J;
  }
}


int main() {
  int T;
  cin >> T;
  for (int t = 1; t <= T; t++) {
    cout << "Case #" << t << ": ";
    cin >> L >> X;
    for (int i = 0; i < L; i++) {
      char c;
      cin >> c;
      a[i] = (c - 'i') + 2;
    }
    cout << (solve() ? "YES" : "NO") << endl;
  }
}
