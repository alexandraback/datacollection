#include <cstdlib>
#include <cmath>
#include <ctime>
#include <iostream>
#include <fstream>
#include <queue>
#include <vector>
#include <string>
#include <map>
#include <stack>
using namespace std;

const char* input  = "B-small-attempt0.in";
const char* output = "B-small-attempt0.out";


int main(int argc, char** argv) {
  
  ifstream I(input);
  ofstream O(output);

  int T; I >> T;
  for (int t = 0; t < T; ++t) {

    int X, Y; I >> X >> Y;

    O << "Case #" << (t + 1) << ": ";
    cout << "Case #" << (t + 1) << ": ";

    int x = 0, y = 0;
    int jump = 1;

    while (x != X || y != Y) {

      int dx = X - x;
      int dy = Y - y;

      int jx = 0;
      int jy = 0;

      if (abs(dx) < abs(dy) && dx != 0) {
        if (abs(dx) >= jump) {
          jx = (dx < 0) ? (-1) : (+1);
        }
        else if (abs(dy) >= jump) {
          jy = (dy < 0) ? (-1) : (+1);
        }
        else
          jx = (dx < 0) ? (+1) : (-1);
      }
      else {
        if (abs(dy) >= jump) {
          jy = (dy < 0) ? (-1) : (+1);
        }
        else if (abs(dx) >= jump) {
          jx = (dx < 0) ? (-1) : (+1);
        }
        else
          jy = (dy < 0) ? (+1) : (-1);
      }

      if (jx != 0) {
        x += jx*jump;
        O << ((jx > 0) ? ("E") : ("W"));
        cout << ((jx > 0) ? ("E") : ("W"));
      }
      else {
        y += jy*jump;
        O << ((jy > 0) ? ("N") : ("S"));
        cout << ((jy > 0) ? ("N") : ("S"));
      }
      ++jump;
    }

    O << endl;
    cout << endl;
  }


  I.close();
  O.close();
  return 0;
}
