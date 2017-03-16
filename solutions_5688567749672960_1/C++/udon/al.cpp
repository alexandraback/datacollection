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
#define N 15000000

ll dp[N];
ll ldp[2][N];
typedef pair<ll, pair<int, int> > dat;
vector<dat> data;
dat create(ll a, int b, int c){
  assert(b==0 || b==1);
  return make_pair(a, make_pair(b,c));
}
ll search(ll num) {
  int l = 0, r=data.size();
  while(l+1<r){
    int med = (l+r)/2;
    if(num<data[med].first) {
      r = med;
    } else {
      l = med;
    }
  }
  dat d = data[l];
  ll dif = num-d.first;
  return ldp[d.second.first][d.second.second] + dif;
}



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
  rep(i, N){
    rep(x,2){
      ll rnum = i;
      ll c=i;
      while(c>0){
        rnum *= 10;
        c/=10;
      }
      if(x)rnum*=10;
      rnum += 1;
      data.push_back(create(rnum, x, i));
      if(rnum<N){
        ldp[x][i] = dp[rnum];
        continue;
      }
    }
  }

  sort(data.begin(), data.end());

  rep(i, data.size()){
    ll num = data[i].first;
    if(num < N)continue;
    ll x = data[i].second.first;
    ll y = data[i].second.second;
    ll r = rev(num);
    ldp[x][y] = search(r)+1;
  }
  cerr<<"start!!"<<endl;
  cin >> T;
  reps(times, 1, T+1) {
    ll n;
    cin>>n;
    printf("Case #%d: %lld\n", times, search(n));
  }

}
