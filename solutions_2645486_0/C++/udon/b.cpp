#include<iostream>
#include<cstdio>
#include<algorithm>
#include<map>
typedef long long ll;
using namespace std;
int T,E,N,R;
int dp[11][11];
int v[11];
bool valid(int r,int c){
  return 0<=r&&r<N&&0<=c&&c<=E;
}
int rec(int r,int c){
  if(!valid(r,c)){
    return -500;
  }
  if(dp[r][c]!=-1){
    return dp[r][c];
  }
  if(r==0){
    dp[r][c]=v[0]*(E-c);
    return dp[r][c];
  }
  int tmp=0;
  for(int i=max(c-R,0);i<=E;i++){
    tmp=max(rec(r-1,i)+(min(E,i+R)-c)*v[r],tmp);
  }
  dp[r][c]=tmp;
  return tmp;
}
int main(){
  cin>>T;
  for(int t=1;t<=T;t++){
    ll ans=0,sum=0;
    cin>>E>>R>>N;
    for(int i=0;i<11;i++){
      for(int j=0;j<11;j++){
        dp[i][j]=-1;
      }
    }
    for(int i=0;i<N;i++){
      cin>>v[i];
      sum+=v[i];
    }
    if(E<=R){
      ans+=sum*E;
      goto END;
    }
    ans=rec(N-1,0);
    /*for(int i=0;i<N;i++){
      for(int j=0;j<=E;j++){
        cout<<dp[i][j]<<" ";
      }
      cout<<endl;
    }*/
  END:
    printf("Case #%d: ",t);cout<<ans<<endl;
  }
}

