#include <bits/stdc++.h>

using namespace std;

const string a[] = {"ZERO", "SIX", "TWO", "EIGHT", "THREE", "FOUR", "ONE", "FIVE", "SEVEN", "NINE"};
const char b[] = {'Z', 'X', 'W', 'G', 'H', 'U', 'O', 'F', 'S', 'N'};
const string c[] = {"0", "6", "2", "8", "3", "4", "1", "5", "7", "9"};

int cnt[26];

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
    memset(cnt, 0, sizeof cnt);
    for (int i = 0; i < s.length(); ++i) {
      ++cnt[s[i] - 'A'];
    }
    string ans = "";
    for (int i = 0; i < 10; ++i) {
      int t = b[i] - 'A';
      while (cnt[t] > 0) {
        for (int j = 0; j < a[i].length(); ++j) {
          --cnt[a[i][j] - 'A'];
        }
        ans += c[i];
      }
    }
    sort(ans.begin(), ans.end());
    cout << ans << endl;
  }
  return 0;
}