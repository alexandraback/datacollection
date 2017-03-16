#include <iostream>
using namespace std;

int main() {
  int t;
  cin >> t;
  for (int tt = 1; tt <= t; ++tt) {
    int a, b, k;
    cin >> a >> b >> k;
    int res = 0;
    for (int aa = 0; aa < a; ++aa) {
      for (int bb = 0; bb < b; ++bb) {
        if ((aa & bb) < k) ++res;
      }
    }
    cout << "Case #" << tt << ": " << res << endl;
  }
}
