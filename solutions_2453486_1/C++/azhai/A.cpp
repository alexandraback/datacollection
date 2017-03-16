#include <iostream>

using namespace std;

const int GRID_DIM = 4;

bool filled;
char grid[GRID_DIM][GRID_DIM];

bool check_diag1(char player) {
  for (int i = 0; i < GRID_DIM; i++) {
    char c = grid[i][i];
    if (c != 'T' && c != player)
      return false;
  }
  return true;
}

bool check_diag2(char player) {
  for (int i = 0; i < GRID_DIM; i++) {
    char c = grid[i][GRID_DIM - 1 - i];
    if (c != 'T' && c != player)
      return false;
  }
  return true;
}

bool check_rows(char player) {
  for (int i = 0; i < GRID_DIM; i++) {
    bool won_row = true;
    for (int j = 0; j < GRID_DIM; j++) {
      char c = grid[i][j];
      if (c != 'T' && c != player) {
        won_row = false;
        break;
      }
    }
    if (won_row)
      return true;
  }
  return false;
}

bool check_cols(char player) {
  for (int i = 0; i < GRID_DIM; i++) {
    bool won_col = true;
    for (int j = 0; j < GRID_DIM; j++) {
      char c = grid[j][i];
      if (c != 'T' && c != player) {
        won_col = false;
        break;
      }
    }
    if (won_col)
      return true;
  }
  return false;
}

char get_winner() {
  char players[2] = {'X', 'O'};
  for (int i = 0; i < 2; i++) {
    char c = players[i];
    if (check_diag1(c) || check_diag2(c) || check_rows(c) || check_cols(c))
      return c;
  }
  return '.';
}

void init() {
  filled = true;

  for (int i = 0; i < GRID_DIM; i++) {
    for (int j = 0; j < GRID_DIM; j++) {
      char c;
      cin >> c;
      grid[i][j] = c;
      if (c == '.')
        filled = false;
    }
  }
}

void solve_case(int t) {
  init();

  cout << "Case #" << t << ": ";

  switch(get_winner()) {
  case 'X':
    cout << "X won\n";
    break;
  case 'O':
    cout << "O won\n";
    break;
  case '.':
    if (filled)
      cout << "Draw\n";
    else
      cout << "Game has not completed\n";
  }
}

int main() {
  int T;
  cin >> T;

  for (int i = 0; i < T; i++) {
    solve_case(i + 1);
  }

  return 0;
}
