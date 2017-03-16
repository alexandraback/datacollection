#include <bits/stdc++.h>

using namespace std;

int main() {
  int T; cin >> T;

  for (int i = 0; i < T; i++) {
    string s; cin >> s;
    string ret = s.substr(0, 1);
    for (int j = 1; j < s.size(); j++) {
      string n = s.substr(j, 1);
      if (s[j] >= ret[0]) ret = n + ret;
      else ret += s[j];
    }

    cout << "Case #" << (i + 1) << ": " << ret << endl;
  }

  return 0;
}
