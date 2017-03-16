#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

bool grid[100];

int ans(string s) {
  for (int i = 0; i < s.length(); i++) {
    grid[i] = s[i] == '+';
  }

  int cnt = 0;
  for (int i = s.length() - 1; i >= 0; i--) {
    if (!grid[i]) {
      for (int j = 0; j <= i; j++) {
        grid[j] = !grid[j];
      }
      cnt++;
    }
  }
  return cnt;
}

int main() {
  int t;
  string s;
  cin >> t;
  for (int caseno = 1; caseno <= t; caseno++) {
    cin >> s;
    printf("Case #%i: %i\n", caseno, ans(s));
  }
}
