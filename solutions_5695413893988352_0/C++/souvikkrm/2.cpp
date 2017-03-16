#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <algorithm>
#include <functional>
#include <utility>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <string>

#define LL long long
#define vi vector<int>
#define pb push_back
#define sz size
#define all(x) (x).begin(),(x).end()
#define it iterator
#define REP(i,a,b) for(int i=(a);i<(b);i++)
#define REPX(i,a,b,c) for(int i=(a);i<(b);i+=(c))
#define DEP(i,a,b) for(int i=(a)-1;i>=(b);i--)
#define REX(i,x) for(__typeof((x).begin()) i=(x).begin(); i!=(x).end();i++)
#define pii pair<int,int>
#define mp make_pair
#define fi first
#define se second
#define st string
#define ffo find_first_of
#define su substr
#define vs vector<st>
#define vpii vector<pii >
#define ub upper_bound
#define lb lower_bound
#define mems(x) memset(x,0,sizeof(x))
#define memc(x,y) memcpy(x,y,sizeof(y))
#define cl clear
#define fr front
#define em empty
#define INF 100010
using namespace std;
st x,y,a,b;
int main()
{
  int tc; cin>>tc;
  REP(t,0,tc)
  {
    cin>>x; cin>>y;
    int n=(int)x.sz(),md=INF;
    REP(i,0,10) REP(j,0,10) REP(k,0,10) REP(e,0,10) REP(f,0,10) REP(g,0,10)
    {
      st p,q;
      if(x[0]=='?') p.pb(i+'0');
      else p.pb(x[0]);
      if(n>1 && x[1]=='?') p.pb(j+'0');
      else if(n>1) p.pb(x[1]);

      if(n>2 && x[2]=='?') p.pb(k+'0');
      else if(n>2) p.pb(x[2]);

      if(y[0]=='?') q.pb(e+'0');
      else q.pb(y[0]);
      if(n>1 && y[1]=='?') q.pb(f+'0');
      else if(n>1) q.pb(y[1]);

      if(n>2 && y[2]=='?') q.pb(g+'0');
      else if(n>2) q.pb(y[2]);

      int r=atoi(p.c_str());
      int s=atoi(q.c_str());
      if(abs(r-s)<md) { md=abs(r-s); a=p; b=q; }
      else if(abs(r-s)==md)
      {
        if(r<atoi(a.c_str()) || (r==atoi(a.c_str()) && s<atoi(b.c_str()))) { a=p; b=q; }
      }
    }
    cout<<"Case #"<<t+1<<": "<<a<<" "<<b<<"\n";
  }
  return 0;
}
