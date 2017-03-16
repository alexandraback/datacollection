#include<vector>
#include<algorithm>
#include<iostream>
using namespace std;

int dp[100][100];

int solve(int e,int r,int n,vector<int> & in){
  for(int i=0;i<n;i++){
    for(int j=0;j<=e;j++){
      dp[i][j] = 0;
    }
  }
  for(int i=0;i<=e;i++){
    dp[0][min(e,e-i+r)] = i * in[0];
  }
  for(int i=0;i<n-1;i++){
    int & val = in[i+1];
    for(int j=0;j<=e;j++){
      for(int k=0;k<=j;k++){
	dp[i+1][min(e, j-k + r)] = max(dp[i+1][min(e, j-k + r)], dp[i][j] + val * k);
      }
    }
  }
  int ans = 0;
  for(int i=0;i<e+1;i++){
    ans = max(ans, dp[n-1][i]);
  }
  return ans;
}

int main(){
  int te,tc = 0;
  cin>>te;
  while(te--){
    int ans = 0;
    int n,e,r;
    cin>>e>>r>>n;
    vector<int> in(n);
    for(int i=0;i<n;i++){
      cin>>in[i];
    }
    ans = solve(e,r,n,in);

    cout <<"Case #" << ++tc << ": " << ans << endl;
  }
  return 0;
}
