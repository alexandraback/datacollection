#include <bits/stdc++.h>

#define rep(i,n) for(i=0;i<n;i++)
#define ll long long 
#define elif else if
#define pii pair<ll int,ll int>
#define mp make_pair
#define pb push_back
using namespace std;

int bar;
   vector<int>v;
int lim=9999999;
 int arr[30000004];
int main()
{
  freopen("int","r",stdin);
  freopen("out","w",stdout);
  std::ios::sync_with_stdio(false);
  int T,t;
  cin>>T;
  for (t=1;t<=T;t++)
  {
    int n,i,j,k;
    cin>>n;
    int ans=lim;
    vector<int>dp(n+5,0);
    dp[n]=0;
    for(i=n-1;i>=1;i--)
    {
          dp[i]=min(n-i,dp[i+1]+1);
          string tem=to_string(i);
          reverse(tem.begin(),tem.end());
          int num=stoi(tem);
          if(num>i){
          if(num<=n)
            dp[i]=min(dp[i],dp[num]+1);}
            //cout<<dp[i]<<" ";
    }
    printf("Case #%d: %d\n",t,dp[1]+1);
  }
  return 0;
}