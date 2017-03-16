#include <iostream>
#include <string>
#include <set>
#include <vector>
#include <cassert>
using namespace std;

int mult[5][5] = {
  {},
  {0,1,2,3,4},
  {0,2,-1,4,-3},
  {0,3,-4,-1,2},
  {0,4,3,-2,-1},
};

struct Quat {
  int val;
  Quat(int v = 1): val(v) {}

  Quat operator*(const Quat& q) const {
    return mult[abs()][q.abs()] * q.sgn() * sgn();
  }

  Quat& operator*=(const Quat& q) {
    val = mult[abs()][q.abs()] * q.sgn() * sgn();
    return *this;
  }

  Quat operator/(const Quat& q) const {
    return *this * Quat(-q.val);
  }

  Quat pow(int x) const {
    Quat res;
    for (int i = 0; i < x%4; i++) {
      res *= *this;
    }
    return res;
  }

  long long sgn() const {
    return val < 0 ? -1 : 1;
  }

  int abs() const {
    return val * sgn();
  }

  Quat inv() const {
    return Quat(1) / *this;
  }

  static Quat fromChar(char c) {
    switch (c) {
      case '1': return Quat(1);
      case 'i': return Quat(2);
      case 'j': return Quat(3);
      case 'k': return Quat(4);
    }
    throw "wut";
  }

  bool operator<(const Quat& q) const {
    return val < q.val;
  }

  bool operator==(const Quat& q) const {
    return val == q.val;
  }

  bool operator!=(const Quat& q) const {
    return val != q.val;
  }
};

ostream& operator<<(ostream& out, const Quat& q) {
  if (q.sgn() == -1) {
    out << "-";
  }
  switch (q.abs()) {
    case 1: out << "1"; break;
    case 2: out << "i"; break;
    case 3: out << "j"; break;
    case 4: out << "k"; break;
  }
  return out;
}

namespace Quats {
  Quat one(1);
  Quat i(2);
  Quat j(3);
  Quat k(4);
};

bool solve3(Quat t, Quat x, Quat y, Quat z, long long s) {
  for (int i = 0; i < 4; i++) {
    if (t.pow(i) != x) continue;
    for (int j = 0; j < 4; j++) {
      if (t.pow(j) != y) continue;
      for (int k = 0; k < 4; k++) {
        if (t.pow(k) == z && i+j+k <= s && (s-i-j-k)%4 == 0) {
          return true;
        }
      }
    }
  }
  return false;
}

bool solve2(Quat t, Quat x, Quat y, long long s) {
  for (int i = 0; i < 4; i++) {
    if (t.pow(i) != x) continue;
    for (int j = 0; j < 4; j++) {
      if (t.pow(j) == y && i+j <= s && (s-i-j)%4 == 0) {
        return true;
      }
    }
  }
  return false;
}

// t^a = i/x, t^b = (t^-1)*x*j/y, t^c = (t^-1)*y*k
// where a >= 0, b >= 0, c >= 0, a + b + c = s
bool solvable1(Quat t, Quat x, Quat y, long long s) {
  return solve3(
    t,
    Quats::i / x,
    t.inv() * x * Quats::j / y,
    t.inv() * y * Quats::k,
    s
  );
}

// t^a = i*(x^-1), t^b = (y^-1)*k
// where a + b = s
bool solvable2(Quat t, Quat x, Quat y, long long s) {
  return solve2(
    t,
    Quats::i / x,
    y.inv() * Quats::k,
    s
  );
}

// t^a = i, t^b = j*(x^-1), t^c = (y^-1)*k
// a + b + c = s
bool solvable3(Quat t, Quat x, Quat y, long long s) {
  for (int i = 1; i <= min(s, 4LL); i++) {
    if (t.pow(i) == Quats::i) {
      return solve2(t, Quats::j / x, y.inv() * Quats::k, s-i);
    }
  }
  return false;
}

// t^a = i*(x^-1), t^b = (y^-1)*j, t^c = k
// a + b + c = s
bool solvable4(Quat t, Quat x, Quat y, long long s) {
  for (int i = 1; i <= min(s, 4LL); i++) {
    if (t.pow(i) == Quats::k) {
      return solve2(t, Quats::i / x, y.inv() * Quats::j, s-i);
    }
  }
  return false;
}

bool ok2(string s) {
  Quat all;
  for (int i = 0; i < s.size(); i++) {
    all *= Quat::fromChar(s[i]);
  }
  if (all != Quats::i*Quats::j*Quats::k) {
    return false;
  }

  // case 1: 3 distinct chunks
  Quat prod1(1);
  multiset<Quat> prefixSet;
  vector<Quat> prefixes(s.size());
  for (int i = 0; i+2 < s.size(); i++) {
    prod1 *= Quat::fromChar(s[i]);
    prefixes[i] = prod1;
    prefixSet.insert(prod1);
  }
  prod1 = Quat(1);
  for (int i = s.size()-1; i >= 2; i--) {
    prod1 = Quat::fromChar(s[i]) * prod1;
    if (prod1 != Quats::k) continue;
    // x * j * prod1 == all
    // -> x == all * (prod1^-1) * (j^-1)
    Quat look = all / prod1 / Quats::j;
    if (prefixSet.count(look)) {
      return true;
    }
    prefixSet.erase(prefixSet.find(prefixes[i-2]));
  }
  return false;
}

bool ok(string s, long long X) {
  if (X > 20) {
    X = 20 + X%4;
  }

  string t;
  for (int i = 0; i < X; i++) {
    t += s;
  }

  return ok2(t);

  Quat all;
  for (int i = 0; i < s.size(); i++) {
    all *= Quat::fromChar(s[i]);
  }

  // case 1: 3 distinct chunks
  Quat prod1(1);
  multiset<Quat> prefixSet;
  vector<Quat> prefixes(s.size());
  for (int i = 0; i+2 < s.size(); i++) {
    prod1 *= Quat::fromChar(s[i]);
    prefixes[i] = prod1;
    prefixSet.insert(prod1);
  }
  prod1 = Quat(1);
  for (int i = s.size()-1; i >= 2; i--) {
    prod1 *= Quat::fromChar(s[i]);
    // x * j * prod1 == all
    // -> x == all * (prod1^-1) * (j^-1)
    Quat look = all / prod1 / Quats::j;
    if (prefixSet.count(look)) {
      if (solvable2(all, look, prod1, X-1)) {
        return true;
      }
    }
    prefixSet.erase(prefixSet.find(prefixes[i-2]));
  }

  // case 2: separate & split
  set<Quat> possible;
  prod1 = Quat(1);
  for (int i = 1; i < s.size(); i++) {
    prod1 *= Quat::fromChar(s[i-1]);
    possible.insert(prod1);
  }
  for (auto si : possible) {
    for (auto sj : possible) {
      if (solvable1(all, si, sj, X-2)) {
        return true;
      }
    }
  }

  // case 3/4: one split, but either side
  for (auto si : possible) {
    auto other = si.inv() * all;
    if (solvable3(all, si, other, X-1) ||
        solvable4(all, si, other, X-1)) {
      return true;
    }
  }

  return false;
}

int main() {
  int T; cin >> T;

  for (int t = 1; t <= T; t++) {
    int L;
    long long X;
    cin >> L >> X;
    string s; cin >> s;

    printf("Case #%d: %s\n", t, ok(s, X) ? "YES" : "NO");
  }
}
