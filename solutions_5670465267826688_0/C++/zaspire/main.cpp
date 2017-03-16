#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <cassert>
#include <vector>
#include <cstdlib>
#include <numeric>
#include <sstream>
#include <iostream>
#include <cstdlib>
#include <algorithm>
using namespace std;

enum QType {
  K_1,
  K_I,
  K_J,
  K_K
};

auto k1 = make_pair(K_1, false);
auto kI = make_pair(K_I, false);
auto kK = make_pair(K_K, false);
auto kJ = make_pair(K_J, false);

pair<QType, bool> FromChar(char c) {
  QType t;
  switch(c) {
  case 'i':
    t = K_I;
    break;
  case 'j':
    t = K_J;
    break;
  case 'k':
    t = K_K;
    break;
  default:
    assert(false);
  }
  return make_pair(t, false); // false = +
}

pair<QType, bool> Mul(const pair<QType, bool> &p1, const pair<QType, bool> &p2) {
  QType t;
  bool sign = p1.second ^ p2.second;
  switch (p1.first) {
  case K_1:
    switch (p2.first) {
    case K_1:
      t = K_1;
      break;
    case K_I:
      t = K_I;
      break;
    case K_J:
      t = K_J;
      break;
    case K_K:
      t = K_K;
      break;
    }
    break;
  case K_I:
    switch (p2.first) {
    case K_1:
      t = K_I;
      break;
    case K_I:
      sign = sign ^ true;
      t = K_1;
      break;
    case K_J:
      t = K_K;
      break;
    case K_K:
      sign = sign ^ true;
      t = K_J;
      break;
    }
    break;
  case K_J:
    switch (p2.first) {
    case K_1:
      t = K_J;
      break;
    case K_I:
      sign = sign ^ true;
      t = K_K;
      break;
    case K_J:
      t = K_1;
      sign = sign ^ true;
      break;
    case K_K:
      t = K_I;
      break;
    }
    break;
  case K_K:
    switch (p2.first) {
    case K_1:
      t = K_K;
      break;
    case K_I:
      t = K_J;
      break;
    case K_J:
      t = K_I;
      sign = sign ^ true;
      break;
    case K_K:
      t = K_1;
      sign = sign ^ true;
      break;
    }
    break;
  }
  return make_pair(t, sign);
}

pair<QType, bool> Pow(const pair<QType, bool> &p1, int X) {
  if (X == 0)
    return make_pair(K_1, false);
  if (X == 1)
    return p1;
  assert(X > 1);
  auto a = Pow(p1, X / 2);
  a = Mul(a, a);
  if (X % 2)
    a = Mul(a, p1);
  return a;
}

bool Solve(const string &str, int X) {
  auto m = make_pair(K_1, false);
  for (int i = 0; i < str.size(); i++) {
    m = Mul(m, FromChar(str[i]));
  }
  if (Pow(m, X) != make_pair(K_1, true))
    return false;

  vector<pair<QType, bool>> prefixes{k1, m, Mul(m, m), Mul(Mul(m, m), m)};

  int ind_i = INT32_MAX;
  auto tm = make_pair(K_1, false);
  for (int i = 0; i < str.size(); i++) {
    tm = Mul(tm, FromChar(str[i]));
    for (int k = 0; k < prefixes.size(); k++) {
      if (Mul(prefixes[k], tm) == kI) {
        ind_i = min((int)(k * str.size() + i), ind_i);
      }
    }
  }
  if (ind_i >= X * str.size())
    return false;
  int ind_k = INT32_MAX;
  tm = make_pair(K_1, false);
  for (int i = str.size() - 1; i >= 0; i--) {
    tm = Mul(FromChar(str[i]), tm);
    for (int k = 0; k < prefixes.size(); k++) {
      if (Mul(tm, prefixes[k]) == kK) {
        ind_k = min((int)(k * str.size() + (str.size() - i)), ind_k);
      }
    }
  }
  if (ind_k >= X * str.size())
    return false;
  ind_k = X * str.size() - ind_k;
  if (ind_k <= ind_i)
    return false;

  return true;
}

pair<QType, bool> MulS(const string &s) {
  pair<QType, bool> a = k1;
  for (int i = 0; i < s.size(); i++) {
    a = Mul(a, FromChar(s[i]));
  }
  return a;
}

bool NaiveSolve(const string &s) {
  for (int i = 0; i < s.size(); i++) {
    for (int k = i + 1; k < s.size() - 1; k++) {
      if (MulS(s.substr(0, i)) == kI && MulS(s.substr(i, k - i)) == kJ && MulS(s.substr(k)) == kK)
        return true;
    }
  }
  return false;
}

void FuzzyTest() {
  for (int i = 0; i < 100; i++) {
    string t;
    for (int k = 0; k < 100; k++) {
      char c;
      switch(rand() % 3) {
      case 0:
        c = 'i';
        break;
      case 1:
        c = 'k';
        break;
      case 2:
        c = 'j';
        break;
      }
      t.push_back(c);
    }
    if (NaiveSolve(t) == Solve(t, 1))
      cout << "+";
    else {
      cout << endl << t << endl;
      cout << NaiveSolve(t) << Solve(t, 1) << endl;
    }
  }
  cout << endl;
}

int main(void) {
  //FuzzyTest();
  //return 0;
  int T;
  cin >> T;
  for (int TT = 0; TT < T; TT++) {
    int L, X;
    string str;
    cin >> L >> X >> str;

    string ans;
    if (Solve(str, X))
      ans = "YES";
    else
      ans = "NO";
    cout << "Case #" << TT + 1 << ": " << ans << endl;
  }
  return 0;
}
