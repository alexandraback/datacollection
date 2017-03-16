#include <iostream>
#include <string>

using namespace std;

const int N = 4;

string a[N];

bool win(char token) {
  for (int i = 0; i < N; i++) {
    bool good = true;
    for (int j = 0; good && j < N; j++) if (a[i][j] != token && a[i][j] != 'T') good = false;
    if (good) return true;
  }
  for (int j = 0; j < N; j++) {
    bool good = true;
    for (int i = 0; good && i < N; i++) if (a[i][j] != token && a[i][j] != 'T') good = false;
    if (good) return true;
  }
  bool good = true;
  for (int i = 0; i < N; i++) if (a[i][i] != token && a[i][i] != 'T') good = false;
  if (good) return true;

  good = true;
  for (int i = 0; i < N; i++) if (a[i][N-1-i] != token && a[i][N-1-i] != 'T') good = false;
  return good;  
}

int main() {
  int cases; cin >> cases;
  for (int caseNo = 1; caseNo <= cases; caseNo++) {
    for (int i = 0; i < N; i++) cin >> a[i];

    bool onGoing = false;
    for (int i = 0; i < N; i++) for (int j = 0; j < N; j++) {
      if (a[i][j] == '.') {
        onGoing = true;
      }
    }
    cout << "Case #" << caseNo << ": ";
    if (win('O')) cout << "O won" << endl;
    else if (win('X')) cout << "X won" << endl;
    else if (onGoing) cout << "Game has not completed" << endl;
    else cout << "Draw" << endl;
  }
  return 0;
}