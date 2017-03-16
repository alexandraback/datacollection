#include <bits/stdc++.h>

using namespace std;

string s;

void read() {
  cin >> s;
}

void kill() {
  string ans;

  char mx = 'A';
  for (char c : s) {
    mx = max(mx, c);
    if (c == mx)
      ans = string(1, c) + ans;
    else
      ans += string(1, c);
  }

  cout << ans << endl;
}


int main() {
  int t;
  cin >> t;
  for (int i = 1; i <= t; ++i) {
    cout << "Case #" << i << ": ";
    read();
    kill();
    cerr << "Case #" << i << " done.\n";
  }
  return 0;
}
