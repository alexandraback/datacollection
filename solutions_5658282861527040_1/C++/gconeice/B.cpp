#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cstring>

using namespace std;

int T;
int a,b,k;
const int N=30;
int x[N],y[N],z[N];
int num;
long long ans;

void dfs(int now,int aa,int bb)
{
  if (now==-1) return;
  for (int i=0;i<=max(aa,x[now]);i++)
    for (int j=0;j<=max(bb,y[now]);j++)
      {
	if ((i&j)<z[now])
	  {
	    long long l=a%(1<<now),r=b%(1<<now);
	    if (aa) l=(1<<now);
	    if (bb) r=(1<<now);
	    if (i<x[now]) l=(1<<now);
	    if (j<y[now]) r=(1<<now);
	    ans+=l*r;
	    continue;
	  }
	if ((i&j)>z[now]) continue;
	int na,nb;
	na=i^x[now]; nb=j^y[now];
	dfs(now-1,aa|na,bb|nb);
      }
}

int main()
{
  freopen("B.in","r",stdin);
  freopen("B.out","w",stdout);
  scanf("%d",&T);
  for (int ii=1;ii<=T;ii++)
    {
      scanf("%d%d%d",&a,&b,&k);
      int aa=a,bb=b,kk=k;
      memset(x,0,sizeof(x));
      memset(y,0,sizeof(y));
      memset(z,0,sizeof(z));
      num=0; ans=0;
      int tmp=-1;
      while (a)
	{
	  x[++tmp]=a%2;
	  a/=2;
	}
      num=max(tmp,num);
      tmp=-1;
      while (b)
	{
	  y[++tmp]=b%2;
	  b/=2;
	}
      num=max(tmp,num);
      tmp=-1;
      while (k)
	{
	  z[++tmp]=k%2;
	  k/=2;
	}
      num=max(num,tmp);
      a=aa,b=bb,k=kk;
      dfs(num,0,0);
      printf("Case #%d: %lld\n",ii,ans);
    }
  return 0;
}
