#include <bits/stdc++.h>

using namespace std;

char opposite(char c) {
  return c == '+' ? '-' : '+';
}

string compress(const string &s) {
  string result = "";
  char c = '\0';

  for (int i = 0; i < s.size(); i++) {
    if (s[i] != c) {
      result += s[i];
      c = s[i];
    }
  }

  return result;
}

int f(string s) {
  s += '+';
  s = compress(s);

  return s.size() - 1;
}

void solve(int case_id) {
  string s; cin >> s;

  cout << "Case #" << case_id << ": " << f(s) << "\n";
}

int main() {
  int cases; cin >> cases;

  for (int i = 1; i <= cases; i++) {
    solve(i);
  }

  return 0;
}