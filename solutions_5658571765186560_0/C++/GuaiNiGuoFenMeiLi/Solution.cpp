#include <cstdio>
#include <iostream>
#include <algorithm>

using namespace std;

int ntests, x, r, c;

bool win() {
  if (x == 1) return false;
  else if (x == 2) return (r * c) % 2 != 0;
  else if (x == 3) {
    if ((r * c) % 3 != 0) return true;
    else if (r == 1 || c == 1) return true;
    else return false;
  } else {
    if (r == 4 && c == 4) return false;
    else if (r == 4 && c == 3) return false;
    else if (r == 3 && c == 4) return false;
    else return true;
  }
}

int main() {
  freopen("D-small-attempt3.in", "r", stdin);
  freopen("D-small-attempt3.out", "w", stdout);
  cin >> ntests;
  for (int test = 1; test <= ntests; ++test) {
    cin >> x >> r >> c;
    cout << "Case #" << test << ": " << (win() ? "RICHARD" : "GABRIEL") << endl;
  }
  return 0;
}
