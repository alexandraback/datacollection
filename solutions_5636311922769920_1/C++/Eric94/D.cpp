#include <iostream>
using namespace std;

void solve() {
  int K, C, S;
  cin >> K >> C >> S;

  if (K > C*S) {
    cout << " IMPOSSIBLE";
    return;
  }

  for (int i = 0; i < K; i += C) {
    long long ans = i;
    for (int j = 1; j < C; ++j) {
      int add = i + j;
      add = min (add, K - 1);
      ans = ans*K + add;
    }
    cout << ' ' << ans + 1;
  }
}

int main() {
  int T;
  cin >> T;
  for (int i = 0; i < T; ++i) {
    cout << "Case #" << i + 1 << ":";
    solve();
    cout << endl;
  }
}
