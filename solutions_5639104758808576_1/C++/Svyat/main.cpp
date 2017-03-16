#include <bits/stdc++.h>
using namespace std;

int T;
int smax;
string s;

void load() {
  cin >> smax >> s;
}

void solve(int tc) {
  int res = 0, cur = 0;
  for (int i = 0; i < (int)s.length(); ++i) {
    if (i > cur) {
      res += i - cur;
      cur = i;
    }
    cur += s[i] - '0';
  }
  cout << "Case #" << tc << ": " << res << '\n';
}

void clear() {
}

int main() {
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  ios_base::sync_with_stdio(false);
  cin >> T;
  for (int tc = 1; tc <= T; ++tc) {
    load();
    solve(tc);
    clear();
  }
  return 0;
}
