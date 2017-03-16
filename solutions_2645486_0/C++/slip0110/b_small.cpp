#include<iostream>
#include<algorithm>
#include<set>
#include<vector>
#include<map>
#include<deque>
#include<queue>
#include<complex>
#include<string>
#include<cstring>
#include<cmath>
#include<cstdio>
#include<cstdlib>

using namespace std;

#define REP(i,a,n) for(int i = a ; i < n ; i++)
#define rep(i,n) REP(i,0,n)

typedef long long ll;
int dp[100][100];
int ene[100];
int res;
int E,R,N;
void solve(){
  rep(i,100)rep(j,100) dp[i][j] = -1;
  dp[0][E] = 0;
  rep(i,N){
    rep(j,E+1){
      rep(k,j+1){
        dp[i+1][min(j-k+R , E)] 
          = max(dp[i+1][min(j-k+R , E)] , dp[i][j] + ene[i] * k);
      }
    }
  }
  /*
  rep(i,N+1){
    rep(j,E+1){
      cout<<dp[i][j]<<" ";
    }
    cout<<endl;
  }
  */
  res = -1;
  rep(i,E+1){
    res = max(res , dp[N][i]);
  }
}
int main(){
  int T;
  cin>>T;
  int C = 1;
  while(T--){
    cin>>E>>R>>N;
    rep(i,N){
      cin>>ene[i];
    }
    solve();
    cout<<"Case #"<<C<<": "<<res<<endl;
    C++;
  }
}
