/* no greedy easy life */

#include <cstring>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cassert>
#include <cstdlib>
#include <queue>
#include <ctime>

#define pii pair<int, int>
  
#define pb push_back
#define mp make_pair
  
#define f first
#define s second
  
using namespace std;

typedef long long ll;
typedef double ld;

typedef vector<int> vi;

const double EPS = 1e-9;
const double PI = acos(-1);
  
const int INF = (int) 1e9 + 7;
const int MAXN = (int) 3e5 + 7;

string a, b;
pair<ll, ll> res;

int n;

void upd_ans(ll x, ll y) {
  ll cdif = abs(x - y);
  ll adif = abs(res.f - res.s);
  if (cdif < adif || (cdif == adif && mp(x, y) < res))
    res = mp(x, y);
}

void solve(int pos, ll x = 0, ll y = 0, int state = 0) {
  if (pos == n) {
    upd_ans(x, y);
    return;
  }
  x *= 10;
  y *= 10;
  if (state == 1) {
    if (a[pos] != '?') x += a[pos] - '0';
    if (b[pos] == '?') y += 9;
    else y += b[pos] - '0';
    solve(pos + 1, x, y, 1);
    return;
  }
  if (state == -1) {
    if (b[pos] != '?') y += b[pos] - '0';
    if (a[pos] == '?') x += 9;
    else x += a[pos] - '0';
    solve(pos + 1, x, y, -1);
    return;
  }
  if (a[pos] == '?' && b[pos] == '?') {
    solve(pos + 1, x, y, 0);
    solve(pos + 1, x + 1, y, 1);
    solve(pos + 1, x, y + 1, -1);
  } else if (a[pos] == '?') {
    solve(pos + 1, x + b[pos] - '0', y + b[pos] - '0', 0);
    if (b[pos] != '9')
      solve(pos + 1, x + b[pos] + 1 - '0', y + b[pos] - '0', 1);
    if (b[pos] != '0')
      solve(pos + 1, x + b[pos] - 1 - '0', y + b[pos] - '0', -1);
  } else if (b[pos] == '?') {
    solve(pos + 1, x + a[pos] - '0', y + a[pos] - '0', 0);
    if (a[pos] != '0')
      solve(pos + 1, x + a[pos] - '0', y + a[pos] - 1 - '0', 1);
    if (a[pos] != '9')
      solve(pos + 1, x + a[pos] - '0', y + a[pos] + 1 - '0', -1);
  } else {
    int nstate = 0;
    if (a[pos] != b[pos])
      nstate = a[pos] > b[pos] ? 1 : -1;
    solve(pos + 1, x + a[pos] - '0', y + b[pos] - '0', nstate);
  }
}

int main() {                                       
  #ifdef LOCAL
  freopen("in", "r", stdin);
  freopen("outFast", "w", stdout);
  #endif                                                                                          
  
  ll pw[20];
  
  pw[0] = 1;
  for (int i = 1; i <= 18; i++)
    pw[i] = pw[i - 1] * 10ll;

  int t;
  cin >> t;
  for (int cs = 1; cs <= t; cs++) {
    printf("Case #%d: ", cs);
    cin >> a >> b;
    n = a.size();
    res = mp(0, (ll) 2e18);
    solve(0);
    for (int i = n - 1; i >= 0; i--)
      cout << res.f / pw[i] % 10;
    cout << ' ';
    for (int i = n - 1; i >= 0; i--)
      cout << res.s / pw[i] % 10;
    cout << endl;
  }
  return 0;
}