#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int T;
ll l, x, n;
string s;
int a[5][5] = {{0,0,0,0,0},
	       {0,1,2,3,4},
	       {0,2,-1,4,-3},
	       {0,3,-4,-1,2},
	       {0,4,3,-2,-1}};

int mult(int x, int y) {
  int res = a[abs(x)][abs(y)];
  int sgn = 1;
  if (x < 0) sgn *= -1;
  if (y < 0) sgn *= -1;
  return res * sgn;
}

int binpow(int x, ll n) {
  int res = 1;
  while (n > 0) {
    if (n & 1)
      res = mult(res, x);
    x = mult(x, x);
    n >>= 1;
  }
  return res;
}

void load() {
  cin >> l >> x;
}

void solve(int tc) {
  n = l * x;
  cin >> s;
  int block = 1;
  for (int i = 0; i < l; ++i) {
    s[i] -= 'g';
    block = mult(block, s[i]);
  }
  if (binpow(block, x) != -1) {
    cout << "Case #" << tc << ": NO\n";
    return;
  }
  int pref = 1;
  ll lt = 1e18, rt = -1;
  for (int i = 0; i < l; ++i) {
    pref = mult(pref, s[i]);
    int blocks = 1;
    for (int j = 0; j < 10; ++j) {
      if (mult(blocks, pref) == 2) {
	lt = min(lt, i + j * l);
	break;
      }
      blocks = mult(blocks, block);
    }
  }
  int suff = 1;
  for (int i = l - 1; i > -1; --i) {
    suff = mult(s[i], suff);
    int blocks = 1;
    for (int j = 0; j < 10; ++j) {
      if (mult(suff, blocks) == 4) {
	rt = max(rt, n - (l - i) - j * l);
	break;
      }
      blocks = mult(blocks, block);
    }
  }
  cout << "Case #" << tc << ": ";
  if (lt < rt) cout << "YES\n";
  else cout << "NO\n";
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
