#include <iostream>
#include <map>
#include <functional>
#include <vector>
using namespace std;

int main() {
  int t, C = 1;
  cin >> t;
  int e, r, n;
  while (t-- && cin >> e >> r >> n) {
    int k;
    vector<int> v;
    for (int i = 0; i < n; ++i) {
      cin >> k;
      v.push_back(k);
    }

    map<pair<int, int>, int> cache;

    function<int(int, int)> dp = [&](int c, int x) {
      if (cache.find(make_pair(c, x)) != cache.end()) {
        return cache[make_pair(c, x)];
      }

      if (x == n) return 0;

      int m = 0;
      for (int i = 0; i <= c; ++i) {
        m = max(m, i*v[x] + dp(min(e, c - i + r), x + 1));
      }

      return cache[make_pair(c, x)] = m;
    };

    cout << "Case #" << C++ << ": " << dp(e, 0) << endl;
  }
}
