#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>
#include <algorithm>
#include <cassert>

using namespace std;

const int S_MAX = 2000;
int S;
int counts[S_MAX];

void init() {
  cin >> S;
  string s;
  cin >> s;
  assert(s.length() == S + 1);
  for (int i = 0; i < s.length(); i++) {
    counts[i] = s[i] - '0';
  }
}

void solve_case(int t) {
  init();

  int num_needed = 0;
  int ct = 0;
  for (int i = 0; i <= S; i++) {
    int deficit = i - ct;
    num_needed = max(deficit, num_needed);
    ct += counts[i];
  }
  cout << "Case #" << t << ": " << num_needed << "\n";
}

int main() {
  int T;
  cin >> T;

  for (int i = 0; i < T; i++) {
    solve_case(i + 1);
  }

  return 0;
}
