#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int r, c, w;
int solve() {
  return (c / w) * r + w - (c % w == 0);
}

int main() {
  ios::sync_with_stdio(0);
  int tc;
  cin >> tc;
  for (int cs = 1; cs <= tc; ++cs) {
    cout << "Case #" << cs << ":";
    cin >> r >> c >> w;
    cout << ' ' << solve();
    cout << endl;
  }
  return 0;
}
