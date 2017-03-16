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

int valid(string s) {
  if(s=="XXXX"||s=="XXXT"||s=="XXTX"||s=="XTXX"||s=="TXXX") return 1;
  if(s=="OOOO"||s=="OOOT"||s=="OOTO"||s=="OTOO"||s=="TOOO") return 2;
  return 0;
}
int main(int argc,char **argv) {
  fii;fio;
  int kase=GI,t=1;
  string s[4],temp="....";
  while(kase--) {
    int ans=0;
    REP(i,4) cin>>s[i];
    REP(i,4)  {
      REP(j,4) temp[j]=s[i][j];
      ans=valid(temp);
      if(ans) break;
      REP(j,4) temp[j]=s[j][i];
      ans=valid(temp);
      if(ans) break;
    }
    if(!ans) {
      REP(i,4) temp[i]=s[i][i];
      ans=valid(temp);
      if(!ans) {
	REP(i,4) temp[i]=s[i][3-i];
      	ans=valid(temp);
      }
    }
    if(ans==1) printf("Case #%d: %s\n",t++,"X won");
    else if(ans==2) printf("Case #%d: %s\n",t++,"O won");
    else {
      bool fl=1;
      REP(i,4) REP(j,4) if(s[i][j]=='.') fl=0;
      if(fl) printf("Case #%d: %s\n",t++,"Draw");
      else printf("Case #%d: %s\n",t++,"Game has not completed");
      
    }
  }
}
