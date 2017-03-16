#include <iostream>

using namespace std;
string status[4] = {"X won", "O won", "Draw", "Game has not completed"};
int main() {
    int T; cin >> T;
    char grid[4][4];
    int zz = 1;
    while(T--) {
      bool done = true;
      for (int i=0; i < 4; i++) for (int j=0; j < 4; j++) {
          cin >> grid[i][j];
          if (grid[i][j] == '.') done = false;
      }
      bool xwon = false, owon = false;
      int o,x;
      for (int i=0; i < 4; i++) {
          o=0, x=0;
          for (int j=0; j < 4; j++) {
              if (grid[i][j] == 'O') o++;
              if (grid[i][j] == 'X') x++;
              if (grid[i][j] == 'T') o++, x++;
          }
          if (x==4) xwon = 1;
          if (o==4) owon = 1;
          
          o=0, x=0;
          for (int j=0; j < 4; j++) {
              if (grid[j][i] == 'O') o++;
              if (grid[j][i] == 'X') x++;
              if (grid[j][i] == 'T') o++, x++;
          }
          if (x==4) xwon = 1;
          if (o==4) owon = 1;
      }

      o=0, x=0;
      for (int j=0; j < 4; j++) {
          if (grid[j][j] == 'O') o++;
          if (grid[j][j] == 'X') x++;
          if (grid[j][j] == 'T') o++, x++;
      }
      if (x==4) xwon = 1;
      if (o==4) owon = 1;

      o=0, x=0;
      for (int j=0; j < 4; j++) {
          if (grid[j][3-j] == 'O') o++;
          if (grid[j][3-j] == 'X') x++;
          if (grid[j][3-j] == 'T') o++, x++;
      }
      if (x==4) xwon = 1;
      if (o==4) owon = 1;

      int res = 3;
      if (xwon && owon) res = 2;
      else if (xwon) res = 0;
      else if (owon) res = 1;
      else if (done) res = 2;

      cout << "Case #" << zz++ << ": " << status[res] << endl;
    }
    return 0;
}
