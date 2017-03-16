#include <iostream>
using namespace std;

int main () {
  int T, s, r, c, d1, d2;
  int b[4][4];
  char ch;
  bool complete, x, o;
  cin >> T;
  for (int i = 1; i <= T; i++) {
    complete = true;
    x = false;
    o = false;
    for (int xx = 0; xx < 4; xx++) {
      for (int y = 0; y < 4; y++) {
        cin >> ch;
        switch (ch) {
          case 'X': b[xx][y] = 1;
                    break;
          case 'O': b[xx][y] = 10;
                    break;
          case 'T': b[xx][y] = 11;
                    break;
          case '.': b[xx][y] = 0;
                    complete = false;
                    break;
        }
      }
    }
    for (int xx = 0; xx < 4; xx++) {
      r = c = 0;
      for (int y = 0; y < 4; y++) {
        r += b[xx][y];
        c += b[y][xx];
      }
      if ((r%10) == 4 || (c%10) == 4) x = true;
      if ((r/10) == 4 || (c/10) == 4) o = true;
    }
    d1 = d2 = 0;
    for(int j = 0; j < 4; j++) {
      d1 += b[j][j];
      d2 += b[j][3-j];
    }
    if((d1%10) == 4 || (d2%10) == 4) x = true;
    if((d1/10) == 4 || (d2/10) == 4) o = true;
    
    cout << "Case #" << i << ": ";
    if (x) cout << "X won\n";
    else if (o) cout << "O won\n";
    else if (complete) cout << "Draw\n";
    else cout << "Game has not completed\n";
  }
}
