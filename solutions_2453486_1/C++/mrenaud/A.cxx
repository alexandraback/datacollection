#include <array>
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

bool is_same(char a, char b)
{
  return a == b || a == 'T';
}


void solve(int c)
{
  std::array<std::string,4> board;
  bool empty_position = false;

  for (int i = 0; i < 4; ++i)
  {
    std::string line;

    for (int j = 0; j < 4; ++j)
    {
      char c;
      std::cin >> c;
      line.push_back(c);
      if (c == '.')
        empty_position = true;
    }
    board[i] = line;
  }

  // Output:
  std::cout << "Case #" << c << ": ";

  for (char p : {'X', 'O'})
  {
    // Check horizontal.
    for (int i = 0; i < 4; ++i)
    {
      for (int j = 0; j < 4; ++j)
      {
        if (board[i][j] != p && board[i][j] != 'T')
          break;

        if (j == 3)
        {
          std::cout << p << " won\n";
          return;
        }
      }
    }

    // Check vertical.
    for (int i = 0; i < 4; ++i)
    {
      for (int j = 0; j < 4; ++j)
      {
        if (board[j][i] != p && board[j][i] != 'T')
          break;

        if (j == 3)
        {
          std::cout << p << " won\n";
          return;
        }
      }
    }

    // Check diagonal
    for (int i = 0; i < 4; ++i)
    {
      if (board[i][i] != p && board[i][i] != 'T')
        break;

      if (i == 3)
      {
        std::cout << p << " won\n";
        return;
      }
    }

    // Check diagonal
    for (int i = 0; i < 4; ++i)
    {
      if (board[i][3-i] != p && board[i][3-i] != 'T')
        break;

      if (i == 3)
      {
        std::cout << p << " won\n";
        return;
      }
    }
  } // for (player)

  if (empty_position)
    std::cout << "Game has not completed\n";
  else
    std::cout << "Draw\n";
}




int main()
{
  int N;
  std::cin >> N;

  for (int i = 1; i <= N; ++i)
    solve(i);
}
