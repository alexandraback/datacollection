#include <iostream>
#include <algorithm>
using namespace std;

int Z;
char plt[4][4];

void read();
void soups_on(int);

int main() {
  cin >> Z;
  for (int zi = 1; zi <= Z; ++zi)
    read(), soups_on(zi);

  return 0;
}

void read() {
  for (int i = 0; i < 4; ++i)
    for (int j = 0; j < 4; ++j)
      cin >> plt[i][j];
}

void soups_on(int zi) {
  int num_symb = 0;
  char last_move;
  bool is_win = false, find_empty = false, is_invalid;

  for (int i = 0; i < 4; ++i)
    for (int j = 0; j < 4; ++j) {
      if (plt[i][j] == 'X' || plt[i][j] == 'O')
        ++num_symb;
      if (plt[i][j] == '.')
        find_empty = true;
    }

  last_move = num_symb % 2 ? 'X' : 'O';
  for (int i = 0; i < 4 && !is_win; ++i) {
    is_invalid = false;
    for (int j = 0; j < 4 && !is_invalid; ++j)
      if (plt[i][j] != last_move && plt[i][j] != 'T')
        is_invalid = true;
    if (!is_invalid)
      is_win = true;
  }

  for (int i = 0; i < 4 && !is_win; ++i) {
    is_invalid = false;
    for (int j = 0; j < 4 && !is_invalid; ++j)
      if (plt[j][i] != last_move && plt[j][i] != 'T')
        is_invalid = true;
    if (!is_invalid)
      is_win = true;
  }

  is_invalid = false;
  for (int i = 0; i < 4 && !is_invalid; ++i)
    if (plt[i][i] != last_move && plt[i][i] != 'T')
      is_invalid = true;
  if (!is_invalid)
    is_win = true;

  is_invalid = false;
  for (int i = 0; i < 4 && !is_invalid; ++i)
    if (plt[i][3 - i] != last_move && plt[i][3 - i] != 'T')
      is_invalid = true;
  if (!is_invalid)
    is_win = true;

  cout << "Case #" << zi << ": ";
  if (is_win)
    cout << last_move << " won\n";
  else if (find_empty)
    cout << "Game has not completed\n";
  else
    cout << "Draw\n";
}
