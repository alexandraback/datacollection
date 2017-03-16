#include <bits/stdc++.h>

using namespace std;

int solve(string s) {
  int n = s.size();
  vector<int> p;
  vector<int> m;
  p.push_back(0);
  m.push_back(0);

  for (int i=1;i<=n; i++) {
    if (s[i-1]=='+') {
      p.push_back(min(m[i-1] + 1, p[i-1]));
      m.push_back(min(p[i-1]+1, m[i-1]+2));
    }
    if (s[i-1]=='-') {
      p.push_back(min(m[i-1]+1, p[i-1]+2));
      m.push_back(min(p[i-1]+1, m[i-1]));
    }
    p[i] = min(p[i], m[i]+1);
    m[i] = min(m[i], p[i]+1);
  }
  return p[n];
}

int main() {
  ios_base::sync_with_stdio(false);
  freopen("B-small-attempt0.in", "r", stdin);
  freopen("ki.txt", "w", stdout);
  int t;
  cin >> t;
  for (int i=0;i<t;i++) {
    string s;
    cin >> s;
    cout << "Case #" << i+1<<": ";
    cout << solve(s);
    cout<<endl;
  }
  return 0;
}
