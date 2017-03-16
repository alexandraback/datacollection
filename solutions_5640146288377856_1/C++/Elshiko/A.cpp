#include <iostream>
#include <fstream>

using namespace std;

int main() {
  ifstream cin("A-large.in");
  ofstream cout("A-large.out");
  int tests;
  cin >> tests;
  for (int test = 1; test <= tests; ++test) {
    int r, c, w;
    cin >> r >> c >> w;
    int ans = c / w;
    ans *= r;
    if (c % w == 0)
      ans += (w - 1);
    else
      ans += w;
    cout << "Case #" << test << ": " << ans << "\n";
  }
  return 0;
}
