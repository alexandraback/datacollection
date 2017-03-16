#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <ctime>
#include <queue>
#include <set>
#include <map>
#define REP(I,A,B) for(int I=A,END=B;I<=END;I++)
#define REPD(I,A,B) for(int I=A,END=B;I>=END;I--)
#define RI(X) scanf("%d",&X)
#define RS(X) scanf("%s",&X)
#define GCH getchar()
#define PCH(X) putchar(X)
#define MAX(A,B) (((A)>(B))?(A):(B))
#define MIN(A,B) (((A)<(B))?(A):(B))
#define MS(X,Y) memset(X,Y,sizeof(X))
#define MC(X,Y,var,len) memcpy((X),(Y),sizeof(var)*(len))
#define debug(...) fprintf(stderr,__VA_ARGS__)
using namespace std;
/*
  考虑我们一次性把盘子先分完
  那么我们假设分完后最多一个盘子中存着 k个东西。。
  然后我们可以计算每一个 盘子之前需要分成几个部分 
*/
const int MAXN=1005;
int d;
int p[MAXN]={0};
int ans;
void open()
{
  freopen("B.in","r",stdin);
  freopen("B.out","w",stdout);
}
void close()
{
  fclose(stdin);
  fclose(stdout);
}
void init()
{
  RI(d);
  p[0]=0;
  REP(i,1,d)
  {
    RI(p[i]);
    p[0]=max(p[0],p[i]);
  }
  ans=p[0];
}
void work()
{
  int tmp=0;
  REP(x,1,p[0])
  {
  	tmp=x;
    REP(i,1,d)
      tmp+=p[i]/x+(p[i]%x!=0)-1;
    if (ans>tmp)
      ans=tmp;
  }
  printf("%d\n",ans);
}
int main()
{
  open();
  int _=0;
  RI(_);
  REP(__,1,_)
  {
  	printf("Case #%d: ",__);
    init();
    work();
  }
  init();
  close();
  return 0;
}

