#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
  int T; cin >> T;
  for (int zz=1; zz <= T; zz++) {
    cout << "Case #" << zz << ":";
    int K, C, S; cin >> K >> C >> S;
    if (K > S*C) {
      cout << " IMPOSSIBLE" << endl;
      continue;
    }
    for (int i=0; i < K; i += C) {
      ll v = 0;
      for (int j=0; j < C; j++) {
        ll x = min(K-1, i+j);
        v = v * K + x;
      }
      cout << " " << v+1;
    }
    cout << endl;
  }
  return 0;
}
