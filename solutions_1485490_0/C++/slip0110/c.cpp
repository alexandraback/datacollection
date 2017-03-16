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
typedef pair<ll , int> P;
ll dp[110][110];
vector<P> a;
vector<P> b;
int n,m;
ll ans;
void solve(int s , int t , ll res){
  //cout<<s<<" "<<t<<" "<<res<<" "<<a[s].second<<" "<<b[t].second<<endl;
  if(s == n && t == m){
    ans = max(ans , res);
  }
  if(s == n || t == m)return;
  ll tmp = 0;
  if(a[s].second == b[t].second){
    tmp = min(a[s].first,b[t].first);
    a[s].first -= tmp;
    b[t].first -= tmp;
    res += tmp;
    //ut<<"test"<<endl;
  }
  solve(s+1,t,res);
  solve(s,t+1,res);
  solve(s+1,t+1,res);
  a[s].first += tmp;
  b[t].first += tmp;
}
int main(){
  int T;
  cin>>T;
  for(int t = 1 ; t <= T ;t++ ){
    cin>>n>>m;
    a.clear();
    b.clear();
    rep(i,n){
      P tmp;
      cin>>tmp.first>>tmp.second;
      a.push_back(tmp);
    }
    rep(i,m){
      P tmp;
      cin>>tmp.first>>tmp.second;
      b.push_back(tmp);
    }
    ans = 0;
    solve(0,0,0LL);
    cout<<"Case #"<<t<<": "<<ans<<endl;
  }
}
