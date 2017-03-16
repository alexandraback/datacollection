#include <bits/stdc++.h>
#define sz(c) ((int)(c).size())
#define vec vector
using namespace std;
typedef long long int64;
typedef pair<int,int> pii;

void solve(int testcase) {
  cerr << "Case #" << testcase << ": ";
  cout << "Case #" << testcase << ": ";
  int n;
  string s;
  cin >> n >> s;
  int res = 0;
  int sum = s[0] - '0';
  for (int i = 1; i <= n; ++i) {
    res = max(res, i - sum);
    sum += s[i] - '0';
  }
  cerr << res << endl;
  cout << res << endl;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  int T;
  cin >> T;
  for (int t = 1; t <= T; ++t)
    solve(t);

  return 0;
}
