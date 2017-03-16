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
    string S; cin >> S;

    string T;
    for (int i = 0; i < S.size(); i++) {
      string T0 = S[i] + T;
      string T1 = T + S[i];
      T = max(T0, T1);
    }

    cout << "Case #" << t << ": " << T << endl;
  }
  return 0;
}
