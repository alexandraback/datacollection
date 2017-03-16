#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cassert>

using namespace std;

string S;

void init() {
  cin >> S;
}

void solve_case(int t) {
  init();

  char c = '+';
  int ans = 0;
  for (int i = S.length() - 1; i >= 0; i--) {
    if (S[i] != c) {
      ans++;
      c = S[i];
    }
  }

  cout << "Case #" << t << ": " << ans << "\n";
}

int main() {
  int T;
  cin >> T;

  for (int i = 0; i < T; i++) {
    solve_case(i + 1);
  }

  return 0;
}
