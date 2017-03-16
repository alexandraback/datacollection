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
#define dbg(x) cout << __LINE__ << ' ' << #x << " = " << (x) << endl


typedef long long ll;

using namespace std;

const int N = 10;
const int M = 5;

int dp[N+1][M+1];

int E, R, n;

int v[N];

int solve(){
  rep(i, N+1)rep(j, M+1)dp[i][j] =0;
  int ret = 0;
  rep(i, n){
    rep(j, E+1){
      rep(k, j+1){
	int nextValue = dp[i][j] + v[i] * k;
	int nextErg = min(j - k + R, E);
	ret = max(ret, nextValue);
	dp[i+1][nextErg] = max(dp[i+1][nextErg], nextValue);
      }
    }
  }
  return ret;
}


int main(){
  int T;
  cin >> T;
  rep(tc, T){
    cout << "Case #" << tc+1<<": " << flush;
    cin >> E >> R >> n;
    rep(i, n)cin>> v[i];
    cout << solve() << endl;
  }
  return 0;
}
