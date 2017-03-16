#define NDEBUG
#include <cassert>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <string>
#include <tuple>
using namespace std;

typedef long long int64;

struct Q {
  explicit Q(char ch) {
    sign = 1;
    if (ch == '1') {
      val = 0;
    } else {
      assert(ch >= 'i' && ch <= 'k');
      val = ch - 'i' + 1;
    }
  }

  friend Q operator*(const Q q1, const Q q2) {
    static const char mat[4][5] = {
      "1ijk",
      "i1kj",
      "jk1i",
      "kji1",
    };
    static const char neg[4][5] = {
      "0000",
      "0101",
      "0110",
      "0011",
    };
    Q res(mat[q1.val][q2.val]);
    res.sign = q1.sign * q2.sign;
    if (neg[q1.val][q2.val] == '1') {
      res.sign = -res.sign;
    }
    return res;
  }

  friend bool operator==(const Q q1, const Q q2) {
    return tie(q1.sign, q1.val) == tie(q2.sign, q2.val);
  }
  friend bool operator!=(const Q q1, const Q q2) {
    return tie(q1.sign, q1.val) != tie(q2.sign, q2.val);
  }

  int sign;
  int val;
};

string dbgstr(Q q) {
  return (q.sign == -1 ? "-" : "") + string(1, "1ijk"[q.val]);
}

Q pow(Q a, int64 n) {
  if (n == 0) {
    return Q('1');
  }
  if (n % 2 == 1) {
    return a * pow(a, n-1);
  }
  return pow(a*a, n/2);
}

bool solve(int64 L, int64 X, const string& rep) {
  int64 N = L * X;
  auto get = [&](int64 pos) {
    assert(0 <= pos && pos < N);
    return Q(rep[pos % rep.size()]);
  };
  auto getchunk = [&](int64 a, int64 b) {
    assert(a <= b);
    Q q('1');
    for (int64 i = a; i < b; ++i) {
      q = q * get(i);
    }
    return q;
  };

  int64 left = 0, right = N-1;
  {
    Q q('1'), target('i');
    for (int64 i = 0; i < 8*L && left <= right; ++i, ++left) {
      if (q == target) {
        break;
      }
      q = q * get(left);
      // debug(q);
    }
    if (q != target) {
      return false;
    }
  }

  {
    Q q('1'), target('k');
    for (int64 i = 0; i < 8*L && left <= right; ++i, --right) {
      if (q == target) {
        break;
      }
      q = get(right) * q;
      // debug(q);
    }
    if (q != target) {
      return false;
    }
  }

  // Je li [left, right] == j?
  if (left > right) {
    return false;
  }

  int64 nfull = (right - left + 1) / rep.size();
  Q qqq('1');
  if (nfull > 0) {
    qqq = pow(getchunk(left, left + rep.size()), nfull);
  }
  Q mid = qqq * getchunk(left + nfull * rep.size(), right + 1);
  return mid == Q('j');
}

int main() {
  ios_base::sync_with_stdio(0);

  int T;
  cin >> T;
  for (int tt=1; tt<=T; ++tt) {
    int64 L, X;
    string rep;
    cin >> L >> X >> rep;
    printf("Case #%d: %s\n", tt, solve(L, X, rep) ? "YES" : "NO");
  }
}
