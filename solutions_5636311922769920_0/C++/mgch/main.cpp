#include <stdio.h>
#include <algorithm>
#include <assert.h>
#include <set>
#include <map>
#include <complex>
#include <iostream>
#include <time.h>
#include <stack>
#include <stdlib.h>
#include <memory.h>
#include <bitset>
#include <math.h>
#include <string>
#include <string.h>
#include <queue>
#include <vector>

using namespace std;

const int MaxN = 2e8 + 10;
const int INF = 1e9;
const int MOD = 1e9 + 7;

long long mPow(long long a, long long n) {
  long long r = 1;
  while (n > 0) {
    if (n & 1) {
      r *= a;
    }
    a *= a;
    n >>= 1;
  }
  return r;
}

int main() {
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  int t;
  cin >> t;
  for (int it = 1; it <= t; ++it) {
    int k, c, s;
    cin >> k >> c >> s;
    vector < long long > ans;
    int x = 0, y = k - 1;
    while (s > 1) {
      ans.push_back(0 + x * mPow(k, c - 1));
      ans.push_back((y + 1) * mPow(k, c - 1) - 1);
      x++;
      y--;
      s -= 2;
    }
    if (s == 1) {
      ans.push_back(0 + x * mPow(k, c - 1));
    }
    sort(ans.begin(), ans.end());
    cout << "Case #" << it << ": ";
    for (int i = 0; i < (int)ans.size(); ++i) {
      cout << ans[i] + 1 << (i == (int)ans.size() - 1 ? '\n' : ' ');
    }
  }
  return 0;
}

