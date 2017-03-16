#include <iostream>
#include <string>
#include <vector>


class solver
{
public:
  solver(const std::vector<std::string>& board) : board_(board) {};

public:
  std::string solve() {
    if (check('X'))
      return "X won";

    if (check('O'))
      return "O won";

    for (int i = 0; i < 4; i ++)
      if (board_[i].find('.') != std::string::npos)
        return "Game has not completed";

    return "Draw";
  };

private:
  bool check(char c) const {
    for (int i = 0; i < 4; i ++)
      if (check_(c, i, 0, 0, 1))
        return true;
    
    for (int i = 0; i < 4; i ++)
      if (check_(c, 0, i, 1, 0))
        return true;

    if (check_(c, 0, 0, 1, 1))
      return true;

    if (check_(c, 0, 3, 1, -1))
      return true;

    return false;
  };

  bool check_(char c, int x, int y, int dx, int dy) const {
    for (int i = 0; i < 4; i ++, x += dx, y += dy)
      if (board_[y][x] != c && board_[y][x] != 'T')
        return false;
    
    return true;
  };

private:
  std::vector<std::string> board_;
};

int main(int argc, char** argv)
{
  int T;

  std::cin >> T;

  for (int t = 1; t <= T; t ++) {
    std::vector<std::string> board(4);

    for (int i = 0; i < 4; i ++)
      std::cin >> board[i];

    std::cout << "Case #" << t << ": " << solver(board).solve() << std::endl;
  }

  return 0;
}
