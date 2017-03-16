#include <iostream>

using namespace std;

int solve(string s) {
  int moves = 0;
  for (int i = 1; i < int(s.size()); ++i) {
    if (s[i - 1] != s[i]) {
      ++moves;
    }
  }
  if (s[int(s.size()) - 1] == '-') {
    ++moves;
  }
  return moves;
}

int main() {
  int T;
  cin >> T;
  for (int ca = 1; ca <= T; ++ca) {
    string s;
    cin >> s;
    cout << "Case #" << ca << ": " << solve(s) << endl;
  }
}
