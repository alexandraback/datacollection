#include<cstdio>
#include<cmath>
#include<string>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
typedef long long ll;
int T;
ll E,R,N;
ll V[1001];
ll dp[1001][1001];
ll solve(int no,int e){
  if(no == N) return 0;
  if(dp[no][e]!=-1) return dp[no][e];
  ll ret = 0;
  for(int i=e;i>=0;i--){
    ret = max(ret, solve(no+1,min(E,e-i+R))+i*V[no]);
  }
  return dp[no][e]=ret;
}
int main(){
  cin >> T;
  for(int loop=1;loop<=T;loop++){
    memset(dp,-1,sizeof(dp));
    cin >> E >> R >> N;
    for(int i=0;i<N;i++)
      cin >> V[i];
    cout << "Case #"<<loop<<": "<<solve(0,E) << "\n";
  }
}
