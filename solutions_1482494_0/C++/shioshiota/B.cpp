#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <climits>
#include <cfloat>
#include<cassert>
#include <map>
#include <utility>
#include <set>
#include <iostream>
#include <memory>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <sstream>
#include <complex>
#include <stack>
#include <queue>
#include<bitset>

#define REP(i,b,n) for(int i=b;i<(int)n;i++)
#define rep(i,n)   REP(i,0,n)
#define ALL(C)     (C).begin(),(C).end()
#define FOR(it,o)  for(__typeof((o).begin()) it=(o).begin(); it!=(o).end(); ++it)
#define dbg(x) cerr << #x << " = " << (x) << endl


typedef long long ll;

using namespace std;

const int N = 10;

int dp[(1<<N)][(1<<N)];

int main(){
  int T;
  cin >> T;
  rep(tc, T){
    cout << "Case #"<<tc+1<<": " << flush;
    int n;
    cin >> n;
    vector<pair<int, int> > V(n);
    rep(i, n){
      cin >> V[i].first >> V[i].second;;
    }
    const int INF = (1<<28);
    rep(i, (1<<N))rep(j, (1<<N))dp[i][j] = INF;
    dp[0][0] = 0;
    rep(i, (1<<n)){
      rep(j, (1<<n)){
	int nowHave = __builtin_popcount(i)+__builtin_popcount(j);;
	if(dp[i][j] == INF)continue;
	rep(k, n){
	  int nexti = i, nextj = j;
	  if(nowHave >= V[k].first && ((1<<k)&i) == 0){
	    nexti += (1<<k);
	  }
	  if(nowHave >= V[k].second && ((1<<k)&j) == 0){
	    nextj += (1<<k);
	  }
	  dp[nexti][nextj] = min(dp[nexti][nextj], dp[i][j]+1);
	}
      }
    }
    int ans = dp[(1<<n)-1][(1<<n)-1];
    if(ans >= INF)cout << "Too Bad" << endl;
    else cout << ans << endl;
  }
  return 0;
}
