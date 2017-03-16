#include <bits/stdc++.h>

using namespace std;

map<int, int> cnt;
int n;

void read() {
  cnt.clear();

  cin >> n;

  for (int i = 0; i < 2 * n - 1; ++i) {
    for (int j = 0; j < n; ++j) {
      int x;
      cin >> x;
      cnt[x]++;
    }
  }
}

void kill() {
  set<int> ans;
  for (auto p : cnt)
    if (p.second % 2 == 1)
      ans.insert(p.first);

  for (int x : ans)
    cout << x << " ";
  cout << endl;
}


int main() {
  int t;
  cin >> t;
  for (int i = 1; i <= t; ++i) {
    cout << "Case #" << i << ": ";
    read();
    kill();
    cerr << "Case #" << i << " done.\n";
  }
  return 0;
}
