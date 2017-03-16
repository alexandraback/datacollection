#include <bits/stdc++.h>
#define sz(c) ((int)(c).size())
#define vec vector
using namespace std;
typedef long long int64;
typedef pair<int,int> pii;

int n, m;
string t;

vector<vector<int>> mtab = {
  {0,  0,  0,  0,  0},
  {0,  1,  2,  3,  4},
  {0,  2, -1,  4, -3},
  {0,  3, -4, -1,  2},
  {0,  4,  3, -2, -1}
};

int mul(int a, int b) {
  int sign = 1;
  if (a < 0) sign *= -1;
  if (b < 0) sign *= -1;
  return sign * mtab[abs(a)][abs(b)];
}

int pow(const string &s, int x) {
  int val = 1;
  for (char c : s) val = mul(val, c - 'i' + 2);

  int res = 1;
  while (x > 0) {
    if (x % 2 == 1)
      res = mul(res, val);
    val = mul(val, val);
    x /= 2;
  }

  return res;
}

bool solve(const string &s) {
  int cur = 1;
  int l = 0;
  while (l < sz(s) && cur != 2) {
    cur = mul(cur, s[l] - 'i' + 2);
    l += 1;
  }
  if (cur != 2) return false;

  cur = 1;
  while (l < sz(s) && cur != 3) {
    cur = mul(cur, s[l] - 'i' + 2);
    l += 1;
  }
  if (cur != 3) return false;

  cur = 1;
  while (l < sz(s)) {
    cur = mul(cur, s[l] - 'i' + 2);
    l += 1;
  }

  cur = mul(cur, pow(t, m - sz(s) / n));

  return cur == 4;
}

void solve(int testcase) {
  cin >> n >> m;
  cin >> t;

  string s;
  for (int i = 0; i < min(m, 20); ++i)
    s += t;

  cout << "Case #" << testcase << ": ";
  if (solve(s))
    cout << "YES" << endl;
  else
    cout << "NO" << endl;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  int numTests;
  cin >> numTests;
  for (int test = 1; test <= numTests; ++test) {
    cerr << "Case #" << test << endl;
    solve(test);
  }

  return 0;
}
