#include<iostream>
#include<string>
#include<algorithm>
#include<stack>
#include<queue>
#include<set>
#include<complex>
#include<map>
#include<list>
#include<deque>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<cstring>

#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;

const int N = 1000001;
int dp[2][N+1];
int a,n,m[110];

int main(){
  int testcase;
  int ans;

  cin >> testcase;
  for(int casenum=1;casenum<=testcase;casenum++){
    cin >> a >> n;
    rep(i,n)cin >> m[i];
    sort(m,m+n);
    
    rep(i,N+1)dp[0][i] = -1;
    dp[0][a] = 0;

    rep(i,n){
      int cur = i&1;
      int nxt = 1-cur;
      rep(j,N+1)dp[nxt][j] = -1;

      rep(j,N+1){
	if(dp[cur][j]>=0){
	  int ab = min(N,2*j-1);
	  if(dp[cur][ab]<0 || dp[cur][ab] > dp[cur][j] + 1){
	    dp[cur][ab] = dp[cur][j] + 1;
	  }
	  if(dp[nxt][ab]<0 || dp[nxt][ab] > dp[cur][j] + 1){
	    dp[nxt][ab] = dp[cur][j] + 1;
	  }

	  if(m[i]<j){
	    ab = min(N,j+m[i]);
	    if(dp[nxt][ab]<0 || dp[nxt][ab] > dp[cur][j]){
	      dp[nxt][ab] = dp[cur][j];
	    }
	  }
	}
      }
    }

    ans = -1;
    rep(i,N+1){
      if( ans<0 || (dp[n&1][i]>=0 && ans > dp[n&1][i]) )ans = dp[n&1][i];
    }
    cout << "Case #" << casenum << ": ";
    cout << ans << endl;
  }
}
