#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <iostream>
#include <cmath>
#include <sstream>
#include <map>
#include <set>
#include <numeric>
#include <memory.h>
#include <cstdio>
#include <assert.h>

using namespace std;

/*** TEMPLATE CODE ENDS HERE */

char M[128][128];
int S[128][128];

struct Quaternion {
  char c;
  int sgn;
  Quaternion() : Quaternion('1') {}
  Quaternion(char c, int sgn = 1) : c(c), sgn(sgn) {}
  Quaternion operator*(const Quaternion &a) const {
    return Quaternion(M[c][a.c], sgn * S[c][a.c] * a.sgn);
  }
  bool operator==(const Quaternion &a) const {
    return c == a.c && sgn == a.sgn;
  }
  bool operator!=(const Quaternion &a) const { return !(*this == a); }
};

Quaternion preffix[10010];
Quaternion suffix[10010];

bool solve() {
  int L, X;
  cin >> L >> X;
  string s;
  cin >> s;
  int n = (int)s.size();
  if (n == 1) return false;

  {
    vector<string> cp(X, s);
    s = accumulate(cp.begin(), cp.end(), string(""));
    n = (int)s.size();
  }

  if (n < 3) return false;

  preffix[0] = Quaternion('1');
  for (int i = 0; i < n; ++i) {
    preffix[i + 1] = preffix[i] * Quaternion(s[i], 1);
  }

  suffix[n] = Quaternion('1');
  for (int i = n - 1; i >= 0; --i) {
    suffix[i] = Quaternion(s[i], 1) * suffix[i + 1];
  }

  for (int i = 1; i < n; ++i) {
    Quaternion center('1');
    for (int j = i; j + 1 < n; ++j) {
      center = center * Quaternion(s[j]);
      Quaternion left = preffix[i];
      Quaternion right = suffix[j + 1];
      if (left.c == 'i' && center.c == 'j' && right.c == 'k') {
        int sgn = left.sgn * center.sgn * right.sgn;
        if (sgn == 1) return true;
      }
    }
  }

  return false;
}

int main() {
#ifdef LOCAL_HOST
  freopen("C-small-attempt3.in", "r", stdin);
  //  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif

  ios_base::sync_with_stdio(false);
  // init M and S
  {
    const string s1 = "1ijk";
    const string s2 = "ijk";

    for (char c1 : s1) {
      for (char c2 : s1) {
        if (c1 == '1' || c2 == '1') {
          M[c1][c2] = c1 == '1' ? c2 : c1;
          S[c1][c2] = 1;
        } else if (c1 == c2) {
          M[c1][c1] = '1';
          S[c1][c1] = -1;
        } else {
          for (char t : s2) {
            if (t != c1 && t != c2) {
              M[c1][c2] = t;
              int inv = (c1 > c2) + (c1 > t) + (c2 > t);
              S[c1][c2] = inv % 2 ? -1 : 1;
              break;
            }
          }
        }
      }
    }
  }

  string str[2] = {"NO", "YES"};

  int N;
  cin >> N;
  for (int n = 1; n <= N; ++n) {
    bool ans = solve();
    cout << "Case #" << n << ": " << str[ans] << endl;
  }

  return 0;
}
