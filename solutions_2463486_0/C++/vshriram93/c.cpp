#include <cstdlib>
#include <cctype>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
#include <iostream>
#include <sstream>
#include <map>
#include <set>
#include <queue>
using namespace std;

typedef long long LL;
#define pb push_back
#define mp make_pair
#define REP(i,n) FOR(i,0,n)
#define FOR(i,a,b) for(int i = a; i < b; i++)
#define ROF(i,a,b) for(int i=a;i>b;i--)
#define GI ({int t;scanf("%d",&t);t;})
#define GL ({LL t;scanf("%lld",&t);t;})
#define GD ({double t;scanf("%lf",&t);t;})
#define GC ({char t;scanf("%c",&t);t;})
#define SET(x,a) memset(x,a,sizeof(x))
#define ALL(x) (x.begin(),x.end())
#define INF (int)1e9
#define fii freopen("in.txt","r",stdin)
#define fio freopen("out.txt","w",stdout)
#define MOD 1000000007
template<class T> inline T big(T a,T b) {return a>b?a:b;} 
template<class T> inline T small(T a,T b) {return a<b?a:b;} 

int ans[10000001];
LL rev(LL no) {
  LL temp=0;
  while(no) {
    temp=temp*10+(no%10);
    no/=10;
  }
  return temp;
}
bool palin(LL no) {
  LL temp=rev(no);
  if(temp==no) return 1;
  return 0;
}
LL fsqrt(LL a,int qw) {
  LL fr=1,end=10000000,ans=1;
  while(fr<=end) {
    LL mid=(fr+end)/2;
    LL temp=mid*mid;
    if(temp==a) return mid;
    if(temp>a) end=mid-1;
    else {
      ans=max(ans,mid);
      fr=mid+1;
    }
  }
  if(!qw) ans++;
  return ans;
}
int main(int argc,char **argv) {
  fii;fio;
  int kase=GI,t=1;
  ans[0]=0;
  FOR(i,1,10000001) {
    ans[i]=ans[i-1];
    LL temp=(LL)(i)*(LL)(i);
    if(palin(temp)&&palin(i))  ans[i]++;
  }
  while(kase--) {
    LL a=fsqrt(GL,0);
    LL b=fsqrt(GL,1);
    printf("Case #%d: %d\n",t++,(ans[b]-ans[a-1]));
  }
}
