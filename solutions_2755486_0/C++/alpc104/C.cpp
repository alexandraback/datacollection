#include <iostream>
#include <iomanip>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <bitset>
using namespace std;
#define inf 0x7fffffff
#define eps 1e-9
#define ll long long
#define ld long double
#define pii pair<int,int>
#define x first
#define y second
#define sf scanf
#define pf printf
#define vec vector
#define pb push_back
#define mp make_pair
#define sz(a) int(a.size())
#define all(a) a.begin(),a.end()
#define bin_cnt(x) __builtin_popcount(x)
#define rep(i,a,b) for(int i=a;i<=b;i++)
#define rrep(i,b,a) for(int i=b;i>=a;i--)
#define irep(i,a) for(__typeof(a.begin()) i=a.begin();i!=a.end();i++)
#define dbg(x) cerr<<__LINE__<<": "<<#x<<" = "<<(x)<<endl
//#pragma comment(linker, "/STACK:32505856")

template<class T> inline void gmin(T&a,T b) {if(a>b)a=b;}
template<class T> inline void gmax(T&a,T b) {if(a<b)a=b;}
inline int sign(const double &a) {return a>eps?1:(a<-eps?-1:0);}
struct Initializer{Initializer(){ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);}~Initializer(){}}initializer;

vec<int> d;

int cmp(const int& a,const int& b) {
  return d[a]<d[b];
}

int _h[2048],*h=&_h[1024];
int _h2[2048],*h2=&_h2[1024];

int main() {
  freopen("C-small-attempt0.in","r",stdin);
  freopen("C-small.out","w",stdout);

  int T;
  cin>>T;
  rep(t,1,T) {

    int n;
    cin>>n;

    vec<int> day0(n),att(n),
             l0(n),r0(n),s0(n),
             dd(n),dp(n),ds(n);

    vec<int> l,r,s;
    d.clear();

    rep(i,0,n-1) {
      cin>>day0[i]>>att[i]>>
        l0[i]>>r0[i]>>s0[i]>>
        dd[i]>>dp[i]>>ds[i];

      int dc=day0[i],
          lc=l0[i],rc=r0[i],
          sc=s0[i];

      rep(j,1,att[i]) {
        d.pb(dc);
        l.pb(lc);
        r.pb(rc-1);
        s.pb(sc);

        dc+=dd[i];
        lc+=dp[i];
        rc+=dp[i];
        sc+=ds[i];
      }
    }

    n=sz(d);
    vec<int> idx(n);
    rep(i,0,n-1) idx[i]=i;
    sort(all(idx),cmp);

    int ans=0;
    memset(_h,0,sizeof(_h));
    rep(i,0,n-1) {
      int j;
      for (j=i;j+1<n&&d[idx[j+1]]==d[idx[i]];j++);

      memset(_h2,0,sizeof(_h2));
      rep(k,i,j) {
        int flag=0;
        rep(i,l[idx[k]],r[idx[k]]) {
          if (h[i]<s[idx[k]]) {
            gmax(h2[i],s[idx[k]]);
            flag=1;
          }
        }
        ans+=flag;
        //pf("%d: [%d,%d] S=%d %c\n",d[idx[k]],l[idx[k]],r[idx[k]],s[idx[k]],flag?'!':' ');
      }
      rep(i,-1000,1000) gmax(h[i],h2[i]);

      i=j;
    }
    cout<<"Case #"<<t<<": "<<ans<<endl;

  }
  return 0;
}
