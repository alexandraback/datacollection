// @author peter50216
// #includes {{{
#include <bits/stdc++.h>
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

int tbl[5][5]={
  {0,0,0,0,0},
  {0,1,2,3,4},
  {0,2,-1,4,-3},
  {0,3,-4,-1,2},
  {0,4,3,-2,-1}
};
inline int mul(int a,int b){
  int f=1;
  if(a<0){a=-a;f=-f;}
  if(b<0){b=-b;f=-f;}
  return f*tbl[a][b];
}
char in[10100];
int l;
LL x;
bool solve(){
  REP(i,l){
    if(in[i]=='1')in[i]=1;
    else in[i]=in[i]-'i'+2;
  }
  int xx=x%4;
  int r=1,t=1;
  REP(i,l)r=mul(r,in[i]);
  REP(i,xx)t=mul(t,r);
  if(t!=-1)return 0;
  int ml=-1,mr=-1;
  int tt=1;
  REP(i,l*4){
    tt=mul(tt,in[i%l]);
    if(tt==2){
      ml=i;break;
    }
  }
  tt=1;
  REP(i,l*4){
    tt=mul(in[(4*l-i-1)%l],tt);
    if(tt==4){
      mr=i;break;
    }
  }
  if(ml!=-1&&mr!=-1&&ml+1+mr+1<=l*x)return 1;
  return 0;
}
int main(){
  CASET{
    scanf("%d%I64d",&l,&x);
    RS(in);
    printf("Case #%d: %s\n",cas++,solve()?"YES":"NO");
  }
}
// vim: fdm=marker:commentstring=\ \"\ %s:nowrap:autoread

