#include <iostream>
#include <iomanip>
#include <cassert>
#include <vector>

using namespace std;

int main() {
  int t;
  cin >> t;
  for (int tt = 1; tt <= t; ++tt) {
    int k,l,s;
    string keyboard, target;
    cin >> k >> l >> s;
    cin >> keyboard;
    cin >> target;
    assert(keyboard.size() == k);
    assert(target.size() == l);

    int minDispl = 1;
    while (minDispl < l
           && target.substr(minDispl, l - minDispl)
              != target.substr(0, l - minDispl)) ++minDispl;
    int maxBananas = 1 + ((s - l) / minDispl);

    vector<int> numChar(256, 0);
    for (int i = 0; i < k; ++i) ++numChar[keyboard[i]];
    vector<double> chanceChar(256, 0);
    for (int i = 0; i < 256; ++i) chanceChar[i] = (double)numChar[i] / (double)k;

    double expectedBananas = 1.0;
    for (int i = 0; i < l; ++i) {
      if (numChar[target[i]] == 0) {
        expectedBananas = 0.0;
        maxBananas = 0.0;
      }
      expectedBananas *= chanceChar[target[i]];
    }
    expectedBananas *= (s + 1 - l);

    cout << "Case #" << tt << ": " << setprecision(7)
         << maxBananas - expectedBananas << endl;
  }
  return 0;
}
