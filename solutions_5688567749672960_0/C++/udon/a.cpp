#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
const ll INF = 5000000000;
#define PB push_back
#define sz(a) (a).size()
#define reps(i,n,m) for(int (i)=(n);(i)<int(m);++(i))
#define rep(i,n) reps(i,0,n)
ll T;
ll rev(ll num) {
  ll ans=0;
  while(num>0) {
    ll a = num%10;
    ans = ans*10 + a;
    num/=10;
  }
  return ans;
}
#define N 1500000
ll dp[N];
int main(){
  rep(i, N){
    dp[i]=i;
  }
  rep(i, N){
    if(i+1<N)
      dp[i+1]=min(dp[i+1], dp[i]+1);
    ll r = rev(i);
    if(r<N)
      dp[r]=min(dp[r], dp[i]+1);
  }
  cin >> T;
  reps(times, 1, T+1) {
    ll n;
    ll cnt =1;
    cin>>n;
    printf("Case #%d: %lld\n", times, dp[n]);
  }

}
