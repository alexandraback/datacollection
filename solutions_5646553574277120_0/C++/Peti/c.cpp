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
    int c,d,v;
    cin >> c >> d >> v;
    vector<int> coin(d,0);
    for (int i = 0; i < d; ++i) cin >> coin[i];

    sort(coin.begin(), coin.end());
    int goodUntil = 0;
    int res = 0;
    for (int i = 0; i < d; ++i) {
      while (goodUntil + 1 < coin[i]) {
        ++res;
        goodUntil += c * (goodUntil + 1);
      }
      goodUntil += c * coin[i];
    }
    while (goodUntil < v) {
      ++res;
      goodUntil += c * (goodUntil + 1);
    }

    cout << "Case #" << tt << ": " << res << endl;
  }
  return 0;
}
