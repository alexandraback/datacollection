#include <iostream>
#include <iomanip>
#include <cstring>
#include <map>
using namespace std;

int main() {
  int t; cin >> t;
  for (int c = 1; c <= t; c++) {
    int k, l, s; cin >> k >> l >> s;
    string keys, target; cin >> keys >> target;
    map<char, int> ct;
    for (int i = 0; i < k; i++) ct[keys[i]]++;

    int maxp = 0;
    for (int i = l-1; i >= 1; i--) {
      int len = l - i;
      bool prefix = true;
      for (int j = 0; j < len; j++) prefix = prefix && target[j] == target[i+j];
      if (prefix) maxp = len;
    }
    int maxt = 1 + (s - l) / (l - maxp);
    for (int i = 0; i < l; i++)
      if (ct[target[i]] == 0)
        maxt = 0;

    double expt = s - l + 1;
    for (int i = 0; i < l; i++) expt *= 1.0 * ct[target[i]] / k;

    // cout << maxp << " " << maxt << " " << expt << endl;
    cout << "Case #" << c << ": " << fixed << setprecision(8) << maxt - expt << endl;
  }
  return 0;
}
