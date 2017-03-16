#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

int ans(string s) {
  int cnt = 0;
  for (int i = s.length() - 1; i >= 0; i--) {
    cnt += (s[i] == '+') ^ (cnt % 2 == 0);
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
