#include <bits/stdc++.h>

using namespace std;

#define ST first
#define ND second
#define CLR(x) memset(x, 0, sizeof x)

typedef pair<int, int> pii;

long long l1;
long long l2;
string c, d;

void go(string a, string b, int idx, long long x, long long y) {
  if (idx == a.size()) {
    if (abs(x - y) < abs(l1 - l2)) {
      l1 = x;
      l2 = y;
    }
    return;
  }
  string auxa = a;
  string auxb = b;
  x *= 10LL;
  y *= 10LL;
  long long xa = x;
  long long ya = y;
  for (int i = 0; i < 10; ++i) {
    if (a[idx] == '?') {
      auxa[idx] = '0' + i;
      xa = x + (long long)(i);
    } else {
      xa = x + (long long)(a[idx] - '0');
    }
    for (int j = 0; j < 10; ++j) {
      if (b[idx] == '?') {
        auxb[idx] = '0' + j;
        ya = y + (long long)(j);
      } else {
        ya = y + (long long)(b[idx] - '0');
      }
      go(auxa, auxb, idx + 1, xa, ya);
      if (b[idx] != '?') break;
    }
    if (a[idx] != '?') break;
  }
  
  x /= 10LL;
  y /= 10LL;
}

int main() {
  int n;
  cin >> n;
  for (int i = 0; i < n; ++i) {
    cin >> c >> d;
    l1 = 999999999999999999LL;
    l2 = 0LL;
    go(c, d, 0, 0LL, 0LL);
    cout << "Case #" << (i + 1) << ": ";
    string ans1 = "";
    string ans2 = "";
    for (int j = 0; j < c.size(); ++j) {
      ans1 += ((l1 % 10LL) + '0');
      ans2 += ((l2 % 10LL) + '0');
      l1 /= 10LL;
      l2 /= 10LL;
    }
    reverse(ans1.begin(), ans1.end());
    reverse(ans2.begin(), ans2.end());
    cout << ans1 << " " << ans2 << endl;
  }
  return 0;
}
