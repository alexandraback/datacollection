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

char s[1000010];
int ok[255];

int main() {
  //freopen("A-small-attempt0.in","r",stdin);
  freopen("A-large.in","r",stdin);
  //freopen("A-small.out","w",stdout);
  freopen("A-large.out","w",stdout);

  memset(ok,true,sizeof(ok));
  ok['a']=0;
  ok['e']=0;
  ok['i']=0;
  ok['o']=0;
  ok['u']=0;

  int T;
  sf("%d",&T);
  rep(t,1,T) {

    int n,m;
    sf("%s%d",s+1,&m);
    n=strlen(s+1);

    vec<pii> seg;
    rep(i,1,n)
      if (ok[s[i]]) {
        int j;
        for (j=i; j+1<=n && ok[s[j+1]]; j++);
        if (j-i+1>=m) {
          seg.pb(pii(i,j));
          //pf("<%d,%d> %d %d\n",i,j,j-i+1,m);
        }
        i=j;
      }

    ll ans=0;
    rep(i,1,n) {
      int j=lower_bound(all(seg),pii(i,0))-seg.begin()-1;
      gmax(j,0);

      //pf("i=%d j=%d\n",i,j);
      while (j<sz(seg) && seg[j].y<i) j++;
      if (j<0||j>=sz(seg)) continue;
      if (seg[j].y-i+1<m) j++;
      if (j<0||j>=sz(seg)) continue;

      if (seg[j].x<i) j=i+m-1; else j=seg[j].x+m-1;

      ans+=n-j+1;
      //pf("[%d,%d] %d\n",i,j,n-j+1);
    }
    pf("Case #%d: %I64d\n",t,ans);
  }
  return 0;
}
