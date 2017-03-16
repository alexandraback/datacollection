#include <bits/stdc++.h>

using namespace std;

string get(int a, int n) {
  string res = "";
  while (a > 0) {
    res += '0' + a % 10;
    a /= 10;
  }
  reverse(res.begin(), res.end());
  while (res.length() < n) res = "0" + res;
  return res;
}

bool check(string a, int bb) {
  string b = get(bb, a.length());
  if (a.length() != b.length()) return false;
  for (int i = 0; i < a.length(); ++i) {
    if (a[i] == '?') continue;
    if (b[i] != a[i]) return false;
  }
  return true;
}

int main() {
  freopen("in", "r", stdin);
  freopen("out", "w", stdout);
  freopen("log", "w", stderr);
  int tt;
  scanf("%d", &tt);
  for (int cc = 1; cc <= tt; ++cc) {
    printf("Case #%d: ", cc);
    string a, b;
    cin >> a >> b;
    int diff = 1e9;
    int ansa, ansb;
    for (int i = 0; i <= 999; ++i) {
      if (!check(a, i)) continue;
      for (int j = 0; j <= 999; ++j) {
        if (!check(b, j)) continue;
        int cur = abs(i - j);
        if (cur < diff) {
          diff = cur;
          ansa = i;
          ansb = j;
        } else
        if (cur == diff) {
          if (i < ansa) {
            ansa = i;
            ansb = j;
          } else
          if (j < ansb) {
            ansa = i;
            ansb = j;
          }
        }
      }
    }
    cout << get(ansa, a.length()) << " " << get(ansb, a.length()) << endl;
  }
  return 0;
}