#include <iostream>
using namespace std;

int main() {
  int t; cin >> t;
  for (int c = 1; c <= t; c++) {
    int m, n, w; cin >> m >> n >> w;
    int res = (m - 1) * n / w;
    if (n % w == 0) res += n / w + w - 1;
    else res += n / w + w;
    cout << "Case #" << c << ": " << res << endl;
  }
  return 0;
}
