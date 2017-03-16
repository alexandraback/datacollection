#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <queue>

using namespace std;

int main() {
  int T; cin >> T;
  for (int t = 1; t <= T; t++) {
    int N, J;
    cin >> N >> J;
    cout << "Case #" << t << ":\n";

    int b = N / 2 - 1;
    for (int i = 0; i < J; i++) {
      string S(N, '0');
      S[0] = S[N - 1] = '1';
      for (int j = 0; j < b; j++) {
        if (i & 1 << j) {
          S[1 + 2 * j] = '1';
          S[2 + 2 * j] = '1';
        }
      }

      cout << S << " 3 4 5 6 7 8 9 10 11\n";
    }
  }
  return 0;
}
