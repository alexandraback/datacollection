#include <iostream>
#include <algorithm>
using namespace std;

const int E = 5;
const int N = 10;
int e,r,n,v[N];

int solve(){
  int dp[2][E+1], ans=0;
  fill(dp[0],dp[2],0);

  for(int i=0;i<n;i++){
    for(int j=0;j<=e;j++){
      for(int k=0;k<=j;k++){
        dp[1][min(e,k+r)] = max(dp[1][min(e,k+r)], dp[0][j]+v[i]*(j-k));
      }
    }
    for(int j=0;j<=e;j++){
      dp[0][j] = dp[1][j];
      dp[1][j] = 0;
    }
  }

  for(int i=0;i<=e;i++) ans = max(ans,dp[0][i]);
  return ans;
}

int main(){
  int T;
  cin >> T;
  for(int t=1;t<=T;t++){
    cin >> e >> r >> n;
    for(int i=0;i<n;i++) cin >> v[i];
    cout << "Case #" << t << ": " << solve() << endl;
  }
}
