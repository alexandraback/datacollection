#include <iostream>
#include <string>
#include <stdio.h>


namespace {
  using namespace std;
  int T;
  int R;
  int C;
  int W;

  void input() {
    cin >> R >> C >> W;
  }

  void solve(const int case_num) {
    const int answer = C / W * R + W - 1 + (C % W == 0 ? 0 : 1);
    printf("Case #%d: %d\n", case_num, answer);
  }
}

int main() {
  cin >> T;
  for (int t = 0; t < T; ++t) {
    input();
    solve(t + 1);
  }
  return 0;
}
