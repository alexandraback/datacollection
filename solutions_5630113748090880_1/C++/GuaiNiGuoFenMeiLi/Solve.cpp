#include <bits/stdc++.h>

using namespace std;

int main() {
  freopen("B-large.in", "r", stdin);
  freopen("B-large.out", "w", stdout);

  int T;
  cin >> T;
  for (int test = 1; test <= T; ++test) {
    map<int, int> cnt;
    int n;
    cin >> n;
    for (int i = 0; i < n * (2 * n - 1); ++i) {
      int v;
      cin >> v;
      cnt[v]++;
    }
    vector<int> vec;
    for (map<int, int>::iterator it = cnt.begin(); it != cnt.end(); ++it) {
      if ((*it).second & 1) {
        vec.push_back((*it).first);
      }
    }
    sort(vec.begin(), vec.end());
    cout << "Case #" << test << ":";
    for (int i = 0; i < n; ++i) {
      cout << " " << vec[i];
    }
    cout << endl;
  }
  return 0;
}
