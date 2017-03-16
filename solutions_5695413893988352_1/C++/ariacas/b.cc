#include <cstdio>
#include <cstdlib>
#include <cassert>
#include <iostream>
#include <set>
#include <vector>
#include <cstring>
#include <string>
#include <algorithm>
#include <numeric>
#include <cmath>
#include <map>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<vi> vvi;
typedef vector<vl> vvl;
typedef vector<double> vd;
typedef pair<int, int> pii;
typedef pair<double, double> pdd;
typedef vector<pii> vii;
typedef vector<string> vs;

ll x, y, resx, resy;
int n;
string a,b,resa,resb;

string f(ll x) {
  string s = "";
  for (int i = 0; i < n; ++i) {
    s += '0' + x % 10;
    x /= 10;
  }
  reverse(s.begin(), s.end());
  return s;
}

void rec(int i) {
  int sig = (x < y) ? -1 : (x == y ? 0 : 1);
//  cerr << i << ' ' << x << ' ' << y << ' ' << sig << endl;
  if (i == n) {
    if (abs(x-y) > abs(resx - resy)) return;
    if (abs(x-y) == abs(resx - resy) && x > resx) return;
    if (abs(x-y) == abs(resx - resy) && x == resx && y > resy) return;
    resx = x;
    resy = y;
    resa = f(x);
    resb = f(y);
    return;
  }
  if (a[i] == '?' && b[i] == '?') {
    y = 10*y;
    x = 10*x;
    if (sig) {
      if (sig == 1) {
        y += 9;
      }
      if (sig == -1) {
        x += 9;
      }
      rec(i + 1);
    } else {
      rec(i + 1);
      //if (i + 1 < n && (a[i+1] != '?' && b[i+1] != '?')) {
      {
        x += 1;
        rec(i + 1);
        x -= 1;
        y += 1;
        rec(i + 1);
      }
    }
    x /= 10;
    y /= 10;
    return;
  }
  if (a[i] == '?') {
    if (sig == 0) {
      int dd = b[i] - '0';
      x = 10 * x + dd;
      {
        y = 10*y + dd;
        if (dd < 9) {
          x += 1;
          rec(i + 1);
          x -= 1;
        }
        if (dd) {
          x -= 1;
          rec(i + 1);
          x += 1;
        }
        y /= 10;
      }
    }
    if (sig == -1) {
      x = 10 * x + 9;
    }
    if (sig == 1) {
      x = 10 * x;
    }
  } else {
    x = 10 * x + a[i] - '0';
  }
  if (b[i] == '?') {
    if (sig == 0) {
      int dd = a[i] - '0';
      //cerr << i << ' ' << x << ' ' << y << ' ' << dd << endl;
      y = 10 * y + dd;
      {
//        x = 10*x + dd;
        if (dd < 9) {
          y += 1;
          rec(i + 1);
          y -= 1;
        }
        if (dd) {
          y -= 1;
          rec(i + 1);
          y += 1;
        }
//        x /= 10;
      }
    }
    if (sig == 1) {
      y = 10 * y + 9;
    }
    if (sig == -1) {
      y = 10 * y;
    }
  } else {
    y = 10 * y + b[i] - '0';
  }
  rec(i + 1);
  x /= 10;
  y /= 10;
/*  x *= 10;
  for (int d = 0; d < 10; ++d) {
    if (d) x++;
    if (a[i] != '?' && '0'+d != a[i]) continue;
    y *= 10;
    if (b[i] == '?') for (int d = 0; d < 10; ++d) {
      if (d) y++;
      rec(i + 1);
    } else {
      y += b[i] - '0';
      rec(i + 1);
    }
    y /= 10;
  }
  x /= 10;*/
}

void solve() {
  n = a.size();
  x = y = 0;
  resx = 2e18;
  resy = 0;
  rec(0);
}

int main() {
  int T;
  cin >> T;
  for (int test = 1; test <= T; ++test) {
    printf("Case #%d: ", test);
    cin >> a >> b;
    solve();
    cout << resa << ' ' << resb << endl;
  }
  return 0;
}
