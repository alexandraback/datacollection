#include <iostream>
using namespace std;

int main() {
  int T, K, C, S, prob=1;
  for (cin >> T; T--;) {
    cin >> K >> C >> S;
    cout << "Case #" << prob++ << ":";
    if (S*C < K) {
      cout << " IMPOSSIBLE" << endl;
      continue;
    }
    long long v = 0;
    for (int x = 0; x < K; x++) {
      v = (v*K) + x;
      if (x%C == C-1 || x == K-1) {
        cout << ' ' << v+1;
        v = 0;
      }
    }
    cout << endl;
  }
}
