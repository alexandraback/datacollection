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
typedef pair<ll,ll> P;

void Main() {
  int T;
  R T;
  REP(tt,1,T+1) {
    ll n,m;
    cin >> n >> m;
    cout << "Case #" << tt << ": ";
    ll xx=m;
    ll a[n][n];
    mem(a);
    m--;
    a[0][n-1]=1;
    ll d[n];
    mem(d);
    d[n-1]=1;
    rrep(i,n-1) {
      bool f=0;
      REP(j,i+1,n) {
        if(d[j]&&m>=d[j]) {
          m-=d[j];
          a[i][j]=1;
          d[i]+=d[j];
          f=1;
        }
      }
      if(f&&i) a[0][i]=1;
    }
    ll dp[n];
    mem(dp);
    dp[0]=1;
    rep(i,n-1) {
      REP(j,i+1,n) {
        if(a[i][j]==1) dp[j]+=dp[i];
      }
    }
    if(m||dp[n-1]!=xx)pr("IMPOSSIBLE");
    else {
      pr("POSSIBLE");
      rep(i,n){
        rep(j,n)cout << a[i][j];
        ln;
      }
    }
  }
}

int main() {
  ios::sync_with_stdio(0);cin.tie(0);
  Main();return 0;
}
