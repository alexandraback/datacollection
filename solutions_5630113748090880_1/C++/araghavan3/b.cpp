#include <bits/stdc++.h>

using namespace std;

map<int, int> cm;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  int T; cin >> T;
  for (int i = 0; i < T; i++) {
    int N; cin >> N;
    cm.clear();
    vector<int> ret;
    for (int _ = 0; _ < 2 * N - 1; _++ ) {
      for (int j = 0; j < N; j++) {
        int x; cin >> x;
        if (cm.count(x)) cm[x]++;
        else cm[x] = 1;
      }
    }

    for (auto& p : cm) {
      if (p.second % 2 != 0) {
        ret.push_back(p.first);
      }
    }

    sort(ret.begin(), ret.end());
    cout << "Case #" << (i + 1) << ": ";
    for (int j = 0; j < ret.size(); j++) {
      cout << ret[j];
      if (j != ret.size() - 1) cout << " ";
    }
    cout << endl;
  }

  return 0;
}
