#include <iostream>
using namespace std;

int solve(int r, int t) {
  int k = 1;
  while (true) {
    int cost = 2*r + 4*k - 3;
    if (cost <= t) {
      t -= cost;
      k++;
    } else {
      return k-1;
    }
  }
}

int main() {
  int T; cin >> T;
  for (int ts = 1; ts <= T; ts++) {
    int r, t; cin >> r >> t;
    cout << "Case #" << ts << ": " << solve(r, t) << endl;
  }
  return 0;
}

