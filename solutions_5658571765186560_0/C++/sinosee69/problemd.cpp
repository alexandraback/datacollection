#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <sstream>
#include <cmath>
#include <cctype>
#include <queue>
using namespace std;

int main() {
  int index_table[4][4] = {
    {0, 0, 0, 0},
    {1, 2, 0, 0},
    {3, 4, 5, 0},
    {6, 7, 8, 9},
  };

  int combo_table[10][3] = {
    {2, 3, 4},
    {3, 4, 0},
    {3, 4, 0},
    {2, 3, 4},
    {4, 0, 0},
    {2, 4, 0},
    {3, 4, 0},
    {3, 4, 0},
    {0, 0, 0},
    {3, 0, 0}
  };
  
  int T;
  cin >> T;
  for(int t = 0; t < T; t++) {
    int X, R, C;
    cin >> X >> R >> C;
    int row = (R > C) ? R : C;
    int col = (R > C) ? C : R;

    //**TEST
    // cout << row << " " << col << endl;

    int index = index_table[row-1][col-1]; 
    bool rich = false;
    for(int c = 0; c < 3; c++) {
      if(combo_table[index][c] == X)
        rich = true;
    }

    if(rich)
      cout << "Case #" << t+1 << ": RICHARD" << endl;
    else
      cout << "Case #" << t+1 << ": GABRIEL" << endl;
  }
}
