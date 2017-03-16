#include <bits/stdc++.h>
#define sz(c) ((int)(c).size())
#define vec vector
using namespace std;
typedef long long int64;
typedef pair<int,int> pii;

map<vec<int>,int> cache;

int rec(vec<int> a) {
  sort(a.begin(), a.end());
  if (cache.count(a)) return cache[a];
  if (sz(a) == 0)
    return 0;

  vec<int> b;
  for (int x : a) {
    if (x - 1 > 0) b.push_back(x - 1);
  }

  int res = rec(b) + 1;

  b = a;
  set<int> was;
  for (int i = 0; i < sz(a); ++i) {
    if (a[i] > 1 && !was.count(a[i])) {
      was.insert(a[i]);

      b.push_back(0);
      int l = sz(b) - 1;
      for (int t = 1; t < a[i]; ++t) {
        b[i] = t;
        b[l] = a[i] - t;
        if (b[i] <= b[l]) {
          res = min(res, rec(b) + 1);
        }
        b[l] = 0;
        b[i] = a[i];
      }
      b.pop_back();
    }
  }

  cache[a] = res;
  return res;
}

void solve(int testcase) {
  #ifdef STRESS
  int n = rand() % 6 + 1;
  vec<int> a(n);
  for (int i = 0; i < n; ++i)
    a[i] = rand() % 9 + 1;
  int ans = rec(a);
  #else

  cout << "Case #" << testcase << ": ";

  int n;
  cin >> n;
  vec<int> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }

  #endif

  int res = 1e9;
  for (int hi = 1; hi <= 1000; ++hi) {
    int mov = 0;
    for (int i = 0; i < sz(a); ++i) {
      if (a[i] > hi) {
        mov += (a[i] + hi - 1) / hi - 1;
      }
    }
    res = min(res, mov + hi);
  }

  cerr << res << endl;

  #ifdef STRESS
  if (ans != res) {
    cerr << n << endl;
    for (int i = 0; i < n; ++i)
      cerr << a[i] << " ";
    cerr << endl;
    cerr << ans << endl;
    cerr << res << endl;
    assert(false);
  }

  #else
  cout << res << endl;
  #endif
}

int main() {
  srand((int)time(0));
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  #ifdef STRESS
  while (true) solve(0);
  #endif

  int T;
  cin >> T;
  for (int t = 1; t <= T; ++t)
    solve(t);

  return 0;
}
