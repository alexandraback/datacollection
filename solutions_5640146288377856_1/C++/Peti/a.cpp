#include <iostream>
#include <iomanip>
#include <cassert>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
  int t;
  cin >> t;
  for (int tt = 1; tt <= t; ++tt) {
    int r,c,w;
    cin >> r >> c >> w;

    int res = c / w;
    res *= r;
    res += w;
    if (c % w == 0) res -= 1; 

    cout << "Case #" << tt << ": " << res << endl;
  }
  return 0;
}
