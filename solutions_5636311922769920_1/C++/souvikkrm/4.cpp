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
#define MAX 110
using namespace std;
int main()
{
  int tc; cin>>tc;
  REP(t,0,tc)
  {
    int k,c,s; cin>>k>>c>>s;
    cout<<"Case #"<<t+1<<":";
    if(c==1)
    {
      if(s<k) cout<<" IMPOSSIBLE\n";
      else
      {
        REP(i,1,k+1) cout<<" "<<i;
        cout<<"\n";
      }
    }
    else
    {
      int m=(k+1)>>1;
      if(s<m) cout<<" IMPOSSIBLE\n";
      else
      {
        REP(i,0,m) cout<<" "<<(i+1)*k-i;
        cout<<"\n";
      }
    }
  }
  return 0;
}
