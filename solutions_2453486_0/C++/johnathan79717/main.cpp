#include <iostream>

using namespace std;

char b[4][5];
int i, j, Ti, Tj;

bool check_won(char c) {
  if(Ti > 0)
    b[Ti][Tj] = c;
  for(i = 0; i < 4; i++) {
    if(b[i][0] == c && b[i][1] == c && b[i][2] == c && b[i][3] == c)
      return true;
    if(b[0][i] == c && b[1][i] == c && b[2][i] == c && b[3][i] == c)
      return true;
  }
  if(b[0][0] == c && b[1][1] == c && b[2][2] == c && b[3][3] == c)
    return true;
  if(b[3][0] == c && b[2][1] == c && b[1][2] == c && b[0][3] == c)
    return true;

  return false;
}

bool check_complete() {
  for(i = 0; i < 4; ++i)
    for(j = 0; j < 4; j++)
      if(b[i][j] == '.')
        return false;
  return true;
}

int main() {
  int T;
  cin >> T;
  for(int t = 1; t <= T; ++t) {
    cout << "Case #" << t << ": "; 
    for(i = 0; i < 4; i++)
      cin >> b[i];

    Ti = -1; Tj = -1;
    for(i = 0; i < 4; i++)
      for(j = 0; j < 4; j++)
        if(b[i][j] == 'T') {
          Ti = i;
          Tj = j;
        }

    if(check_won('X')) {
      cout << "X won" << endl;
      continue;
    }
    if(check_won('O')) {
      cout << "O won" << endl;
      continue;
    }

    if(check_complete())
      cout << "Draw" << endl;
    else
      cout << "Game has not completed" << endl;

  }
}