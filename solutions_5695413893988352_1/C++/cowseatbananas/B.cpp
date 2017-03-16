#include <bits/stdc++.h>
#define FOR(i, n) for (int i = 0; i < (n); ++i)
#define REP(i, n) for (int i = 1; i <= (n); ++i)
using namespace std;

int T, best = 1 << 30, bestc, bestj;
string C, J, CC, JJ, bestC, bestJ;

void lessdfs(int);
void moredfs(int);

void update() {
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

void dfs(int i) {
  if (i == (int) C.size()) {
    update();
  } else {
    if (C[i] != '?' && J[i] != '?') {
      if (C[i] == J[i]) dfs(i + 1);
      else if (C[i] < J[i]) lessdfs(i + 1);
      else moredfs(i + 1);
    } else if (C[i] == '?' && J[i] == '?') {
      CC[i] = '0';
      JJ[i] = '0';
      dfs(i + 1);
      JJ[i] = '1';
      lessdfs(i + 1);
      CC[i] = '1';
      JJ[i] = '0';
      moredfs(i + 1);
    } else if (C[i] == '?') {
      CC[i] = J[i];
      dfs(i + 1);
      if (J[i] != '0') {
        CC[i] = J[i] - 1;
        lessdfs(i + 1);
      }
      if (J[i] != '9') {
        CC[i] = J[i] + 1;
        moredfs(i + 1);
      }
    } else if (J[i] == '?') {
      JJ[i] = C[i];
      dfs(i + 1);
      if (C[i] != '0') {
        JJ[i] = C[i] - 1;
        moredfs(i + 1);
      }
      if (C[i] != '9') {
        JJ[i] = C[i] + 1;
        lessdfs(i + 1);
      }
    }
  }
}

void lessdfs(int i) {
  if (i == (int) C.size()) {
    update();
  } else {
    if (C[i] == '?') CC[i] = '9';
    if (J[i] == '?') JJ[i] = '0';
    lessdfs(i + 1);
  }
}

void moredfs(int i) {
  if (i == (int) C.size()) {
    update();
  } else {
    if (C[i] == '?') CC[i] = '0';
    if (J[i] == '?') JJ[i] = '9';
    moredfs(i + 1);
  }
}

int main() {
  cin >> T;
  REP (tc, T) {
    cin >> C >> J;
    CC = C; JJ = J;

    best = 1 << 30;
    dfs(0);

    printf("Case #%d: %s %s\n", tc, bestC.c_str(), bestJ.c_str());
  }
  return 0;
}
