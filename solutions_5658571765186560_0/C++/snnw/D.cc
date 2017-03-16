#include <iostream>

int max_other_side(int X, int side) {
	return X - side + 1;
}

int main() {
  int T;
  std::cin >> T;

  for (int test = 1; test <= T; test++) {
    int X, R, C;
    std::cin >> X >> R >> C;

    bool richard = false;

    if (R * C % X != 0) richard = true;
    if (R < X && C < X) richard = true;
    if (X >= R + 1 && C > 1 && R > 3) richard = true;
    if (X >= C + 1 && R > 1 && C > 3) richard = true;
    if (max_other_side(X, R + 1) > R) richard = true;
    if (max_other_side(X, C + 1) > C) richard = true;
    if (X >= 7) richard = true;

    printf("Case #%d: %s\n", test, richard ? "RICHARD" : "GABRIEL");
  }
}