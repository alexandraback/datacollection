#include <iostream>
using namespace std;

typedef long long int LLI;

int main() {
  int T, K, C, S;
  cin >> T;
  for (int i = 0; i < T; ++i) {
    cin >> K >> C >> S;
    cout << "Case #" << i + 1 << ":";
    if (C * S < K) {
      cout << " IMPOSSIBLE" << endl;
      continue;
    }
    int N = (K + C - 1) / C;
    int c = 0;
    for (int i = 0; i < N; ++i) {
      LLI a = 0;
      for (int j = 0; j < C; ++j) {
        a *= K;
        a += c;
        c = (c + 1) % K;
      }
      ++a;
      cout << " " << a;
    }
    cout << endl;
  }
  return 0;
}
