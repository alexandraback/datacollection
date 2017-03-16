#define _CRT_SECURE_NO_DEPRECATE
#include <iostream> 
#include <string>
#include <vector>
#include <sstream>
#include <queue>
#include <algorithm>
#include <iomanip>
#include <map>
#include <set>
#include <math.h>
#include <stack>
#include <deque>
#include <numeric>
#define all(x) x.begin(),x.end()
#define mpair make_pair
using namespace std;
typedef long long ll;
typedef long double ld;
const ld epsylon = 1e-9;

ll dp[50][1000];
vector<int> v;
int e,r,n;

ll solve(int from, int lft) {
  int res = 0;
  if ( from + 1 == v.size()) {
    return dp[from][lft] = lft * v[from];
  }
  for (int val = 0; val <= lft; ++val) {
    int nxt = lft - val + r;
    if (nxt > e) {
      nxt = e;
    }

    int tmp = ((dp[from+1][nxt] == -1)?solve(from+1, nxt):dp[from+1][nxt]);
    tmp += v[from] * val;

    if (tmp > res) {
      res = tmp;
    }
  }

  return dp[from][lft] = res;
}
int main()
{
  freopen("google.in","r",stdin);
  freopen("google.out","w",stdout);
  int nt;
  cin>>nt;
  for(int it=1;it<=nt;it++)
  {
    cin >> e >> r >> n;
    v.clear();
    v.resize(n);
    for (int i = 0; i< n; ++i){
      scanf("%d", &v[i]);
    }
    memset(dp, -1, sizeof(dp));

    cout<<"Case #"<<it<<": " << solve(0, e)<<endl;
  }
  return 0;
}
