#include <iostream>
#include <vector>

using namespace::std;

int board[4][4];

bool checkWin(char player) {
  for (int i = 0; i < 4; i++) {    
    bool row = true;
    for (int j = 0; j < 4; j++) {
      if (board[i][j] != player &&
	  board[i][j] != 'T') {
	row = false;
	break;
      }
    }
    if (row == true) return true;
  }

  for (int i = 0; i < 4; i++) {    
    bool row = true;
    for (int j = 0; j < 4; j++) {
      if (board[j][i] != player &&
	  board[j][i] != 'T') {
	row = false;
	break;
      }
    }
    if (row == true) return true;
  }

  bool diag1 = true;
  for (int i = 0; i < 4; i++) {
    if (board[i][i] != player &&
	board[i][i] != 'T') {
      diag1 = false;
      break;
    }
  }

  if (diag1 == true)
    return true;

  bool diag2 = true;
  for (int i = 0; i < 4; i++) {
    if (board[i][3-i] != player &&
	board[i][3-i] != 'T') {
      diag2 = false;
      break;
    }
  }

  if (diag2 == true)
    return true;

  return false;
}

bool checkFilled() {
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 4; j++) {
      if (board[i][j] == '.')
	return false;
    }
  }
  return true;
}

int main(int argc, char *argv[]) {
  int n_cases = 0;
  cin >> n_cases;

  for (int i = 0; i < n_cases; i++) {

    for (int j = 0; j < 4; j++) {
      for (int k = 0; k < 4; k++) {
	char c;
	cin >> c;
	
	board[j][k] = c;
      }
    }
    
    cout << "Case #" << i+1 << ": ";

    if (checkWin('X')) 
      cout << "X won" << endl;
    else if (checkWin('O'))
      cout << "O won" << endl;
    else if (checkFilled())
      cout << "Draw" << endl;
    else 
      cout << "Game has not completed" << endl;     
  }
}
