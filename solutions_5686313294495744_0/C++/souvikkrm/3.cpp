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
#define msi map<st,int>
#define cl clear
#define fr front
#define em empty
using namespace std;
st x[16],y[16]; msi p,q;
int v[1<<16];
int main()
{
  int tc; cin>>tc;
  REP(t,0,tc)
  {
    int n; cin>>n;
    REP(i,0,n) cin>>x[i]>>y[i];
    REP(i,0,n)
    {
      p[x[i]]++;
      q[y[i]]++;
    }
    int m=(1<<n),ans=0;
    v[0]=1;
    REP(i,1,m-1)
    {
      int c=0;
      REP(j,0,n) if(i&(1<<j)) { p[x[j]]--; q[y[j]]--; c++; }
      REP(j,0,n) if(i&(1<<j) && v[i^(1<<j)] && p[x[j]] && q[y[j]]) { ans=max(ans,c); v[i]=1; break; }
      REP(j,0,n) if(i&(1<<j)) { p[x[j]]++; q[y[j]]++; }
    }
    cout<<"Case #"<<t+1<<": "<<ans<<"\n";
    //clean-up
    p.cl(); q.cl(); mems(v);
  }
  return 0;
}
