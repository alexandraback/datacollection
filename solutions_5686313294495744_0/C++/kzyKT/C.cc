#include <bits/stdc++.h>
using namespace std;
#define all(c) (c).begin(),(c).end()
#define rrep(i,n) for(int i=(int)(n)-1;i>=0;i--)
#define REP(i,m,n) for(int i=(int)(m);i<(int)(n);i++)
#define rep(i,n) REP(i,0,n)
#define iter(c) __typeof((c).begin())
#define tr(it,c) for(iter(c) it=(c).begin();it!=(c).end();it++)
#define mem(a) memset(a,0,sizeof(a))
#define pd(a) printf("%.10f\n",a)
#define pb(a) push_back(a)
#define in(a) insert(a)
#define pi M_PI
#define R cin>>
#define F first
#define S second
#define C class
#define ll long long
#define ln cout<<'\n'
#define _(_1,_2,_3,N,...)N
#define pr(...) _(__VA_ARGS__,pr3,pr2,pr1)(__VA_ARGS__)
template<C T>void pr1(T a){cout<<a;ln;}
template<C T,C T2>void pr2(T a,T2 b){cout<<a<<' '<<b;ln;}
template<C T,C T2,C T3>void pr3(T a,T2 b,T3 c){cout<<a<<' '<<b<<' '<<c;ln;}
template<C T>void PR(T a,int n){rep(i,n){if(i)cout<<' ';cout<<a[i];}ln;}
bool check(int n,int m,int x,int y){return x>=0&&x<n&&y>=0&&y<m;}
const ll MAX=1000000007,MAXL=1LL<<60,dx[4]={-1,0,1,0},dy[4]={0,1,0,-1};
typedef pair<string,string> P;

void Main() {
  int T;
  R T;
  REP(tt,1,T+1) {
    int n;
    R n;
    P a[n];
    rep(i,n) cin >> a[i].F >> a[i].S;
    int dp[1<<n];
    memset(dp,-1,sizeof(dp));
    dp[0]=0;
    int ans=0;
    rep(t,1<<n) {
      if(dp[t]==-1) continue;
      ans=max(ans,dp[t]);
      rep(i,n) {
        if(t&(1<<i)) continue;
        bool f=0,f2=0;
        rep(j,n) {
          if(!(t&(1<<j))) continue;
          if(a[i].F==a[j].F) f=1;
          if(a[i].S==a[j].S) f2=1;
        }
        int c=0;
        if(f&&f2) c++;
        dp[t|(1<<i)]=max(dp[t|(1<<i)],dp[t]+c);
      }
    }
    cout << "Case #" << tt << ": " << ans << endl;
  }
}

int main() {
  ios::sync_with_stdio(0);cin.tie(0);
  Main();return 0;
}
