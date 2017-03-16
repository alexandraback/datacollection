#include <iostream>

using namespace std;

int calculateMinimumMoves(int R, int C, int W) {
  int rowMoves = (C-W)/W;
  int movesToEliminate = (C-W)/W + 1;
  if (C % W > 0) ++rowMoves;
  rowMoves += W;
  return rowMoves + (R-1)*movesToEliminate;
}

int main(int argc, char *argv[]) {
  int T;
  cin >> T;
  for (int i = 0; i < T; ++i) {
    int R, C, W;
    cin >> R >> C >> W;
    cout << "Case #" << i + 1 << ": "
         << calculateMinimumMoves(R, C, W)
         << endl;
  }
  return 0;
}
