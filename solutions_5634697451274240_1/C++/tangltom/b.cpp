#include <bits/stdc++.h>
using namespace std;

char s[105];
int dp[105][2];
int f(int i, int wanted){
  if(i<0)
    return 0;
  int &res = dp[i][wanted];
  if(res!=-1)
    return res;
  res = 1000;
  if(s[i]==wanted)
    res = min(f(i-1, wanted), f(i-1,!wanted)+1);
  else
    res = min(f(i-1, !wanted)+1, f(i-1,wanted)+1+1);
  return res;
}

int main(){
  ios_base::sync_with_stdio(0);
  int T;
  cin>>T;
  for(int t=1;t<=T;t++){
    cin>>s;
    int n = strlen(s);
    for(int i=0;i<n;i++)
      s[i] = (s[i]=='+');
    memset(dp,-1,sizeof(dp));
    cout<<"Case #"<<t<<": "<<f(n-1, 1)<<endl;
  }
  return 0;
}
