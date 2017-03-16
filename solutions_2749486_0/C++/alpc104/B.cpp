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

const int dx[]={0,0,-1,1},
          dy[]={-1,1,0,0};

char get_char(pii b,pii a) {
  a.x=b.x-a.x;
  a.y=b.y-a.y;
  if (a.x==0&&a.y>0) return 'N';
  if (a.x==0&&a.y<0) return 'S';
  if (a.x>0&&a.y==0) return 'E';
  if (a.x<0&&a.y==0) return 'W';
}

int main() {
  freopen("B-small-attempt0.in","r",stdin);
  freopen("B-small.out","w",stdout);

  int T;
  sf("%d",&T);
  rep(t,1,T) {

    pii aim,ini=pii(0,0);
    sf("%d%d",&aim.x,&aim.y);

    map<pii,pii> g;
    queue<pii> q;
    queue<int> step;
    q.push(ini);
    step.push(1);
    g[ini]=ini;

    while (sz(q)) {
      pii cur=q.front();
      //pf("(%d,%d)\n",cur.x,cur.y);
      if (cur==aim) {
        pf("Case #%d: ",t);
        string opt;
        while (cur!=ini) {
          //pf("[%d,%d]\n",cur.x,cur.y);
          opt=get_char(cur,g[cur])+opt;
          cur=g[cur];
        }
        puts(opt.data());
        break;
      }

      rep(d,0,3) {
        pii tmp=pii(cur.x+dx[d]*step.front(),cur.y+dy[d]*step.front());
        if (g.find(tmp)==g.end()) {
          g[tmp]=cur;
          q.push(tmp);
          step.push(step.front()+1);
        }
      }

      q.pop();
      step.pop();
    }

  }
  return 0;
}
