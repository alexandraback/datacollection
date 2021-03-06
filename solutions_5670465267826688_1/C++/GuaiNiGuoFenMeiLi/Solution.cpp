#include <cstdio>
#include <iostream>
#include <algorithm>

using namespace std;

const int S[4][4] = { {+1, +1, +1, +1}, {+1, -1, +1, -1}, {+1, -1, -1, +1}, {+1, +1, -1, -1} };
const int V[4][4] = { {0, 1, 2, 3}, {1, 0, 3, 2}, {2, 3, 0, 1}, {3, 2, 1, 0} };

struct type {
  int sign, value;
  type() {}
  type(int _sign, int _value): sign(_sign), value(_value) {}
  type operator* (type rhs) {
    return type(sign * rhs.sign * S[value][rhs.value], V[value][rhs.value]);
  }
  bool operator!= (type &rhs) {
    return sign != rhs.sign || value != rhs.value;
  }
  bool operator== (type &rhs) {
    return sign == rhs.sign && value == rhs.value;
  }
  void out() {
    cout << (sign == 1 ? "+" : "-") << value;
  }
};

int ntests, n, m, X[256];
string s;

bool judge() {
  type I(+1, 1);
  type J(+1, 2);
  type K(+1, 3);
  type IJ = I * J;
  type IJK = IJ * K;
  X['i'] = 1;
  X['j'] = 2;
  X['k'] = 3;
  type value(+1, 0);
  for (int i = 0; i < n; ++i) value = value * type(+1, X[s[i % n]]);
  type res(+1, 0);
  for (int i = 0; i < m % 4; ++i) res = res * value;
  if (res != IJK) return false;
  value = type(+1, 0);
  bool flag = false;
  for (int i = 0; i < min(m, 8) * n; ++i) {
    value = value * type(+1, X[s[i % n]]);
    if (!flag && value == I) flag = true;
    if (flag && value == IJ) return true;
  }
  return false;
}

int main() {
  freopen("C-large.in", "r", stdin);
  freopen("C-large.out", "w", stdout);
  cin >> ntests;
  for (int test = 1; test <= ntests; ++test) {
    cin >> n >> m >> s;
    cout << "Case #" << test << ": " << (judge() ? "YES" : "NO") << endl;
  }
  return 0;
}
