#include <cstdio>
#include <cstdlib>
#include <cassert>
#include <cmath>
#include <ctime>
#include <cstring>
#include <iostream>
#include <vector>
#include <algorithm>

#define sz(c) ((int)(c).size())
#define all(c) (c).begin(), (c).end()

using namespace std;
typedef long long ll;

void testCase()
{
  int smax;
  string s;
  cin >> smax >> s;
  assert(sz(s) == smax + 1);

  int ans = 0;
  int cnt = 0;
  int last = sz(s);
  while (last > 0 && s[last - 1] == '0') {
    last--;
  }
  for (int i = 0; i < last; i++) {
    if (cnt < i) {
      ans += i - cnt;
      cnt = i;
    }
    cnt += s[i] - '0';
  }
  cout << ans << endl;
}

int main() {
//  freopen("input.txt", "rt", stdin);
//  freopen("output.txt", "wt", stdout);
  int T;
  cin >> T;
  for (int t = 1; t <= T; t++) {
    cout << "Case #" << t << ": ";
    testCase();
  }
  return 0;
}
