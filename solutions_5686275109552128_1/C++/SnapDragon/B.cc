#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

main() {
  int T, D, prob=1;
  for (cin >> T; T--;) {
    cin >> D;
    vector<int> v(D);
    for (int i = 0; i < D; i++) cin >> v[i];

    int ret = 1000000000;
    for (int x = 1; x <= 1000; x++) {
      int cur = 0;
      for (int i = 0; i < D; i++) cur += (v[i]-1)/x;
      ret = min(ret, cur + x);
    }

    cout << "Case #" << prob++ << ": " << ret << endl;
  }
}
