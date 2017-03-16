#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
#include <set>
#include <map>
#include <vector>
#include <bitset>
#include <cstdio>
#include <queue>

using namespace std;

bool checkXWin (const string& s) {
  if (s == "XXXX") return true;
  if (s == "XXXT") return true;
  if (s == "XXTX") return true;
  if (s == "XTXX") return true;
  if (s == "TXXX") return true;
  return false;
}

bool checkOWin (const string& s) {
  if (s == "OOOO") return true;
  if (s == "OOOT") return true;
  if (s == "OOTO") return true;
  if (s == "OTOO") return true;
  if (s == "TOOO") return true;
  return false;
}

void solve () {
  vector <string> board(4);
  for (int i = 0; i < 4; ++i) {
    cin >> board[i];
  }

  for (int i = 0; i < 4; ++i) {
    string column;
    for (int j = 0; j < 4; ++j) {
      column += board[j][i];
    }
    if (checkXWin(board[i]) || checkXWin(column)) {
      cout << "X won" << endl;
      return;
    }
    if (checkOWin(board[i]) || checkOWin(column)) {
      cout << "O won" << endl;
      return;
    }
  }

  string diagonal1, diagonal2;
  for (int i = 0; i < 4; ++i) {
    diagonal1 += board[i][i];
    diagonal2 += board[i][3 - i];
  }
  if (checkXWin(diagonal1) || checkXWin(diagonal2)) {
    cout << "X won" << endl;
    return;
  }
  if (checkOWin(diagonal1) || checkOWin(diagonal2)) {
    cout << "O won" << endl;
    return;
  }

  bool filled_board = true;
  for (int i = 0; i < 4; ++i) {
    for (int j = 0; j < 4; ++j) {
      if (board[i][j] == '.') {
        filled_board = false;
        break;
      }
    }
    if (!filled_board) {
      break;
    }
  }

  if (filled_board) {
    cout << "Draw" << endl;
    return;
  }
  cout << "Game has not completed" << endl;
}

int main() {
	freopen("A-large.in","r",stdin);
	freopen("output.txt","w",stdout);

	int T;
	cin >> T;
	for (int test = 1; test <= T; ++test) {
		cout << "Case #" << test << ": ";
    solve();
	}
	return 0;
}
