#include <iostream>

using namespace std;

void f(int T) {
  int R, C, W;
  cin >> R >> C >> W;
  int count = C % W == 0
    ? (C / W) - 1 + W
    : (C / W) + W;
  cout << "Case #" << T << ": " << count * R << endl;
}

int main() {
  int T;
  cin >> T;
  for (int i = 1; i <= T; ++i) {
    f(i);
  }
}
