#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
  int T;
  cin >> T;
  for (int t = 1; t <= T; t++) {
    int smax;
    string S;
    cin >> smax >> S;
    int res = 0;
    int sm = 0;
    for (int i = 0; i <= smax; i++) {
      if (S[i] == '0') {
        continue;
      }
      res = max(res, i - sm);
      sm += S[i] - '0';
    }
    cout << "Case #" << t << ": " << res << '\n';
  }
  return 0;
}
