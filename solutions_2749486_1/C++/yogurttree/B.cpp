#include <cstdio>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <map>
#include <vector>
#include <string>
#include <cassert>

using namespace std;

#define TEST(dx, dy, ch) {int nx = x + dx; int ny = y + dy; if (abs(nx) + abs(ny) < best) {newx = nx; newy = ny; best = abs(nx) + abs(ny); bestdir = ch;}}

int main () {
  int T;
  cin >> T;

  for (int i=0; i<T; i++) {
    int x, y;
    cin >> x;
    cin >> y;
    // n = number of steps
    int n=0;
    while (!(n*(n+1)/2 >= abs(x) + abs(y) &&
      ((n*(n+1)/2 - abs(x) + abs(y)) % 2) == 0)) {
      n += 1;
    }

    // now descend
    string moves;
    while (n > 0) {
      int newx = x;
      int newy = y;
      int best = INT_MAX;
      assert (((abs(x) + abs(y) - n*(n+1)/2) % 2) == 0 && abs(x) + abs(y) <= n*(n+1)/2);
      char bestdir = '?';
      TEST(n, 0, 'W')
      TEST(-n, 0, 'E')
      TEST(0, n, 'S')
      TEST(0, -n, 'N')
      moves = bestdir + moves;
      // cout << "n=" << n << ", going in dir " << bestdir << endl;
      n -= 1;
      x = newx;
      y = newy;
      // cout << "(x,y) = (" << x << ", " << y << ")" << endl;
    }


    cout << "Case #" << (i+1) << ": " << moves << endl;
  }

  return 0;
}
