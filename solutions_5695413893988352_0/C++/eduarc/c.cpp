#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(false);cout.tie(0);cin.tie(0);
using namespace std;

void ways(string s, vector<string> &v) {

  int marks = 0;
  for (int i = 0; i < s.length(); i++) {
    if (s[i] == '?') {
      marks++;
      for (int d = 0; d < 10; d++) {
        s[i] = d+'0';
        ways(s, v);
      }
    }
  }
  if (!marks) {
    v.push_back(s);
  }
}

void solve() {
 
  string c, j;
  cin >> c >> j;

  vector<string> C, J;
  ways(c, C);
  ways(j, J);

  sort(C.begin(), C.end());
  sort(J.begin(), J.end());
  int diff = 1e9;
  for (string sa : C) {
    for (string sb : J) {
      int a = atoi(sa.c_str());
      int b = atoi(sb.c_str());
      if (abs(a-b) < diff) {
        diff = abs(a-b);
      }
    }
  }
  for (string sa : C) {
    for (string sb : J) {
      int a = atoi(sa.c_str());
      int b = atoi(sb.c_str());
      if (abs(a-b) == diff) {
        cout << sa << " " << sb;
        return;
      }
    }
  }
}

int main() { _
  int tt;
  cin >> tt;
  for (int t = 1; t <= tt; t++) {
    cout << "Case #" << t << ": ";
    solve();
    cout << endl;
  }
  return 0;
}
