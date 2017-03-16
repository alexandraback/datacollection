#include <iostream>
#include <functional>
using namespace std;

int J, P, S, K;

void solve() {
  int m = min(S, K);
  cout << m * J * P << endl;
  for (int i = 0; i < m; ++i) {
    for (int j = 0; j < J; ++j) {
      for (int p = 0; p < P; ++p) {
        int q = (p + j + i) % S;
        cout << j + 1 << " " << p + 1 << " " << q + 1 << endl;
      }
    }
  }
}

int main() {
  int T;
  cin >> T;
  for (int i = 0; i < T; ++i) {
    cin >> J >> P >> S >> K;
    cout << "Case #" << i + 1 << ": ";
    solve();
  }
  return 0;
}
