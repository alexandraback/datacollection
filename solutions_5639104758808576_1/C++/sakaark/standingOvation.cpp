#include <string>
#include <vector>
#include <cstring>
#include <cmath>
#include <utility>
#include <algorithm>
#include <set>
#include <map>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <sstream>
#include <list>
#include <iomanip>
#include <ctime>
#include <cassert>
#include <unordered_map>
#include <unordered_set>

#define WHAT_IS(x) cout << #x << " is " << x << endl;

const int MAX = 100010, MOD = 1000000007, INF = 1000000007;

using namespace std;

typedef long long LL;

string s;

int main () {
  std::ios::sync_with_stdio(false);
  int t;
  cin >> t;
  for (int i = 1; i <= t; i++) {
    int n, cur_sum = 0, ans = 0;
    cin >> n >> s;
    for (int i = 0; i <= n; i++) {
      if (cur_sum < i) {
	ans += i - cur_sum;
	cur_sum = i;
      }
      cur_sum += s[i] - '0';
    }
    cout << "Case #" << i << ": " << ans << endl;
  }
  return 0;
}
