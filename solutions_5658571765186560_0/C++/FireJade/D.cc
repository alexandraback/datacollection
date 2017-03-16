#include <iostream>
using namespace std;

int main() {
  int T; cin >> T; int X, R, C;
  for (int caseNum = 1; caseNum <= T; caseNum++) {
    cin >> X >> R >> C; int sm = min(R, C), la = max(R, C);
    bool canSolve;
    if ((R * C) % X != 0 || X >= 7) {
      canSolve = false;
    } else if (X == 1) {
      canSolve = true;
    } else if (X == 2) {
      canSolve = true;
    } else if (X == 3) {
      canSolve = sm >= 2;
    } else if (X == 4) {
      canSolve = sm >= 3;
    } else if (X == 5) {
      canSolve = sm >= 4;
    } else {
      canSolve = sm >= 4;
    }

    if (canSolve) {
      cout << "Case #" << caseNum << ": GABRIEL" << endl;
    } else {
      cout << "Case #" << caseNum << ": RICHARD" << endl;
    }
  }
}
