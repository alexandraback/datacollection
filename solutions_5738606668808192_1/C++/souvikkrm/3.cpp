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
#define MAX 32
using namespace std;
int y[MAX];
inline void disp_and_reset(int n)
{
  DEP(i,n,0) cout<<y[i];
  REP(i,2,11) cout<<" "<<i+1;
  cout<<"\n";
  mems(y);
}
int build_for_0(int n,int r)
{
  if(!r) return 0;
  y[0]=y[n-1]=1;
  disp_and_reset(n);
  return r-1;
}
int build_for_1(int n,int r)
{
  REPX(i,1,n-1,2) REPX(j,2,n,2)
  {
    if(r)
    {
      y[n-1]=y[0]=y[i]=y[j]=1; //we will disp reverse
      disp_and_reset(n);
      r--;
    }
    else return 0;
  }
  return r;
}
int build_for_2(int n,int r)
{
  REPX(i,1,n-1,2) REPX(j,i+2,n-1,2) REPX(k,2,n,2) REPX(l,k+2,n,2)
  {
    if(r)
    {
      y[n-1]=y[0]=y[i]=y[j]=y[k]=y[l]=1;
      disp_and_reset(n);
      r--;
    }
    else return 0;
  }
  return r;
}

int main()
{
  int tc; cin>>tc; //always 1 test case
  REP(t,0,tc)
  {
    int n,j; cin>>n>>j; //n=16,j=50 or n=32,j=500. n is even :)
    cout<<"Case #"<<t+1<<":\n";
    REP(k,0,3) //given the conditions, k<=2
    {
      if(!k) j=build_for_0(n,j);
      else if(k==1) j=build_for_1(n,j);
      else j=build_for_2(n,j);
    }
  }
  return 0;
}
