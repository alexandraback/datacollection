// @author peter50216
// #includes {{{
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<functional>
#include<math.h>
#include<assert.h>
#include<stdarg.h>
#include<time.h>
#include<limits.h>
#include<ctype.h>
#include<string>
#include<map>
#include<set>
#include<queue>
#include<algorithm>
#include<vector>
#include<iostream>
#include<sstream>
using namespace std;
// }}}
// #defines {{{
#define FOR(i,c) for(__typeof((c).begin()) i=(c).begin();i!=(c).end();i++)
#define SZ(x) ((int)(x).size())
#define ALL(x) (x).begin(),(x).end()
#define REP(i,n) for(int i=0;i<(n);i++)
#define REP1(i,a,b) for(int i=(a);i<=(b);i++)
#define REPL(i,x) for(int i=0;x[i];i++)
#define PER(i,n) for(int i=(n)-1;i>=0;i--)
#define PER1(i,a,b) for(int i=(a);i>=(b);i--)
#define RI(x) scanf("%d",&x)
#define DRI(x) int x;RI(x)
#define RII(x,y) scanf("%d%d",&x,&y)
#define DRII(x,y) int x,y;RII(x,y)
#define RIII(x,y,z) scanf("%d%d%d",&x,&y,&z)
#define DRIII(x,y,z) int x,y,z;RIII(x,y,z)
#define RS(x) scanf("%s",x)
#define PI(x) printf("%d\n",x)
#define PIS(x) printf("%d ",x)
#define CASET int ___T,cas=1;scanf("%d ",&___T);while(___T--)
#define CASEN0(n) int cas=1;while(scanf("%d",&n)!=EOF&&n)
#define CASEN(n) int cas=1;while(scanf("%d",&n)!=EOF)
#define MP make_pair
#define PB push_back
#define MS0(x) memset(x,0,sizeof(x))
#define MS1(x) memset(x,-1,sizeof(x))
#define SEP(x) ((x)?'\n':' ')
#define F first
#define S second
#ifdef ONLINE_JUDGE
#define FILEIO(x) freopen(#x ".in","r",stdin);freopen(#x ".out","w",stdout);
#define FILEIOS freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
#else
#define FILEIO(x) ;
#define FILEIOS ;
#endif
typedef pair<int,int> PII;
typedef long long LL;
typedef unsigned long long ULL;
// }}}
int n,m,k;
char out[55][55];
inline void emp(){
  REP(i,n)REP(j,m)out[i][j]='.';
  out[n-1][m-1]='c';
}
inline bool solve(){
  // n<=m
  if(k==n*m-1){
    REP(i,n)REP(j,m)out[i][j]=(i==0&&j==0?'c':'*');
    return 1;
  }else if(k==0){
    emp();
    return 1;
  }else if(n==1){
    REP(i,n)REP(j,m)out[i][j]=(j<k?'*':'.');
    out[0][m-1]='c';
    return 1;
  }else if(n==2){
    if(k%2)return 0;
    if(k==n*m-2)return 0;
    REP(i,n)REP(j,m)out[i][j]=(j<k/2?'*':'.');
    out[0][m-1]='c';
    return 1;
  }else{
    int l=n*m-k;
    REP(i,n)REP(j,m)out[i][j]='*';
    if(l==2||l==3||l==5||l==7)return 0;
    if(l%2==0){
      REP(i,n)REP(j,m)out[i][j]='*';
      REP(i,2)REP(j,2)out[i][j]='.';
      out[0][0]='c';
      l-=4;
      int p1=0,p2=2;
      while(l>0){
        if(p1==n-1){
          out[p1][p2]=out[p1][p2+1]='.';
          p2+=2;
        }else{
          if(p2==0)out[p1][p2]=out[p1][p2+1]='.';
          else if(p2==1)out[p1+1][p2-1]=out[p1+1][p2]='.';
          else out[p1][p2]=out[p1+1][p2]='.';
          p2++;
          if(p2==m){
            p2=0;p1+=2;
          }
        }
        l-=2;
      }
    }else{
      REP(i,n)REP(j,m)out[i][j]='*';
      REP(i,3)REP(j,3)out[i][j]='.';
      out[0][0]='c';
      l-=9;
      int p1=0,p2=3;
      while(l>0){
        if(p1==0){
          out[p1][p2]=out[p1+1][p2]='.';
          p2++;
          if(p2==m){
            p2=3;p1=2;
            if(m==4){
              p1=3;p2=0;
            }
          }
        }else{
          if(p2==m-2&&out[p1-1][p2+1]=='*'){
            out[p1][p2]=out[p1-1][p2+1]='.';
          }else if(p2==m-1&&out[p1-1][p2]=='*'){
            out[p1-1][p2]=out[p1][p2]='.';
          }else{
            out[p1][p2]=out[p1][p2+1]='.';
          }
          p2+=2;
          if(p2>=m||(p2==m-1&&out[p1-1][p2]=='.')){
            p1++;
            p2=0;
          }
        }
        l-=2;
      }
    }
    return 1;
  }
}
int main(){
  CASET{
    RIII(n,m,k);
    printf("Case #%d:\n",cas++);
    //printf("(%d,%d,%d)\n",n,m,k);
    bool f=0;
    if(n>m){
      f=1;swap(n,m);
    }
    if(!solve())puts("Impossible");
    else{
      int c1=0,c2=0,c3=0;
      REP(i,n)REP(j,m){
        if(out[i][j]=='.')c1++;
        else if(out[i][j]=='*')c2++;
        else if(out[i][j]=='c')c3++;
        else puts("QQ");
      }
      if(c3!=1||c2!=k)puts("QQ");
      if(f){
        REP(i,m){
          REP(j,n)printf("%c",out[j][i]);
          puts("");
        }
      }else{
        REP(i,n){
          REP(j,m)printf("%c",out[i][j]);
          puts("");
        }
      }
    }
  }
}
// vim: fdm=marker:commentstring=\ \"\ %s:nowrap:autoread

