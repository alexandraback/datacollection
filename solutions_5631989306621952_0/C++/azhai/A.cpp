#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cassert>

using namespace std;

int counts[30];
char answer[2000];
int cur_left, cur_right;
string S;

void init() {
  cin >> S;
  for (int i = 0; i < 30; i++)
    counts[i] = 0;
  for (int i = 0; i < S.length(); i++) {
    counts[S[i] - 'A']++;
  }
  cur_left = 0;
  cur_right = S.length();
}

void solve_case(int t) {
  init();

  int last_idx = 25;

  for (int i = S.length() - 1; i >= 0; i--) {
    while (counts[last_idx] == 0) {
      last_idx--;
      assert(last_idx >= 0);
    }

    counts[S[i] - 'A']--;
    if (S[i] - 'A' == last_idx) {
      answer[cur_left] = S[i];
      cur_left++;
    } else {
      answer[cur_right - 1] = S[i];
      cur_right--;
    }
  }

  cout << "Case #" << t << ": ";
  for (int i = 0; i < S.length(); i++)
    cout << answer[i];
  cout << "\n";
}

int main() {
  int T;
  cin >> T;

  for (int i = 0; i < T; i++) {
    solve_case(i + 1);
  }

  return 0;
}
