#include <cstdio>
#include <iostream>
#include <algorithm>

using namespace std;

int main() {

  int TC;

  cin >> TC;

  for (int tc = 1; tc <= TC; tc++) {
    int X, R, C;
    cin >> X >> R >> C;

    int width = max(R, C);
    int height = min(R, C);

    bool result = false;
    if ( (width * height) % X == 0 && width >= X && height >= X-1 ) result = true;

    printf("Case #%d: %s\n", tc, (result)? "GABRIEL" : "RICHARD");
  }

  return 0;
}
