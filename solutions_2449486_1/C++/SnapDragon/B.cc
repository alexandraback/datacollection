#include <algorithm>
#include <cstring>
#include <iostream>
using namespace std;

int X, Y, g[101][101], u[101][101];

main() {
  int T, prob=1;
  for (cin >> T; T--;) {
    cout << "Case #" << prob++ << ": ";
    cin >> Y >> X;
    for (int y = 0; y < Y; y++)
    for (int x = 0; x < X; x++)
      cin >> g[y][x];
    memset(u, 0, sizeof(u));
    for (int y = 0; y < Y; y++) {
      int mx = 0;
      for (int x = 0; x < X; x++) mx = max(mx, g[y][x]);
      for (int x = 0; x < X; x++) if (g[y][x] == mx) u[y][x] = true;
    }
    for (int x = 0; x < X; x++) {
      int mx = 0;
      for (int y = 0; y < Y; y++) mx = max(mx, g[y][x]);
      for (int y = 0; y < Y; y++) if (g[y][x] == mx) u[y][x] = true;
    }
    bool valid = true;
    for (int y = 0; y < Y; y++)
    for (int x = 0; x < X; x++)
      if (!u[y][x]) valid = false;
    cout << (valid ? "YES" : "NO") << endl;
  }
}
