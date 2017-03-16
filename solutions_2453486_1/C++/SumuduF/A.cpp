#include <iostream>

using namespace std;

const int W = 4;
const char WILD = 'T';
const char EMPTY = '.';

bool full(const char board[W][W]) {
  for (int i = 0; i < W; ++i)
    for (int j = 0; j < W; ++j)
      if (board[i][j] == EMPTY) return false;
  return true;
  }

bool winD(char c, const char board[W][W], int a, int b, int da, int db) {
  for (int i = 0; i < W; ++i) {
    char x = board[a+i*da][b+i*db];
    if ((x != c) && (x != WILD))
      return false;
    }
  return true;
  }

bool win(char c, const char board[W][W]) {
  if (winD(c, board, 0, 0, 1, 1)) return true;
  if (winD(c, board, W-1, 0, -1, 1)) return true;

  for (int i = 0; i < W; ++i) {
    if (winD(c, board, i, 0, 0, 1)) return true;
    if (winD(c, board, 0, i, 1, 0)) return true;
    }

  return false;
  }

int main() {
  int nc; cin >> nc;
  for (int curC = 1; curC <= nc; ++curC) {
    char board[W][W];
    for (int i = 0; i < W; ++i)
      for (int j = 0; j < W; ++j)
        cin >> board[i][j];

    cout << "Case #" << curC << ": ";
    if (win('X', board))
      cout << "X won\n";
    else if (win('O', board))
      cout << "O won\n";
    else if (full(board))
      cout << "Draw\n";
    else
      cout << "Game has not completed\n";
    }
  }

