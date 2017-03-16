#include <iostream>
#include <sstream>
#include <cstdlib>
#include <cmath>
#include <map>
#include <set>
#include <queue>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <cstdio>
#include <numeric>
#include <bitset>
#include <stack>
using namespace std;

const int INF = 1 << 29;

typedef struct
{
  int a, b;
} Level;

int solve(int star, int c1, int c2, const vector<Level>& l, vector<vector<int> >& dp)
{
  if (c2 == (1 << l.size())-1)
    return 0;

  if (dp[c1][c2] != -1)
    return dp[c1][c2];

  int ans = INF;
  for (int i = 0; i < l.size(); ++i) {
    if (!(c1 & (1 << i)) && star >= l[i].a)
      ans = min(ans, solve(star+1, c1 | 1 << i, c2, l, dp)+1);

    if (!(c2 & (1 << i)) && star >= l[i].b) {
      if (c1 & (1 << i))
	ans = min(ans, solve(star+1, c1, c2 | 1 << i, l, dp)+1);
      else
	ans = min(ans, solve(star+2, c1, c2 | 1 << i, l, dp)+1);
    }
  }
  return dp[c1][c2] = ans;
}


int main()
{
  int T;
  cin >> T;
  for (int Testcase = 1; Testcase <= T; ++Testcase) {
    int N;
    cin >> N;
    vector<Level> l(N);
    for (int i = 0; i < N; ++i)
      cin >> l[i].a >> l[i].b;

    vector<vector<int> > dp(1 << N, vector<int>(1 << N, -1));
    int ans = solve(0, 0, 0, l, dp);
    if (ans >= INF)
      cout << "Case #" << Testcase << ": Too Bad" << endl;
    else
      cout << "Case #" << Testcase << ": " << ans << endl;
  }
  return 0;
}
