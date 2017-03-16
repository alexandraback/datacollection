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
typedef pair<ll,P> PP;
void Main() {
  int T;
  R T;
  REP(tt,1,T+1) {
    int a,b,c,m;
    cin >> a >> b >> c >> m;
    vector<P> v;
    rep(j,b)rep(k,c)v.pb(P(j+1,k+1));
    sort(all(v));
    vector<PP> ans;
    do {
      map<P,ll> ma;ma.clear();
      vector<PP> e;
      int x=1;
      rep(ttt,m) {
        rep(j,v.size()) {
          int y=v[j].F*100,z=v[j].S*10000;
          if(ma[P(x,y)]>=m||ma[P(x,z)]>=m||ma[P(y,z)]>=m) {
            x++;
            if(x==a+1) x=1;
            continue;
          }
          ma[P(x,y)]++;
          ma[P(x,z)]++;
          ma[P(y,z)]++;
          e.pb(PP(x,P(y/100,z/10000)));
        }
      }
      sort(all(e));
      e.erase(unique(all(e)),e.end());
      if(e.size()>ans.size()) ans=e;
    } while(next_permutation(all(v)));
    cout << "Case #" << tt << ": " << ans.size() << endl;
    rep(i,ans.size()) cout << ans[i].F << " " << ans[i].S.F << " " << ans[i].S.S << endl;
  }
}

int main() {
  ios::sync_with_stdio(0);cin.tie(0);
  Main();return 0;
}
