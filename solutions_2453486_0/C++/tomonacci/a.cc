#include <algorithm>
#include <cctype>
#include <cstdio>
#include <cmath>
#include <iostream>
#include <functional>
#include <queue>
#include <string>
#include <map>
#include <vector>

using namespace std;

const int X = 1, O = 2, Draw = 3, Incomplete = 4;
const char *Messages[] = { "", "X won", "O won", "Draw", "Game has not completed" };

#define JUDGE\
  if (x == 4 || x == 3 && t) { judgement = X; goto finish; }\
  else if (o == 4 || o == 3 && t) { judgement = O; goto finish; }

int main() {
  int T;
  char board[4][16];
  cin >> T;
  for (int I = 0; I < T; I++) {
    bool incomplete = false;
    int judgement = 0;
    for (int i = 0; i < 4; i++)
      cin >> board[i];
    for (int k = 0; k < 2; k++) {
      for (int i = 0; i < 4; i++) {
        int x = 0, o = 0, t = 0;
        for (int j = 0; j < 4; j++)
          switch (k ? board[i][j] : board[j][i]) {
          case 'X': x++; break;
          case 'O': o++; break;
          case 'T': t++; break;
          default: incomplete = true; break;
          }
        JUDGE
      }
    }
    for (int k = 0; k < 2; k++) {
      int x = 0, o = 0, t = 0;
      for (int i = 0; i < 4; i++) {
        switch (k ? board[i][i] : board[i][3-i]) {
        case 'X': x++; break;
        case 'O': o++; break;
        case 'T': t++; break;
        default: incomplete = true; break;
        }
      }
      JUDGE
    }
  finish:
    if (!judgement)
      judgement = incomplete ? Incomplete : Draw;
    cout << "Case #" << I+1 << ": " << Messages[judgement] << endl;
  }
  return 0;
}
