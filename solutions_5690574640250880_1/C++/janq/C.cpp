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
///////////////////////////////////////////////////////////////////////////////////
// }}}

int r,c,m;
char a[55][55];
int deg[55][55];

bool dnu(int x, int y){
  return (0<=x && x<r && 0<=y && y<c);
}

bool evaluate(int blank) {
//  FOR(i,r) {
//    FOR(j,c) printf("%c",a[i][j]); PN;
//  }
  bool wasc=false;
  FOR(i,r) FOR(j,c) {
    deg[i][j]=0;
    FR(dx,-1,2) FR(dy,-1,2) if(dnu(i+dx,j+dy)) if(a[i+dx][j+dy]=='*') deg[i][j]++;
  }  
  FOR(i,r) FOR(j,c) if(a[i][j]=='.') {
    int zeros=0;
    FR(dx,-1,2) FR(dy,-1,2) if(dnu(i+dx,j+dy)) if(deg[i+dx][j+dy]==0) zeros++;
    if(zeros==0) {
      if(blank==1) {
        a[i][j]='c';
        return true;
      } else {
        return false;
      }
    }
  }
  FOR(i,r) FOR(j,c) if(a[i][j]=='.') if(deg[i][j]==0) {
    a[i][j]='c';
    return true;
  }
}

void vysledok(int e){
      int em=0;
      FOR(i,r) {
        FOR(j,c) if(a[i][j]!='*') em++;
      }
      int cc=0;
      FOR(i,r) {
        FOR(j,c) if(a[i][j]=='c') cc++;
      }
      if(em!=e || cc!=1) printf("ZLEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEE\n");

      FOR(i,r) {
        FOR(j,c) printf("%c",a[i][j]); PN;
      }
}

void solve(){
  scanf("%d %d %d",&r,&c,&m);
  int e = r*c-m;
  FOR(sk,1) FOR(zx,1) FOR(zy,1) FOR(v, 55) {
    FOR(i,r) FOR(j,c) a[i][j]='*';
    int x=zx+sk;
    int y=zy;
    if(!dnu(x,y)) continue;
    bool zle=false;
    FOR(ee,e) {
      if(!dnu(x,y)) { zle=true; break; }
      a[x][y]='.';    
      x+=1;
      if(!dnu(x,y) || (x-zx>v)) { x=zx; y++; }
    }
    if((!zle) && evaluate(e)) {
      vysledok(e);
      return ;
    }
  }
  FOR(sk,1) FOR(zx,1) FOR(zy,1) FOR(v, 55) {
    FOR(i,r) FOR(j,c) a[i][j]='*';
    int x=zx;
    int y=zy+sk;
    if(!dnu(x,y)) continue;
    bool zle=false;
    FOR(ee,e) {
      if(!dnu(x,y)) { zle=true; break; }
      a[x][y]='.';    
      y+=1;
      if(!dnu(x,y) || (y-zy>v)) { y=zy; x++; }
    }
    if((!zle) && evaluate(e)) { 
      vysledok(e);
      return ;
    }
  }
  bool zle=false;
  int x=0;
  int y=0;
  int diag=0;
  
  FOR(i,r) FOR(j,c) a[i][j]='.';
  FOR(ee,m) {
    if(!dnu(x,y)) { zle=true; break; }
    a[x][y]='*';    
    x++; 
    y--;
    if(!dnu(x,y)) {
      diag++;
      if(diag>c) {
        x = diag-c;
        y = c;
      } else {
        x=0; y=diag;
      }
    }
  }
  if(!zle && evaluate(e)) {
    vysledok(e);
    return;
  }
  printf("Impossible\n");

}

int main(){
  int pvs; scanf("%d",&pvs);
  FR(ppp,1,pvs+1){
     printf("Case #%d:\n",ppp);

     solve();
  }
}


// vim: fdm=marker:commentstring=\ \"\ %s:nowrap:autoread
