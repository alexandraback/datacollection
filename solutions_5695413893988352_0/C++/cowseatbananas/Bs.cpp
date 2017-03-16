#include <bits/stdc++.h>
#define FOR(i, n) for (int i = 0; i < (n); ++i)
#define REP(i, n) for (int i = 1; i <= (n); ++i)
using namespace std;

int T;
string C, J, CC, JJ;

int main() {
  cin >> T;
  REP (tc, T) {
    cin >> C >> J;
    CC = C; JJ = J;

    int best = 1 << 30;
    int bestc, bestj;
    string bestC, bestJ;

    int nx = 0, nm = 1;
    for (auto x : C) if (x == '?') ++nx, nm *= 10;
    for (auto x : J) if (x == '?') ++nx, nm *= 10;
    for (int m = 0; m < nm; ++m) {
      int n = m;
      for (int i = 0; i < (int) C.size(); ++i) {
        if (C[i] == '?') {
          int d = n % 10;
          n /= 10;
          CC[i] = '0' + d;
        }
      }
      for (int i = 0; i < (int) J.size(); ++i) {
        if (J[i] == '?') {
          int d = n % 10;
          n /= 10;
          JJ[i] = '0' + d;
        }
      }

      int CD = 0, JD = 0;
      for (auto x : CC) CD = CD * 10 + (x - '0');
      for (auto x : JJ) JD = JD * 10 + (x - '0');

      if (best == 1 << 30 || best > abs(CD - JD) ||
          (best == abs(CD - JD)
           && (CD < bestc || (CD == bestc && JD < bestj)))) {
        best = abs(CD - JD);
        bestc = CD;
        bestj = JD;
        bestC = CC;
        bestJ = JJ;
      }
    }

    printf("Case #%d: %s %s\n", tc, bestC.c_str(), bestJ.c_str());
  }
  return 0;
}
