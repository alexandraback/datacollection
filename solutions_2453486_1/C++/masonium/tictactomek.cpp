#include <vector>
#include <iostream>

using namespace std;

struct Board
{
  char c[4][4];
};

Board read_board()
{
  Board b;
  
  for (int y = 0; y < 4; ++y)
    for (int x = 0; x < 4; ++x)
      cin >> b.c[x][y];

  return b;
}

bool helps(char c, char player)
{
  return c == player || c == 'T';
}

bool has_win(const Board& b, char p)
{
  bool win;
  
  for (int i = 0; i < 4; ++i)
  {
    win = true;
    for (int j = 0; j < 4; ++j)
      win = win && helps(b.c[i][j], p);
    if (win)
      return true;

    win = true;
    for (int j = 0; j < 4; ++j)
      win = win && helps(b.c[j][i], p);
    if (win)
      return true;
  }
  
  win = true;
  for (int j = 0; j < 4; ++j)
    win = win && helps(b.c[j][j], p);
  if (win)
    return true;

  win = true;
  for (int j = 0; j < 4; ++j)
    win = win && helps(b.c[j][3-j], p);
  if (win)
    return true;

  return false;
}

bool has_space_left(const Board& board)
{
  for (int i = 0; i < 4; ++i)
    for (int j = 0; j < 4; ++j)
      if (board.c[j][j] == '.')
        return true;

  return false;
}

void solve_case(int casenum)
{
  Board board = read_board();

  cout << "Case #" << casenum << ": ";
  
  if (has_win(board, 'X'))
    cout << "X won";
  else if (has_win(board, 'O'))
    cout << "O won";
  else if (has_space_left(board))
    cout << "Game has not completed";
  else
    cout << "Draw";
  
  cout << endl;
}

int main(int argc, char ** args)
{
  int T;
  cin >> T;
  for (int i = 1; i <= T; ++i)
  {
    solve_case(i);
  }

  return 0;
}
