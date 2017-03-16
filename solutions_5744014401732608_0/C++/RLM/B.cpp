#include <iostream>
#include <vector>
using namespace std;

typedef long long int ll;

int main() {
  vector<ll> v(50);
  v[0] = v[1] = 1;
  for (int i = 2; i < 50; ++i) v[i] = v[i-1]*2;
  int T; cin >> T;
  for (int t = 1; t <= T; ++t) {
    int B, M; cin >> B >> M;
    cout << "Case #" << t << ": ";
    if (M > v[B-1]) cout << "IMPOSSIBLE\n";
    else {
      cout << "POSSIBLE\n";
      vector<int> sl(B-1, 0);
      for (int j = B-2; j >= 0; --j) {
        if (v[j] <= M) {
          sl[j] = 1;
          M -= v[j];
        }
      }
      for (int i = 0; i < B-1; ++i) {
        for (int j = 0; j < B-1; ++j) {
          if (i < j) cout << '1';
          else cout << '0';
        }
        cout << sl[i] << endl;
      }
      cout << string(B, '0') << endl;
    }
  }
}