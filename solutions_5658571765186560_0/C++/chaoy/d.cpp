#include <iostream>
#include <string>
#include <exception>
using namespace std;

string run() {
  int X, R, C;
  cin >> X >> R >> C;
  if (R > C) {
    swap(R, C);
  }
  if (X < 4) {
    if (R == 1 && C == 3 && X == 3) return "RICHARD";
    return R * C % X == 0 ? "GABRIEL" : "RICHARD";
  }
  if (X == 4) {
    if (C == 4 && (R == 3 || R == 4)) {
      return "GABRIEL";
    }
    return "RICHARD";
  }
  throw runtime_error("Too hard, stay tuned");
}

int main() {
  int T;
  cin >> T;
  for (int t = 1; t <= T; t++) {
    cout << "Case #" << t << ": " << run() << endl;
  }
  return 0;
}
