#include <iostream>
#include <vector>
using namespace std;

inline bool valid(char x, char c) {
  return x == c or x == 'T';  
}

bool win(vector<string>& v, char c) {
  //Check diagonals
  if (valid(v[0][0], c) and valid(v[1][1], c) and valid(v[2][2], c) and valid(v[3][3], c)) return true;
  if (valid(v[0][3], c) and valid(v[1][2], c) and valid(v[2][1], c) and valid(v[3][0], c)) return true;
  
  //Check rows
  for (int i = 0; i < 4; ++i) {
    bool ok = true;
    for (int j = 0; j < 4; ++j) if (not valid(v[i][j], c)) ok = false;
    if (ok) return true;
  }
  
  //Check columns
  for (int i = 0; i < 4; ++i) {
    bool ok = true;
    for (int j = 0; j < 4; ++j) if (not valid(v[j][i], c)) ok = false;
    if (ok) return true;
  }
  
  return false;
}

int main() {
  int casos;
  cin >> casos;
  for (int cas = 1; cas <= casos; ++cas) {
    vector<string> v(4);
    for (int i = 0; i < 4; ++i) cin >> v[i];
    
    cout << "Case #" << cas << ": ";
    
    if (win(v, 'X')) cout << "X won" << endl;
    else if (win(v, 'O')) cout << "O won" << endl;
    else {
      bool end = true;
      for (int i = 0; i < 4; ++i) for (int j = 0; j < 4; ++j) if (v[i][j] == '.') end = false;
      if (end) cout << "Draw" << endl;
      else cout << "Game has not completed" << endl;
    }
  }
}