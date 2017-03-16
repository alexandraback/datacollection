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
    long long c,d,v;
    cin >> c >> d >> v;
    vector<long long> coin(d,0);
    for (int i = 0; i < d; ++i) cin >> coin[i];

    sort(coin.begin(), coin.end());
    long long goodUntil = 0;
    int res = 0;
    for (int i = 0; i < d; ++i) {
      while (goodUntil + 1LL < coin[i]) {
        ++res;
        goodUntil += c * (goodUntil + 1LL);
      }
      goodUntil += c * coin[i];
    }
    while (goodUntil < v) {
      ++res;
      goodUntil += c * (goodUntil + 1LL);
    }

    cout << "Case #" << tt << ": " << res << endl;
  }
  return 0;
}
