#include <iostream>

using namespace std;

int main() {

  int ncases;
  cin >> ncases;

  for (int i = 0; i < ncases; i++) {
    int r, c, w;
    cin >> r >> c >> w;

    long long min_moves = (r-1)*(c/w) + (c/w) - 1;
    int nblocks = c%w + w;
    min_moves += min(nblocks, w+1);

    cout << "Case #" << i+1 << ": " << min_moves << endl;
  }
  return 0;
}
