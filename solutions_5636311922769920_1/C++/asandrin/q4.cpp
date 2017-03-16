#include <iostream>
using namespace std;

#define _ long long

int main() {

  _ T;
  cin >> T;
  for (_ t = 0; t < T; t++) {
    _ K, C, S;
    cin >> K >> C >> S;

    cout << "Case #" << t + 1 << ": ";
    if (S < (K-1)/C +1) {
      cout << "IMPOSSIBLE" << endl;
      continue;
    }

    _ p = 0;
    for (_ i = 0; i < (K-1)/C + 1; i++) {
      _ o = p++;
      for (_ j = 0; j < C - 1; j++) {
        o *= K;
        if (p < K) {
          o += p++;
        }
      }
      cout << o + 1 << " ";
    }
    cout << endl;
  }

  return 0;
}
