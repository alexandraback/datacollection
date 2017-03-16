#include <iostream>
#include <vector>
#include <cassert>
using namespace std;

int solve() {
  int r, c, w;
  cin >> r >> c >> w;

  int res = (r - 1)*(2*w <= c ? 2 + c - 2*w: 1);
  if (2*w <= c) return c/w + (c%w == 0 ? w - 1 : w) + res;
  return min(c, w + 1) + res;
}

int main() {
  int casos;
  cin >> casos;
  for (int cas = 1; cas <= casos; ++cas) {
    cout << "Case #" << cas << ": " << solve() << endl;
  }
}
