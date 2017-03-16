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
#define RS(X) scanf("%s",X)
#define GCH getchar()
#define PCH(X) putchar(X)
#define MAX(A,B) (((A)>(B))?(A):(B))
#define MIN(A,B) (((A)<(B))?(A):(B))
#define MS(X,Y) memset(X,Y,sizeof(X))
#define MC(X,Y,var,len) memcpy((X),(Y),sizeof(var)*(len))
#define debug(...) fprintf(stderr,__VA_ARGS__)
using namespace std;
const int MAXN=1005; 
int pre[MAXN]={0};
int f[MAXN]={0};
int s;
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
void init()
{
  RI(s);
  MS(f,0);
  REP(i,0,s)
    scanf("%1d",&pre[i]);
  REP(i,1,s)
    pre[i]+=pre[i-1];
  REP(i,1,s)
    if (i>pre[i-1]+f[i-1])
	  f[i]=i-pre[i-1];
	else 
	  f[i]=f[i-1];
  printf("%d\n",f[s]);
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
  }
  close();
  return 0;
}
