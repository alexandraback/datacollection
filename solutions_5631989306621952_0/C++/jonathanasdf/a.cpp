#include <bits/stdc++.h>
using namespace std;

int main() {
  int T; cin >> T;
  for (int zz=1; zz <= T; zz++) {
    cout << "Case #" << zz << ": ";
    string s; cin >> s;
    string t = string(1, s[0]);
    for (int i=1; i < s.size(); i++) {
      if (s[i] >= t[0]) t = string(1, s[i])+t;
      else t = t+s[i];
    }
    cout << t << endl;
  }
  return 0;
}
