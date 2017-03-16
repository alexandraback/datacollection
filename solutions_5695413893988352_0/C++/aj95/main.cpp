// :)
#include <bits/stdc++.h>

typedef long long ll;
using namespace std;

string f(int x, int n) {
  string s = "";
  while (x > 0) {
    s = char((x % 10) + '0') + s;
    x /= 10;
  }
  while ((int)s.size() < n) {
    s = '0' + s;
  }
  return s;
}

bool IsOk(const string& s, const string& t) {
  assert((int)s.size() == (int)t.size());
  for (int i = 0; i < (int)s.size(); i++) {
    if (s[i] == '?' || t[i] == '?')
      continue;
    if (s[i] != t[i])
      return false;
  }
  return true;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  freopen("/Users/Ayur/Downloads/B-small-attempt0.in.txt", "r", stdin);
  freopen("/Users/Ayur/Downloads/B-small.txt", "w", stdout);
  int t, tt, i, j, n, m;
  int a, b, d = 0;
  string p, q, r, s;
  cin >> tt;
  for (t = 1; t <= tt; t++) {
    cout << "Case #" << t << ": ";
    cin >> p >> q;
    n = (int)p.size();
    assert((int)q.size() == n);
    if (n == 1)
      m = 9;
    else if (n == 2)
      m = 99;
    else if (n == 3)
      m = 999;
    else
      assert(0);
    d = 1000000001;
    a = b = -1;
    for (i = 0; i <= m; i++) {
      r = f(i, n);
      if (!IsOk(p, r))
        continue;
      for (j = 0; j <= m; j++) {
        s = f(j, n);
        if (!IsOk(q, s))
          continue;
        if (d > abs(i - j)) {
          d = abs(i - j);
          a = i;
          b = j;
        }
      }
    }
    assert(a != -1);
    assert(b != -1);
    r = f(a, n);
    s = f(b, n);
    cout << r << ' ' << s << '\n';
  }
  return 0;
}