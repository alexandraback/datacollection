#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <ctime>
#include <set>
#include <map>
#define REP(I,A,B) for (int I=A,END=B;I<=END;I++)
#define REPD(I,A,B) for (int I=A,END=B;I>=END;I--)
#define RI(X) scanf("%d",&X)
#define RS(X) scanf("%s",X)
#define RD(X) scanf("%lf",&X)
#define RLL(X) scanf("%I64d",&X)
#define GCH getchar()
#define PCH(X) putchar(X)
#define MS(X,Y) memset(X,Y,sizeof(X))
#define MC(X,Y,var,len) memcpy(X,Y,sizeof(var)*(len))
#define debug(...) fprintf(stderr,__VA_ARGS__)
using namespace std;
const int MAXN=1e6+5;
const int INF=1e6+7;
int f[MAXN]={0};
int t;
int q[105]={0};
void open()
{
  freopen("A.in","r",stdin);
  freopen("A.out","w",stdout);
}
void close()
{
  fclose(stdin);
  fclose(stdout);
}
int rev(int p)
{
  int a=0;
  while (p)
  {
    a=a*10+p%10;
    p/=10;
  };
  return a;
}
void init()
{
  RI(t);
  REP(i,1,1e6)
    f[i]=INF;
  f[1]=1;
  REP(i,1,t)
  {
    RI(q[i]);
    q[0]=max(q[0],q[i]);
  }
  int tmp;
  REP(i,1,q[0])
  {
  	tmp=rev(i);
  	if (tmp<=q[0])
  	  f[tmp]=min(f[tmp],f[i]+1);
  	if (i+1<=q[0])
  	  f[i+1]=min(f[i+1],f[i]+1);
  }
  REP(i,1,t)
    printf("Case #%d: %d\n",i,f[q[i]]);
}
int main()
{
  open();
  init();
  close();
  return 0;
}

