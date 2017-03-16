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

#define N 128
int a[N],n;

int check(int m) {
  int res=n-m;

  deque<int> b;
  rep(i,1,m) b.pb(a[i]);

  int cur=a[0];
  while (sz(b)) {
    if (cur>b.front()) {
      cur+=b.front();
      b.pop_front();
    } else {
      cur+=cur-1;
      res++;
    }
  }

  return res;
}

int main() {
  freopen("A-large.in","r",stdin);
  freopen("A-large.out","w",stdout);

  int T;
  sf("%d",&T);

  rep(t,1,T) {
    sf("%d%d",&a[0],&n);

    int ans=n;
    rep(i,1,n) sf("%d",a+i);

    if (a[0]<=1) goto next;
    sort(a+1,a+1+n);

    rep(i,0,n) gmin(ans,check(i));

    next: pf("Case #%d: %d\n",t,ans);
  }
  return 0;
}
