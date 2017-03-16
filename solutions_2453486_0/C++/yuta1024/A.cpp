#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

bool solve(vector<string> board, char symbol)
{
  for (unsigned int i = 0; i < board.size(); ++i) {
    for (unsigned int j = 0; j < board[i].size(); ++j) {
      if (board[i][j] == 'T')
        board[i][j] = symbol;
    }
  }

  // hor
  for (unsigned int i = 0; i < board.size(); ++i) {
    if (count(board[i].begin(), board[i].end(), symbol) == 4)
      return true;
  }

  // ver
  for (unsigned int i = 0; i < board[0].size(); ++i) {
    int cnt = 0;
    for (unsigned int j = 0; j <  board.size(); ++j) {
      if (board[j][i] == symbol)
        ++cnt;
    }
    if (cnt == 4)
      return true;
  }

  // diag
  if ((board[0][0] == symbol && board[1][1] == symbol &&
       board[2][2] == symbol && board[3][3] == symbol) ||
      (board[0][3] == symbol && board[1][2] == symbol &&
       board[2][1] == symbol && board[3][0] == symbol))
    return true;

  return false;
}


int main()
{
  int T;
  cin >> T;
  for (int t = 0; t < T; ++t) {
    int empty = 0;
    vector<string> board(4);
    for (int i = 0; i < 4; ++i) {
      cin >> board[i];
      empty += count(board[i].begin(), board[i].end(), '.');
    }

    cout << "Case #" << t+1 << ": ";
    if (solve(board, 'X'))
      cout << "X won" << endl;
    else if (solve(board, 'O'))
      cout << "O won" << endl;
    else if (empty != 0)
      cout << "Game has not completed" << endl;
    else
      cout << "Draw" << endl;
  }
  return 0;
}
