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
    long long K, C, S;
    cin >> K >> C >> S;

    cout << "Case #" << t << ":";
    if (C * S < K) {
      cout << " IMPOSSIBLE" << endl;
      continue;
    }

    for (int i = 0; i < K; i += C) {
      long long p = 0;
      for (int j = 0; j < C; j++) {
        p = p * K + min(K - 1, 0ll + i + j);
      }
      cout << ' ' << p + 1;
    }
    
    cout << endl;
  }
  return 0;
}
