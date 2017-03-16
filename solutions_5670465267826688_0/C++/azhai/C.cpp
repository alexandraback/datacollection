#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>
#include <algorithm>
#include <cassert>

using namespace std;

typedef int quat;
const quat I = 1, J = 2, K = 3;
quat MULT[8][8];
const int L_MAX = 10100;

int L; long long X;
quat terms[L_MAX];

void init() {
  cin >> L >> X;
  string s;
  cin >> s;
  for (int i = 0; i < L; i++) {
    if (s[i] == 'i')
      terms[i] = I;
    else if (s[i] == 'j')
      terms[i] = J;
    else
      terms[i] = K;
  }
}

quat pow(quat x, long long n) {
  if (n == 0)
    return 0;
  quat y = pow(x, n / 2);
  return MULT[MULT[y][y]][n % 2 == 0 ? 0 : x];
}

void solve_case(int t) {
  init();

  quat block_total = 0;
  for (int i = 0; i < L; i++)
    block_total = MULT[block_total][terms[i % L]];
  quat total = 0;
  if (pow(block_total, X) != 4) { // total product should be -1
    cout << "Case #" << t << ": NO\n";
    return;
  }

  bool makes_i = false, makes_j = false;
  quat cur = 0;
  for (int i = 0; i < min(8LL, X) * L; i++) {
    cur = MULT[cur][terms[i % L]];
    if (!makes_i) {
      if (cur == I) {
        makes_i = true;
        cur = 0;
      }
    } else {
      if (cur == J)
        makes_j = true;
    }
  }

  cout << "Case #" << t << ": "
       << (makes_i && makes_j ? "YES" : "NO") << "\n";
}

string repr(quat x) {
  if (x >= 4)
    return "-" + repr(x - 4);
  if (x == 0)
    return "1";
  if (x == 1)
    return "i";
  if (x == 2)
    return "j";
  if (x == 3)
    return "k";
  return "?";
}

int main() {
  for (int i = 0; i < 8; i++)
    MULT[i][0] = MULT[0][i] = i;
  for (int i = 0; i < 8; i++)
    MULT[i][4] = MULT[4][i] = (i + 4) % 8;
  for (int a = 0; a < 3; a++) {
    int b = (a + 1) % 3, c = (a + 2) % 3;
    MULT[a + 1][b + 1] = c + 1;
    MULT[b + 1][a + 1] = c + 5;
    MULT[a + 1][a + 1] = MULT[a + 5][a + 5] = 4;
  }
  for (int a = 0; a < 3; a++) {
    for (int b = 0; b < 3; b++) {
      MULT[a + 5][b + 5] = MULT[a + 1][b + 1];
      MULT[a + 5][b + 1] = MULT[a + 1][b + 5] = (MULT[a + 1][b + 1] + 4) % 8;
    }
  }

  /*
  for (int i = 0; i < 8; i++) {
    for (int j = 0; j < 8; j++) {
      cout << repr(i) << " * " << repr(j) << " = " << repr(MULT[i][j]) << endl;
    }
  }
  */

  int T;
  cin >> T;

  for (int i = 0; i < T; i++) {
    solve_case(i + 1);
  }

  return 0;
}
