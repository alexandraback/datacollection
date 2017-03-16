#include <algorithm>
#include <bitset>
#include <cassert>
#include <cinttypes>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <deque>
#include <functional>
#include <iostream>
#include <limits>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

const int64_t kInf = 1.5E18;

int64_t Abs(int64_t v) {
  return v < 0 ? -v : v;
}

string A, B;
int N;
vector<int64_t> pw;
vector<int64_t> dp[4];

int64_t Dp(int type, int i) {
  if (i == N) {
    return 0;
  }

  int64_t& r = dp[type][i];
  if (r != -1) {
    return r;
  }

  if (type <= 1) {
    r = kInf;
  } else {
    r = 0;
  }

  for (int a = 0; a < 10; ++a) {
    if (A[i] != '?' && A[i] != a + '0') {
      continue;
    }

    for (int b = 0; b < 10; ++b) {
      if (B[i] != '?' && B[i] != b + '0') {
        continue;
      }

      if (type == 0) {
        if (a == b) {
          r = min(r, Dp(0, i + 1));
        } else if (a > b) {
          r = min(r, (a - b) * pw[N - i - 1] + Dp(3, i + 1));
        }
      } else if (type == 1) {
        if (a == b) {
          r = min(r, Dp(1, i + 1));
        } else if (a < b) {
          r = min(r, (b - a) * pw[N - i - 1] + Dp(2, i + 1));
        }
      } else if (type == 2) {
        if (a >= b) {
          r = max(r, (a - b) * pw[N - i - 1] + Dp(2, i + 1));
        }
      } else {
        if (a <= b) {
          r = max(r, (b - a) * pw[N - i - 1] + Dp(3, i + 1));
        }
      }
    }
  }

  return r;
}

void Out(int type, int i, string& oA, string& oB) {
  for (int a = 0; a < 10; ++a) {
    if (A[i] != '?' && A[i] != a + '0') {
      continue;
    }

    for (int b = 0; b < 10; ++b) {
      if (B[i] != '?' && B[i] != b + '0') {
        continue;
      }

      if (type == 0) {
        if (a > b) {
          if ((a - b) * pw[N - i - 1] + Dp(3, i + 1) == Dp(type, i)) {
            oA.push_back('0' + a);
            oB.push_back('0' + b);
            Out(3, i + 1, oA, oB);
            return;
          }
        } else if (a == b) {
          if (Dp(type, i) == Dp(0, i + 1)) {
            oA.push_back('0' + a);
            oB.push_back('0' + b);
            Out(0, i + 1, oA, oB);
            return;
          }
        }
      } else if (type == 1) {
        if (a == b) {
          if (Dp(type, i) == Dp(1, i + 1)) {
            oA.push_back('0' + a);
            oB.push_back('0' + b);
            Out(1, i + 1, oA, oB);
            return;
          }
        } else if (a < b) {
          if ((b - a) * pw[N - i - 1] + Dp(2, i + 1) == Dp(type, i)) {
            oA.push_back('0' + a);
            oB.push_back('0' + b);
            Out(2, i + 1, oA, oB);
            return;
          }
        }
      } else if (type == 2) {
        if (a >= b) {
          if ((a - b) * pw[N - i - 1] + Dp(2, i + 1) == Dp(type, i)) {
            oA.push_back('0' + a);
            oB.push_back('0' + b);
            Out(2, i + 1, oA, oB);
            return;
          }
        }
      } else {
        if (a <= b) {
          if ((b - a) * pw[N - i - 1] + Dp(3, i + 1) == Dp(type, i)) {
            oA.push_back('0' + a);
            oB.push_back('0' + b);
            Out(3, i + 1, oA, oB);
            return;
          }
        }
      }
    }
  }
}

void Solve() {
  cin >> A >> B;
  N = A.size();

  for (auto& d : dp) {
    d.assign(N, -1);
  }
  pw.resize(N + 1);
  pw[0] = 1;
  for (int i = 1; i <= N; ++i) {
    pw[i] = 10 * pw[i - 1];
  }

  string oA, oB;
  int64_t r1 = Dp(0, 0);
  int64_t r2 = Dp(1, 0);

  if (r1 < r2) {
    Out(0, 0, oA, oB);
  } else if (r1 > r2) {
    Out(1, 0, oA, oB);
  } else {
    Out(0, 0, oA, oB);
    string z1, z2;
    Out(1, 0, z1, z2);
    if (z1 < oA || (z1 == oA && z2 < oB)) {
      oA = z1;
      oB = z2;
    }
  }

  cout << oA << ' ' << oB << endl;

}

int main() {
//  freopen("../Console/1.txt", "rb", stdin);
  freopen("../Console/input", "rb", stdin);
  freopen("../Console/output", "wb", stdout);
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int T;
  cin >> T;
  for (int tc = 0; tc < T; ++tc) {
    cout << "Case #" << tc + 1 << ": ";
    Solve();
  }

  return 0;
}
