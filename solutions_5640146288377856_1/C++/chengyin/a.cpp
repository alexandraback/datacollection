#include <iostream>
#include <cassert>

using namespace std;

int solve(int R, int C, int W) {
   int shift = (C - W) / W;
   return ((R - 1) * (1 + shift)) + shift + ((C % W) ? 1 : 0) + W;
}

int main() {
   int T; cin >> T;
   for (int i = 1; i <= T; ++i) {
      int R, C, W; cin >> R >> C >> W;
      cout << "Case #" << i << ": " << solve(R, C, W) << endl;
   }
   return 0;
}

