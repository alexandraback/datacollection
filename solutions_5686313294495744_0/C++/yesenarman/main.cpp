#include <bits/stdc++.h>
#define vec vector
#define sz(c) int(c.size())
#define FOR(i, a, b) for (int i = a; i < (b); ++i)
#define DOWN(i, a, b) for(int i = (a) - 1; i >= (b); --i)
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef vec<int> vi;

void solve(int testcase) {
  cout << "Case #" << testcase << ": ";
  int n;
  cin >> n;
  vec<string> first(n);
  vec<string> second(n);
  FOR(i, 0, n) {
    cin >> first[i] >> second[i];
  }
  int res = 0;
  FOR(mask, 0, 1 << n) {
    set<string> ff;
    set<string> ss;
    FOR(i, 0, n) {
      if (!(mask >> i & 1)) {
        ff.insert(first[i]);
        ss.insert(second[i]);
      }
    }
    int fakes = 0;
    FOR(i, 0, n) {
      if (mask >> i & 1) {
        if (ff.count(first[i]) && ss.count(second[i])) {
          fakes += 1;
        }
      }
    }
    res = max(res, fakes);
  }
  cout << res << endl;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  int testcases;
  cin >> testcases;
  FOR(testcase, 1, testcases + 1) {
    cerr << "Case " << testcase << "/" << testcases << endl;
    solve(testcase);
  }

  return 0;
}
