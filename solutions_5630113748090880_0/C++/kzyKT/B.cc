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
typedef pair<int,int> P;

void Main() {
  int T;
  R T;
  REP(tt,1,T+1) {
    int n;
    R n;
    int m=n*2-1;
    vector<int> a[m+2];
    int d[2501];
    mem(d);
    rep(i,m) {
      vector<int> v(n);
      rep(j,n) {
        R v[j];
        d[v[j]]++;
      }
      a[i]=v;
    }
    rep(i,n) a[m].pb(0);
    rep(i,n) a[m+1].pb(2501);
    sort(a,a+m+2);
    cout << "Case #" << tt << ": ";
    vector<int> v;
    REP(i,1,2501) {
      if(d[i]%2) v.pb(i);
    }
    PR(v,n);
    /*
    REP(k,1,2501-n) {
      int v[n];
      rep(i,n) v[i]=k+i;
      rep(i,m+1) {
        bool f=1;
        rep(l,m+2) {
          rep(j,n) {
            if(l<=i) {
              if(a[l][j]>=v[j]) f=0;
            } else {
              if(v[j]>=a[l][j]) f=0;
            }
          }
        }
        if(f) {
          PR(v,n);
          goto end;
        }
      }
    }
  end:;
    */
  }
}

int main() {
  ios::sync_with_stdio(0);cin.tie(0);
  Main();return 0;
}
