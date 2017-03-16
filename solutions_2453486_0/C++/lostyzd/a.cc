#include <iostream>
#include <string>

int m[4][4];

char check() {
  for (int i = 0; i < 4; ++i) {
    int cnt = 0;
    for (int j = 0; j < 4; ++j) {
      cnt += m[i][j];
    }
    if (cnt == 7 || cnt == 8) return 'X';
    if (cnt == 400 || cnt == 301) return 'O';
  }

  for (int j = 0; j < 4; ++j) {
    int cnt = 0;
    for (int i = 0; i < 4; ++i) {
      cnt += m[i][j];
    }
    if (cnt == 7 || cnt == 8) return 'X';
    if (cnt == 400 || cnt == 301) return 'O';

  }

  int cnt = 0;
  cnt = m[0][0] + m[1][1] + m[2][2] + m[3][3];
  if (cnt == 7 || cnt == 8) return 'X';
  if (cnt == 400 || cnt == 301) return 'O';

  cnt = m[0][3] + m[1][2] + m[2][1] + m[3][0];
  if (cnt == 7 || cnt == 8) return 'X';
  if (cnt == 400 || cnt == 301) return 'O';

  return 0;
}

int main() {
  int T;
  std::cin >> T;
for (int tt = 1; tt <= T; ++tt) {
  std::string s;
  int cnt = 0;
  for (int i = 0; i < 4; ++i) {
    std::cin >> s;
    for (int j = 0; j < 4; ++j) {
      if (s[j] == 'X') {
        m[i][j] = 2;
      } else if (s[j] == 'O') {
        m[i][j] = 100;
      } else if (s[j] == 'T') {
        m[i][j] = 1;
      } else {
        m[i][j] = 0;
      }
      if (s[j] != '.') ++cnt;
    }
  }

  char win = check();

  std::cout << "Case #" << tt << ": ";
  if (win) {
    std::cout << win << " won" << std::endl;
  } else if (cnt == 16) {
    std::cout << "Draw" << std::endl;
  } else {
    std::cout << "Game has not completed" << std::endl;
  }
}
}
