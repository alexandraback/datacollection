#include <bits/stdc++.h>
using namespace std;

int main() {
  int TT;
  cin >> TT;
  for (int tt = 0; tt < TT; ++tt) {
    int n;
    cin >> n;
    map<int, int> m;
    for (int i = 0; i < 2 * n - 1; ++i)
      for (int j = 0; j < n; ++j) {
        int a;
        cin >> a;
        m[a]++;
      }
    vector<int> res;
    for (auto it : m)
      if (it.second % 2 == 1)
        res.push_back(it.first);
    sort(res.begin(), res.end());
    assert(res.size() == n);
    cout << "Case #" << tt + 1 << ":";
    for (int x : res)
      cout  << ' ' << x;
    cout << endl;
  }
}
