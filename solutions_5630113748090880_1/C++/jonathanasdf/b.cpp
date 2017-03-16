#include <bits/stdc++.h>
using namespace std;

int main() {
  int T; cin >> T;
  for (int zz=1; zz <= T; zz++) {
    cout << "Case #" << zz << ":";
    int N; cin >> N;
    map<int, int> cnt;
    for (int i=0; i < 2*N-1; i++) for (int j=0; j < N; j++) {
      int c; cin >> c;
      cnt[c]++;
    }
    for (auto p : cnt) {
      if (p.second%2) cout << " " << p.first;
    }
    cout << endl;
  }
  return 0;
}
