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
#define MAX 1000010
using namespace std;
LL x[MAX]; int y[10];
inline void add_digit_count(LL n)
{
  while(n)
  {
    y[n%10]=1;
    n/=10;
  }
}
inline int all_digits_covered()
{
  int f=1;
  REP(i,0,10) f&=y[i];
  return f;
}
int main()
{
  //pre-compute
  x[0]=-1; //infinite
  REP(i,1,MAX)
  {
    LL j=0;
    do
    {
      j+=i;
      add_digit_count(j);
    }while(!all_digits_covered());
    x[i]=j;
    //clean-up
    mems(y);
  }
  int tc; cin>>tc;
  REP(t,0,tc)
  {
    int n; cin>>n;
    if(x[n]==-1) cout<<"Case #"<<t+1<<": INSOMNIA\n";
    else cout<<"Case #"<<t+1<<": "<<x[n]<<"\n";
  }
  return 0;
}
