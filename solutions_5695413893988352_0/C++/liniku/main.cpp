#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

bool match(const string &s, int n) {
  int l = s.length();
  for (int i = 0; i < l; ++i) {
    int m = n % 10;
    char c = s[l - 1 - i];
    if (c != '?' && c != '0' + m) {
      return false;
    }
    n /= 10;
  }
  return true;
}

void solve(const string &c, const string &j, string &cc, string &jj) {
  int l = c.length();
  int m = 1;
  for (int i = 0; i < l; ++i) {
    m *= 10;
  }
  int a = m;
  int ap = -1, aq = -1;
  for (int p = 0; p < m; ++p) {
    if (!match(c, p)) {
      continue;
    }
    for (int q = 0; q < m; ++q) {
      if (!match(j, q)) {
        continue;
      }
      int d = abs(p - q);
      if (a > d) {
        a = d;
        ap = p;
        aq = q;
      }
    }
  }
  cc = c;
  jj = j;
  for (int i = 0; i < l; ++i) {
    cc[l - i - 1] = ap % 10 + '0';
    jj[l - i - 1] = aq % 10 + '0';
    ap /= 10;
    aq /= 10;
  }
}

int main() {
  int T;
  string c, j, cc, jj;
  cin >> T;
  for (int i = 0; i < T; ++i) {
    cin >> c >> j;
    solve(c, j, cc, jj);
    cout << "Case #" << i + 1 << ": " << cc << " " << jj << endl;
  }
  return 0;
}
