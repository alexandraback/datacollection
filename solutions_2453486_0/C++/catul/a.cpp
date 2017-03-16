#include <cstdio>
#include <iostream>
#include <vector>
#include <cmath>
#include <cstdlib>
using namespace std;

int main() {
  int T, num=1;
  int i,j;
  int line;
  char point;
  char board[4][4];

  for (cin >> T; T--;) {
    for (i = 0; i < 4; i++)
      for (j = 0; j < 4; j++)
        cin >> board[i][j];

    int  done   = 1;
    char winner = ' ';

    // horizontal lines
    for (line = 0; line < 4; line++) {
      char first = ' ';
      for (i = 0; i < 4; i++) {
        point = board[line][i];
        if (point == '.') {
          done = 0;
          goto next_hline;
        }
        if (point == 'T')
          continue;
        if (first == ' ') {
          first = point;
          continue;
        }
        if (first != point)
          goto next_hline;
      }
      winner = first;
      goto found;
next_hline:;
    }

    // vertical lines
    for (line = 0; line < 4; line++) {
      char first = ' ';
      for (i = 0; i < 4; i++) {
        point = board[i][line];
        if (point == '.') {
          done = 0;
          goto next_vline;
        }
        if (point == 'T')
          continue;
        if (first == ' ') {
          first = point;
          continue;
        }
        if (first != point)
          goto next_vline;
      }
      winner = first;
      goto found;
next_vline:;
    }

    // diagonal lines
    for (line = 0; line < 2; line++) {
      char first = ' ';
      for (i = 0; i < 4; i++) {
        point = line == 0 ? board[i][i] : board[3-i][i];
        if (point == '.') {
          done = 0;
          goto next_dline;
        }
        if (point == 'T')
          continue;
        if (first == ' ') {
          first = point;
          continue;
        }
        if (first != point)
          goto next_dline;
      }
      winner = first;
      goto found;
next_dline:;
    }

    // not found, draw or not over
    if (done)
      printf("Case #%d: Draw\n", num++);
    else
      printf("Case #%d: Game has not completed\n", num++);
    continue;

found:
    printf("Case #%d: %c won\n", num++, winner);
  }
}
