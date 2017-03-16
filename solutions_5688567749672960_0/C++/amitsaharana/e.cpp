#include <bits/stdc++.h>
using namespace std;
#define ll long long

#define up 1000000

int dp[up+5];
int dp2[up+5];

int main() {
  ios_base::sync_with_stdio(0);
  for(int i=1; i<up+5; i++) {
    dp[i] = 1e9;
  }
  dp[1] = 1; dp2[1] = 0;
  for(int i=1; i<=up; i++) {
    int cur = 0;
    int j= i;
    while(j>0) {
      cur = 10*cur+(j%10);
      j/=10;
    }
    if(cur>i && cur<=up && dp[cur]>dp[i]+1) {
      dp[cur] = dp[i]+1;
      dp2[cur] = i;
    }
    if(dp[i+1]>=dp[i]+1) {
      dp[i+1] = dp[i]+1;
      dp2[i+1] = i;
    }
  }
  int t;
  cin>>t;
  for(int z=1; z<=t; z++) {
    cout<<"Case #"<<z<<": ";
    int n;
    cin>>n;
    cout<<dp[n]<<endl;
    /*
    while(n>0) {
      cout<<n<<" ";
      n = dp2[n];
    }
    cout<<endl;
    */
  }
  
  return 0;
}