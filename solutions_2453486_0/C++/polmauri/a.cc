#include <iostream>
#include <string>
#include <vector>
using namespace std;

typedef vector<string> Vs;

bool won(const Vs& m, char c) {
  for (int i = 0; i < 4; ++i) {
    bool ok = true;
    for (int j = 0; j < 4; ++j)
      if (m[i][j] != 'T' and m[i][j] != c) {
        ok = false;
        break;
      }
    if (ok) return true;
  }
  for (int j = 0; j < 4; ++j) {
    bool ok = true;
    for (int i = 0; i < 4; ++i)
      if (m[i][j] != 'T' and m[i][j] != c) {
        ok = false;
        break;
      }
    if (ok) return true;
  }
  bool ok = true;
  for (int i = 0; i < 4; ++i)
    if (m[i][i] != 'T' and m[i][i] != c) {
      ok = false;
      break;
    }
  if (ok) return true;
  for (int i = 0; i < 4; ++i)
    if (m[i][3 - i] != 'T' and m[i][3 - i] != c)
      return false;
  return true;
}

int main() {
  int tcas;
  cin >> tcas;
  for (int cas = 1; cas <= tcas; ++cas) {
    cout << "Case #" << cas << ": ";
    
    Vs m(4);
    for (int i = 0; i < 4; ++i) cin >> m[i];
    
    if (won(m, 'X')) cout << "X won" << endl;
    else if (won(m, 'O')) cout << "O won" << endl;
    else {
      bool draw = true;
      for (int i = 0; i < 4; ++i)
        for (int j = 0; j < 4; ++j)
          if (m[i][j] == '.') draw = false;
      if (draw) cout << "Draw" << endl;
      else cout << "Game has not completed" << endl;
    }
  }
}
