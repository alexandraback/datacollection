#include<bits/stdc++.h>
using namespace std;

int main()
{
  freopen("input.txt","r",stdin);
  freopen("output.txt","w",stdout);
  int T,count = 1;
  cin>>T;
  string S,A,B;
  while(T--)
  {
    cout<<"Case #"<<count++<<": ";
    cin>>S;
    int N = S.length();
    string dp[N+1];
    dp[1] = S[0];
    for(int i=1;i<N;i++)
    {
      A = dp[i] + S[i];
      B = S[i] + dp[i];
      dp[i+1] = max(A,B);
    }
    cout<<dp[N]<<endl;

  }
  
  return 0;
}