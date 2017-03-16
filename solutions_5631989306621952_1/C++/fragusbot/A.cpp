#include <bits/stdc++.h>

using namespace std;

int main() {
  freopen("in", "r", stdin);
  freopen("out", "w", stdout);
  freopen("log", "w", stderr);
  int tt;
  scanf("%d", &tt);
  for (int cc = 1; cc <= tt; ++cc) {
    printf("Case #%d: ", cc);
    string s;
    cin >> s;
    string ans = "";
    ans += s[0];
    for (int i = 1; i < s.length(); ++i) {
      if (s[i] >= ans[0]) {
        string cur = "";
        cur += s[i];
        ans = cur + ans;
      } else {
        ans += s[i];
      }
    }
    cout << ans << endl;
  }
  return 0;
}