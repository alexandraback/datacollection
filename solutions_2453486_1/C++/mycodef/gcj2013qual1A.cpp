#include <iostream>
#include <cstdio>
#include <string>

using namespace std;

int main() {
  ios_base::sync_with_stdio(0);
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  int t; cin >> t;
  string state[4];
  int colsx[4], rowsx[4], colso[4], rowso[4];
  for (int i = 0; i < t; ++i) {
    for (int j = 0; j < 4; ++j) {
      colsx[j] = 0;
      rowsx[j] = 0;
      colso[j] = 0;
      rowso[j] = 0;
    }
    for (int j = 0; j < 4; ++j) {
      cin >> state[j];
      for (int k = 0; k < 4; ++k) {
        if (state[j][k] == 'X' || state[j][k] == 'T') {
          ++colsx[j];
          ++rowsx[k];
        } 
        if (state[j][k] == 'O' || state[j][k] == 'T') {
          ++colso[j];
          ++rowso[k];
        }
      }
    }
    bool hasempty = false;
    int result = 0;
    for (int j = 0; j < 4; ++j) {
      if (colsx[j] == 4 || rowsx[j] == 4) result = 1;
      else if (colso[j] == 4 || rowso[j] == 4) result = 2;
      if (colsx[j] + colso[j] < 4 || rowsx[j] + rowso[j] < 4)
        hasempty = true;
    }
    int xd1 = 0, xd2 = 0, od1 = 0, od2 = 0;
    for (int j = 0; j < 4; ++j) {
      if (state[j][j] == 'X' || state[j][j] == 'T') ++xd1;
      if (state[j][j] == 'O' || state[j][j] == 'T') ++od1;
      if (state[j][4 - 1 - j] == 'X' || state[j][4 - 1 - j] == 'T') ++xd2;
      if (state[j][4 - 1 - j] == 'O' || state[j][4 - 1 - j] == 'T') ++od2;
    }
    if (xd1 == 4 || xd2 == 4) result = 1;
    else if (od1 == 4 || od2 == 4) result = 2;
    if (result > 0) {
      cout << "Case #" << (i + 1) << ": " << (result == 1 ? "X won\n" : "O won\n");
    } else {
      cout << "Case #" << (i + 1) << ": " << (hasempty ? "Game has not completed\n" : "Draw\n");
    }

  }    
  return 0;
}
