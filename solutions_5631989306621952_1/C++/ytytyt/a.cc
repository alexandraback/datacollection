#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <list>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>

using namespace std;

typedef long long LL;

int T, ti;
string s;

int solve() {
  cin >> s;
  string ans;
  ans += s[0];
  for (int i = 1; i < s.length(); ++i)
    if (s[i] >= ans[0])
      ans = s[i] + ans;
    else
      ans = ans + s[i];

  printf("Case #%d: ", ti);
  cout << ans << endl;
  return 0;
}

int main() {
  cin >> T;
  for (ti = 1; ti <= T; ti++) {
    solve();
  }
  return 0;
}
