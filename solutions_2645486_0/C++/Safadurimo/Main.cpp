#include <iostream>
#include <string>
#include <cassert>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <ctime> 

using namespace std;

typedef string Date;
typedef long long ll;


ll f(ll n, ll r){
  return n*(2*r-3)+2*n*(n+1);
}

int main() 
{
  int T;
  cin >> T;
  for(int x=1;x<=T;x++){
  int E,R,N;
  cin >> E >> R >> N;
  vector<int> v;
  for(int i=0;i<N;i++){
    int x;
    cin >> x;
    v.push_back(x);
  }
  int dp[6][11];
  memset(dp,-1,6*11*sizeof(int));
  dp[E][0]=0;
  for(int i=1;i<=N;i++){
    for(int j=0;j<6;j++){
      if(dp[j][i-1]!=-1){
        for(int k=0;k<=j;k++){
          // new energy after spending k
          int en= j-k;
          en=min(en+R,E);
          dp[en][i] =max(dp[en][i],v[i-1]*k+dp[j][i-1]);
        }
      }
    }
  }
  int m=-1;
  for(int i=0;i<=E;i++) m=max(m,dp[i][N]);

    cout << "Case #" << x << ": " << (m) << endl;
  }
}
