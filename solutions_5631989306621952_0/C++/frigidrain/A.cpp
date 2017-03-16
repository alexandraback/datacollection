#include <iostream>
#include <cstdio>
#include <sstream>

using namespace std;

string solve(string &s) {
  string res;
  for (int i = 0; i < s.length(); i++) {
    if (s[i] >= res[0]) {
      res = s[i] + res;
    } else {
      res = res + s[i];
    }
  }
  return res;
}

int main() {
  int T;
  cin >> T;
  for (int t = 1; t <= T; t++) {
    string s;
    cin >> s;
    printf("Case #%d: %s\n", t, solve(s).c_str());
  }
}
