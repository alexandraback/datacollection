#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cstring>

using namespace std;

int T;
int n,m;
const int N=55;
struct Point
{
  int next;
  void init() {next=-1;}
}P[N];
struct Edge
{
  int to,next;  
}E[N*N*2];
int Enum;
int a[N];
int ans[N],b[N];
bool check[N],c[N];

void Ins(int from,int to)
{
  Enum++;
  E[Enum].to=to; E[Enum].next=P[from].next; P[from].next=Enum;
}

void Solve()
{
  memset(check,0,sizeof(check));
  int now=b[1];
  int pre[10];
  memset(pre,0,sizeof(pre));
  for (int i=2;i<=n;i++)
    {
      bool bj=0;
      for (int p=P[now].next;p!=-1;p=E[p].next)
	{
	  if (E[p].to==b[i])
	    {
	      bj=1;
	      pre[b[i]]=now;
	      now=b[i];
	      break;
	    }
	}
      if (bj) continue;
      i--;
      now=pre[now];
      if (now==0) return;
    }
  for (int i=1;i<=n;i++)
    {
      if (ans[i]<a[b[i]]) return;
      if (ans[i]>a[b[i]]) break;
    }
  for (int i=1;i<=n;i++) ans[i]=a[b[i]];
}

void dfs(int now)
{
  if (now==n+1)
    {
      Solve();
      return;
    }
  for (int i=1;i<=n;i++)
    {
      if (c[i]) continue;
      c[i]=1;
      b[now]=i;
      dfs(now+1);
      c[i]=0;
    }
}

int main()
{
  freopen("C.in","r",stdin);
  freopen("C.out","w",stdout);
  scanf("%d",&T);
  for (int ii=1;ii<=T;ii++)
    {
      Enum=-1;
      scanf("%d%d",&n,&m);
      for (int i=1;i<=n;i++) P[i].init();
      for (int i=1;i<=n;i++) scanf("%d",&a[i]);
      for (int i=1;i<=m;i++)
	{
	  int from,to;
	  scanf("%d%d",&from,&to);
	  Ins(from,to); Ins(to,from);
	}
      for (int i=1;i<=n;i++) ans[i]=100000;
      dfs(1);
      printf("Case #%d: ",ii);
      for (int i=1;i<=n;i++) printf("%d",ans[i]);
      printf("\n");
    }
  return 0;
}
