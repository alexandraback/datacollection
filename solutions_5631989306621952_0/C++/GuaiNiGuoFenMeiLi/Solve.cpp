#include <bits/stdc++.h>

using namespace std;

string s;

int main() {
  freopen("A-small-attempt0.in", "r", stdin);
  freopen("A-small-attempt0.out", "w", stdout);

  int T;
  cin >> T;
  for (int test = 1; test <= T; ++test) {
    cin >> s;
    string t = "";
    for (int i = 0; i < (int)s.size(); ++i) {
      string u = t + s[i];
      string v = s[i] + t;
      if (u > v) {
        t = u;
      } else {
        t = v;
      }
    }
    cout << "Case #" << test << ": "<< t << endl;
  }
  return 0;
}
