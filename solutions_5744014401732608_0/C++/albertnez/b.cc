#include <iostream>
#include <vector>
using namespace std;
using ll = long long;
int main() {
  int T; cin >> T;
  int ncase = 0;
  while (T--) {
    ll b, m;
    cin >> b >> m;
    cout << "Case #" << ++ncase << ": ";
    if (m > (1LL<<(b-2))) {
      cout << "IMPOSSIBLE" << endl;
      continue;
    }
    cout << "POSSIBLE" << endl;
    for (int i = 0; i < b-1; ++i) cout << (i>0);
    cout << (m == (1LL<<(b-2))) << endl;
    if (m == (1LL<<(b-2))) --m;
    for (int i = 1; i < b-1; ++i) {
      for (int j = 0; j < b-1; ++j) cout << (j>i);
      cout << (m&1) << endl;
      m /= 2;
    }
    cout << string(b, '0') << endl;
  }
}
