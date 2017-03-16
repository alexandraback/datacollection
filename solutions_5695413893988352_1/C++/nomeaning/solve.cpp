#include <iostream>
#include <cstdlib>
#include <cassert>
using namespace std;
string retC, retJ;

long diff(string A, string B) {
  return abs(atol(A.c_str()) - atol(B.c_str()));
}

void solve(string C, string J, int cur, int matched) {
  if(cur == C.size()) {
    if(retC == "") {
      retC = C;
      retJ = J;
    }
    long d = diff(C, J);
    long md = diff(retC, retJ);
    if(d < md) {
      retC = C;
      retJ = J;
    }else if(d == md) {
      if(C < retC) {
        retC = C;
        retJ = J;
      }else if(C == retC && J < retJ) {
        retC = C;
        retJ = J;
      }
    }

    return;
  }
  if(matched == 0) {
    if(C[cur] == '?' && J[cur] == '?') {
      C[cur] = '0';
      J[cur] = '0';
      solve(C, J, cur + 1, 0); // そのまま
      C[cur] = '1';
      J[cur] = '0';
      solve(C, J, cur + 1, 1); // C-Larger
      C[cur] = '0';
      J[cur] = '1';
      solve(C, J, cur + 1, -1); // J-Larger
      C[cur] = '?';
      J[cur] = '?';
    }else if(J[cur] == '?') {
      J[cur] = C[cur];
      solve(C, J, cur + 1, 0); // そのまま
      if(C[cur] < '9') {
        J[cur] = C[cur] + 1;
        solve(C, J, cur + 1, -1 );  // J-Larger
      }
      if(C[cur] > '0') {
        J[cur] = C[cur] - 1;
        solve(C, J, cur + 1, 1);  // J-Larger
      }
      J[cur] = '?';
    }else if(C[cur] == '?') {
      C[cur] = J[cur];
      solve(C, J, cur + 1, 0); // そのまま
      if(J[cur] < '9') {
        C[cur] = J[cur] + 1;
        solve(C, J, cur + 1, 1);  // C-Larger
      }
      if(J[cur] > '0') {
        C[cur] = J[cur] - 1;
        solve(C, J, cur + 1, -1);  // J-Larger
      }
      C[cur] = '?';
    }else {
      int m = 0;
      if(C[cur] > J[cur]) m = 1; // C-Larger
      if(C[cur] < J[cur]) m = -1; // J-Larger
      solve(C, J, cur + 1, m);
    }
  } else if(matched == 1) {
    // C-Larger
    char bc = C[cur];
    if(C[cur] == '?') {
      C[cur] = '0';
    }
    char bj = J[cur];
    if(J[cur] == '?') {
      J[cur] = '9';
    }
    solve(C, J, cur + 1, matched);
    J[cur] = bj;
  }else if(matched == -1) {
    // J-Larger
    char bc = C[cur];
    if(C[cur] == '?') {
      C[cur] = '9';
    }
    char bj = J[cur];
    if(J[cur] == '?') {
      J[cur] = '0';
    }
    solve(C, J, cur + 1, matched);
    J[cur] = bj;
  }else {
    assert(false);
  }
}
int main() {
  int T;
  cin >> T;
  for(int caze = 1; caze <= T; caze++) {
    string C, J;
    cin >> C >> J;
    retC = retJ = "";
    solve(C, J, 0, 0);
    cout << "Case #" << caze << ": " << retC << " " << retJ << endl;
  }
}
