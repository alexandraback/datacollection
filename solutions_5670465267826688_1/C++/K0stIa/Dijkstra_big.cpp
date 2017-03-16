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
  int L;
  long long X;
  cin >> L >> X;
  string s;
  cin >> s;
  const int n = (int)s.size();
  if (n == 1) return false;

  preffix[0] = Quaternion('1');
  for (int i = 0; i < n; ++i) {
    preffix[i + 1] = preffix[i] * Quaternion(s[i], 1);
  }

  suffix[n] = Quaternion('1');
  for (int i = n - 1; i >= 0; --i) {
    suffix[i] = Quaternion(s[i], 1) * suffix[i + 1];
  }

  Quaternion cycle[] = {Quaternion('1'), suffix[0]};

  int period = 1;
  {
    Quaternion el = cycle[1];
    Quaternion one('1');
    while (el != one) {
      el = el * cycle[1];
      period++;
    }
  }

  for (int i = 0; i < n; ++i) {
    Quaternion line('1', 1);
    for (int j = 0; j < n; ++j) {
      if (i <= j) {
        line = line * Quaternion(s[j]);
      }
      for (int l = 0; l <= 1; ++l) {
        for (int r = 0; r <= 1; ++r) {
          for (int c = 0; c <= 1; ++c) {
            Quaternion left = cycle[l] * preffix[i];
            Quaternion right = suffix[j + 1] * cycle[r];
            if (left.c != 'i' || right.c != 'k') {
              continue;
            }
            {
              Quaternion center = suffix[i] * cycle[c] * preffix[j + 1];
              int used = l + 1 + c + 1 + r;
              int sgn = left.sgn * center.sgn * right.sgn;
              bool possible = true;
              if (sgn == -1) {
                if (cycle[1] != Quaternion('1', 1) &&
                    cycle[1] != Quaternion('1', -1)) {
                  used += 2;
                } else if (cycle[1] == Quaternion('1', -1)) {
                  used += 1;
                } else {
                  possible = false;
                }
              }
              if (center.c == 'j' && used <= X && possible) {
                long long others = X - used;
                if (others % period == 0) return true;
              }
            }
            if (i <= j) {
              Quaternion center = line;
              int used = l + 1 + r;
              int sgn = left.sgn * center.sgn * right.sgn;
              bool possible = true;
              if (sgn == -1) {
                if (cycle[1] != Quaternion('1', 1) &&
                    cycle[1] != Quaternion('1', -1)) {
                  used += 2;
                } else if (cycle[1] == Quaternion('1', -1)) {
                  used += 1;
                } else {
                  possible = false;
                }
              }
              if (center.c == 'j' && used <= X && possible) {
                long long others = X - used;
                if (others % period == 0) return true;
              }
            }
          }
        }
      }
    }
  }

  return false;
}

int main() {
#ifdef LOCAL_HOST
  freopen("C-large2.in", "r", stdin);
  //  freopen("input.txt", "r", stdin);
  freopen("output_big2.txt", "w", stdout);
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
