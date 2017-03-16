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
string a,b,cura,curb,resa,resb;

void rec(int i) {
  if (i == n) {
    if (abs(x-y) > abs(resx - resy)) return;
    if (abs(x-y) == abs(resx - resy) && x > resx) return;
    if (abs(x-y) == abs(resx - resy) && x == resx && y > resy) return;
    resx = x;
    resy = y;
    resa = cura;
    resb = curb;
    return;
  }
  x *= 10;
  for (int d = 0; d < 10; ++d) {
    cura[i] = '0' + d;
    if (d) x++;
    if (a[i] != '?' && '0'+d != a[i]) continue;
    y *= 10;
    if (b[i] == '?') for (int d = 0; d < 10; ++d) {
      curb[i] = '0' + d;
      if (d) y++;
      rec(i + 1);
    } else {
      y += b[i] - '0';
      rec(i + 1);
    }
    y /= 10;
  }
  x /= 10;
}

void solve() {
  n = a.size();
  x = y = 0;
  resx = 2e18;
  resy = 0;
  cura = a;
  curb = b;
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
