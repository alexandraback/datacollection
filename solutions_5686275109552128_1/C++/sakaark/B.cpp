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

using namespace std;

typedef long long LL;

const int MAX = 1001, INF = 1001;

int dp[MAX][MAX];

int get_extra(int a, int reach) {
  if (dp[a][reach] != -1) {
    return dp[a][reach];
  }
  if (a <= reach) {
    return dp[a][reach] = 0;
  }
  int ans = INF;
  for (int i = 1; i <= a / 2; i++) {
    ans = min(ans, get_extra(i, reach) + get_extra(a - i, reach) + 1);
  }
  return dp[a][reach] = ans;
}

int main () {
  std::ios::sync_with_stdio(false);
  int t;
  cin >> t;
  memset(dp, -1, sizeof(dp));
  for (int i = 1; i <= t; i++) {
    int d, final_ans;
    cin >> d;
    vector<int> alls(d), ans(MAX, INF);
    for (int i = 0; i < d; i++) {
      cin >> alls[i];
    }
    for (int tr = 1; tr < MAX; tr++) {
      ans[tr] = tr;
      for (int i = 0; i < d; i++) {
	ans[tr] += get_extra(alls[i], tr);
      }
    }
    cout << "Case #" << i << ": " << *min_element(ans.begin(), ans.end()) << endl;
  }
  return 0;
}
