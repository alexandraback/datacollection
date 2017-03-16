// pre-written code {{{
#include <cstdio>
#include <cmath>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <queue>
#include <numeric>
#include <iostream>
#include <cassert>
#include <set>
#include <sys/resource.h>
#define FOR(i,n) for(int _n=n,i=0;i<_n;++i)
#define FR(i,a,b) for(int _b=b,i=a;i<_b;++i)
#define CL(x) memset(x,0,sizeof(x))
#define PN printf("\n");
#define MP make_pair
#define PB push_back
#define SZ size()
#define ALL(x) x.begin(),x.end()
#define FORSZ(i,v) FOR(i,v.size())
#define FORIT(it,x) for(__typeof(x.begin()) it=x.begin();it!=x.end();it++)
using namespace std;
typedef vector<int> VI;
typedef vector<string> VS;
typedef long long LL;
void stackSizeUnlimited() { struct rlimit rl; getrlimit(RLIMIT_STACK, &rl); rl.rlim_cur = RLIM_INFINITY; setrlimit(RLIMIT_STACK, &rl); }
///////////////////////////////////////////////////////////////////////////////////
// }}}

//maxflow vrati velkost toku , ale treba naplnit 'n' a 'cap' (graf je orientovany)
#define REP(i,n) for(int _n=n,i=0;i<_n;++i)
const int MAXN = 2005;
 
int n;
int cap[MAXN][MAXN];
int rescap[MAXN][MAXN];
int vis[MAXN];
int start,goal;
 
int augpath(int x) {
  vis[x]=true;
  if(x==goal) return true;
  REP(y,n) if(!vis[y] && rescap[x][y]) {
    int T=min(augpath(y),rescap[x][y]);
    if(T){     
      rescap[x][y]-=T;
      rescap[y][x]+=T;
      return T;
    }
  }
  return 0;
}
 

int maxflow(int st,int gl) {
  start=st; goal=gl;
  REP(i,n) REP(j,n) rescap[i][j]=cap[i][j];
  int res = 0;
  while(1) {
    CL(vis);
    int T=augpath(st);
    if(!T) break; else res+=T;
  }
  return res;
}

void solve(){
  int s; scanf("%d\n",&s);
  int dega[2005]; CL(dega);
  int degb[2005]; CL(degb);
  CL(cap);
  map<string, int> ca;
  map<string, int> cb;
  int num = 0;
  FOR(i,s) {
    char a[30],b[30];
    scanf("%s %s\n",a,b);
    int cca,ccb;
    if(!ca.count(a)) {
      ca[a] = num;     
      num++;
    }
    if(!cb.count(b)) {
      cb[b] = num;     
      num++;
    }
    cca = ca[a];
    ccb = cb[b];
    dega[cca]++;
    degb[ccb]++;
    cap[cca][ccb]++;
  }  
  FORIT(it, ca) {
    cap[num+1][it->second] = dega[it->second] -1 ;
  }
  FORIT(it, cb) {
    cap[it->second][num+2] = degb[it->second] -1;
  }  
  n=num+3;
  printf("%d\n",maxflow(num+1,num+2));
}

int main(){
  stackSizeUnlimited();
  int pvs; scanf("%d",&pvs);
  FR(ppp,1,pvs+1){
     printf("Case #%d: ",ppp);

     solve();
  }
}


// vim: fdm=marker:commentstring=\ \"\ %s:nowrap:autoread
