#include <iostream>
using namespace std;

typedef long long int LLI;

int main() {
  int T, K, C, S;
  cin >> T;
  for (int i = 0; i < T; ++i) {
    cin >> K >> C >> S;
    cout << "Case #" << i + 1 << ":";
    // assume S == K
    for (int j = 0; j < S; ++j) {
      LLI a = j;
      for (int k = 0; k < C - 1; ++k) {
        a *= K;
        a += j;
      }
      ++a;
      cout << " " << a;
    }
    cout << endl;
  }
  return 0;
}
