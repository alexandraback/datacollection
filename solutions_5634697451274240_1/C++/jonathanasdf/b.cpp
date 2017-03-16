#include <bits/stdc++.h>
using namespace std;
int main() {
  int T; cin >> T;
  for (int zz=1; zz <= T; zz++) {
    cout << "Case #" << zz << ": ";
    string s; cin >> s;
    int cnt = 0;
    for (int i=0; i < s.size()-1; i++) {
      if (s[i] != s[i+1]) cnt++;
    }
    if (s[s.size()-1] == '-') cnt++;
    cout << cnt << endl;
  }
  return 0;
}
