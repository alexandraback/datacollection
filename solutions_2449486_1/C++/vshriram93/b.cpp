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
int a[101][101],n,m,cnt;
struct node {
  int no,posi,posj;
  node(){no=INF;posi=INF;posj=INF;}
  node(int _no,int _posi,int _posj) {no=_no,posi=_posi,posj=_posj;}
}nn[10001];
bool operator<(node t,node b) {
  return t.no<b.no;
}

bool valid(node t) {
  bool fl=1;
  REP(i,n) {
    if(a[i][t.posj]<=t.no) continue;
    fl=0;
  }
  if(fl) return true;
  REP(i,m) {
    if(a[t.posi][i]<=t.no) continue;
    fl=1;
  }
  if(!fl) return true;
}
int main(int argc,char **argv) {
  fii;fio;
  int kase=GI,t=1;
  while(kase--) {
    n=GI,m=GI,cnt=0;
    bool fl=0;
    REP(i,n) REP(j,m) {
      a[i][j]=GI;
      nn[cnt++]=node(a[i][j],i,j);
    }
    sort(nn,nn+cnt);
    REP(i,cnt) {
      if(valid(nn[i])) continue;
      fl=1;
      break;
    }  
    if(fl) printf("Case #%d: %s\n",t++,"NO");
    else  printf("Case #%d: %s\n",t++,"YES");
  }
}
