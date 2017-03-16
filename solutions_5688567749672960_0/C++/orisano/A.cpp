// {{{ include
#include <cstdio>
#include <cmath>
#include <cstring>
#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <queue>
#include <algorithm>
// }}}
#include <sstream>

using namespace std;

typedef long long ll;
inline int in(){int x;scanf("%d",&x);return x;}

int rev_int(int n){
  stringstream ss;
  ss << n;
  string s = ss.str();
  reverse(s.begin(), s.end());
  return atoi(s.c_str());
}

int dp[1000100];
const int INF = 1 << 29;

int main()
{
  fill_n(dp, 1000100, INF);
  dp[1] = 1;
  for (int i = 1; i <= 1000000; i++){
    int ni = rev_int(i);
    dp[i + 1] = min(dp[i + 1], dp[i] + 1);
    dp[ni] = min(dp[ni], dp[i] + 1);
  }

  int T = in();
  for (int t = 1; t <= T; t++){
    ll N;
    scanf("%lld", &N);
    printf("Case #%d: %d\n", t, dp[N]);
  }

  return 0;
}
