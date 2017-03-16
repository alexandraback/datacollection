#include <iostream>
#include <string>
#include <cstdio>
#include <queue>
#include <algorithm>
using namespace std;


int X, R, C;

bool s() {
  int minw = (X+1)/2;

  if (((R*C) % X) != 0) return false;
  if (X > R && X > C) return false;
  if (minw > R || minw > C) return false;

  if (X >= 7) return false;
  if (X <= 3) return true;

  if (X == 4) {
    if (R == 2 || C == 2) return false;
    else return true;
  }

  if (X == 5) return true;

  if (X == 6) {
    if (R == 3 || C == 3) return false;
    else return true;
  }
}

void solve(int CASE) {
  cin >> X >> R >> C;

  bool ok = s();

  printf("Case #%d: %s\n", CASE, ok?"GABRIEL":"RICHARD");
}

int main() {
  int T;

  cin >> T;

  for (int i = 1; i <= T; i++) {
    solve(i);
  }

  return 0;
}
