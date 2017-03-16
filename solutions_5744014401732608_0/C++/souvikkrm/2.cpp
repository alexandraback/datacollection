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
#define MAX 55
using namespace std;
char x[MAX][MAX];
LL my_pow(int a,int b)
{
  LL x=1,y=a;
  while(b)
  {
    if(b%2) x*=y;
    y*=y; b>>=1;
  }
  return x;
}
int main()
{

  int tc; cin>>tc;
  REP(t,0,tc)
  {
    int b; LL m; cin>>b>>m;
    REP(i,0,b) REP(j,0,b) x[i][j]='0';
    int i=0,o=m;
    while(i<b-1 && m)
    {
      int j=1;
      while(i+j<b && m)
      {
       if(x[i][i+j]=='0') { x[i][i+j]='1'; m--; }
       if(i+j!=b-1 && x[i+j][b-1]=='0') x[i+j][b-1]='1';
       j++;
      }
      i++;
    }
    cout<<"Case #"<<t+1<<": ";
    if(!m || o==my_pow(2,b-2))
    {
      cout<<"POSSIBLE\n";
      REP(i,0,b)
      {
        REP(j,0,b) cout<<x[i][j];
        cout<<"\n";
      }
    }
    else cout<<"IMPOSSIBLE\n";
  }
  return 0;
}
