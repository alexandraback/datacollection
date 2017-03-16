#include <iostream>

using namespace std;

int main() {
  int tt;
  cin >> tt;
  for (int t = 1; t <= tt; t++) {
    int r, c, w;
    cin >> r >> c >> w;
    int ans = c/w;
    ans *= r;
    ans += w-1;
    ans += ((c%w)?1:0);
    cout << "Case #" << t << ": " << ans << "\n";
  }
}