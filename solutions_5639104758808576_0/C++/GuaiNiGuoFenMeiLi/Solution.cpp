#include <iostream>
#include <string>
#include <algorithm>
#include <cstdio>

using namespace std;

int ntests, n;
string s;

int main() {
  freopen("A-small-attempt0.in", "r", stdin);
  freopen("A-small-attempt0.out", "w", stdout);
  cin >> ntests;
  for (int test = 1; test <= ntests; ++test) {
    cin >> n >> s;
    int res = 0, sum = s[0] - '0';
    for (int i = 1; i <= n; ++i) {
      res = max(res, max(0, i - sum));
      sum += s[i] - '0';
    }
    cout << "Case #" << test << ": " << res << endl;
  }
  return 0;
}
