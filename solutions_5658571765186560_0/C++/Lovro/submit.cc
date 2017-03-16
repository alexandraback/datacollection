#define NDEBUG
#include <algorithm>
#include <cstdio>
#include <iostream>
using namespace std;


bool solve(int X, int R, int C) {
  if (X >= 7) {
    return false;
  }
  if (R * C % X != 0) {
    return false;
  }
  if (X > max(R, C)) {
    return false;
  }
  if (X >= 2 * min(R, C) + 1) {
    return false;
  }
  if (X == 4 && min(R, C) == 2) {
    return false;
  }
  return true;
}

int main() {
  ios_base::sync_with_stdio(0);

  int T;
  cin >> T;
  for (int tt=1; tt<=T; ++tt) {
    int X, R, C;
    cin >> X >> R >> C;
    printf("Case #%d: %s\n", tt, solve(X, R, C) ? "GABRIEL" : "RICHARD");
  }
}
