#include <iostream>
#include <map>
#include <string>
#include <vector>

char GetStatus(const std::vector<std::string>& board) {
  // rows
  for (int r = 0; r < 4; r++) {
    std::map<char, int> counters;
    for (int c = 0; c < 4; c++) {
      ++counters[board[r][c]];
    }
    if (counters['X'] + counters['T'] == 4) {
      return 'X';
    } else if (counters['O'] + counters['T'] == 4) {
      return 'O';
    }
  }
  // columns
  for (int c = 0; c < 4; c++) {
    std::map<char, int> counters;
    for (int r = 0; r < 4; r++) {
      ++counters[board[r][c]];
    }
    if (counters['X'] + counters['T'] == 4) {
      return 'X';
    } else if (counters['O'] + counters['T'] == 4) {
      return 'O';
    }
  }
  // diagonals
  {
    std::map<char, int> counters;
    for (int r = 0; r < 4; r++) {
      int c = r;
      ++counters[board[r][c]];
    }
    if (counters['X'] + counters['T'] == 4) {
      return 'X';
    } else if (counters['O'] + counters['T'] == 4) {
      return 'O';
    }
  }
  {
    std::map<char, int> counters;
    for (int r = 0; r < 4; r++) {
      int c = 3 - r;
      ++counters[board[r][c]];
    }
    if (counters['X'] + counters['T'] == 4) {
      return 'X';
    } else if (counters['O'] + counters['T'] == 4) {
      return 'O';
    }
  }
  // draw or not completed
  std::map<char, int> counters;
  for (int r = 0; r < 4; r++) {
    for (int c = 0; c < 4; c++) {
      ++counters[board[r][c]];
    }
  }
  if (counters['.'] == 0) {
    return 'D';
  } else {
    return 'N';
  }
}

int main() {
  std::ios_base::sync_with_stdio(false);
  int numCases;
  std::cin >> numCases;
  std::vector<std::string> board(4);
  for (int caseNum = 1; caseNum <= numCases; caseNum++) {
    std::string line;
    std::getline(std::cin, line);
    for (int i = 0; i < 4; i++) {
      std::getline(std::cin, board[i]);
    }
    char status = GetStatus(board);
    std::cout << "Case #" << caseNum << ": ";
    switch (status) {
      case 'X':
        std::cout << "X won";
        break;
      case 'O':
        std::cout << "O won";
        break;
      case 'D':
        std::cout << "Draw";
        break;
      case 'N':
        std::cout << "Game has not completed";
        break;
      default:
        break;
    }
    std::cout << std::endl;
  }
}
