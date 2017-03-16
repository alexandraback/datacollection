#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

typedef long long ll;

int main() {
  int T;
  cin >> T;
  for (int t = 0; t < T; t++) {
    cout << "Case #" << t + 1 << ": ";

    ll X, Y;
    cin >> X >> Y;

    ll curX = 0;
    ll curY = 0;
    ll turn = 1;
    ll dir = 1;
    while (X != curX) {
      char d = (dir > 0) ? 'E' : 'W';
      curX += turn * dir;
      cout << d;
      turn++;
      dir *= -1;
    }
    if (Y > 0)
      dir = -1;
    else
      dir = 1;
    while (Y != curY) {
      char d = (dir > 0) ? 'N' : 'S';
      curY += turn * dir;
      cout << d;
      turn++;
      dir *= -1;
    }

    cout << endl;
  }

  return 0;
}
