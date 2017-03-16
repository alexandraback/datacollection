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
    int k,c,s; cin>>k>>c>>s; //assumption is s=k
    cout<<"Case #"<<t+1<<":";
    REP(i,0,k) cout<<" "<<(i*my_pow(k,c-1))+1;
    cout<<"\n";
  }
  return 0;
}
