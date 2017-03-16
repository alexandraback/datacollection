#include<cstdio>
#include<cstring>
#include<algorithm>
#define fo(i,a,b) for(int i=a;i<=b;i++)
#define fd(i,a,b) for(int i=a;i>=b;i--)
using namespace std;
const int N=3000;
int d[N],tow[N],co[N],t[N],ans,st[N],en[N],next[N],edge;
void insert(int x,int y)
{
	next[++edge]=st[x];
	st[x]=edge;
	en[edge]=y;
}
int dfs(int now)
{
	int re=0;
	t[now]=1;
	for(int i=st[now];i;i=next[i])
	if (t[en[i]]==0) 
	re=max(re,dfs(en[i]));
	return re+1;
}
int main()
{
	freopen("c.in","r",stdin);
	freopen("c.out","w",stdout);
	int T;
	scanf("%d",&T);
	fo(cas,1,T)
	{
		int n;
		scanf("%d",&n);
		memset(st,0,sizeof st);
		memset(co,0,sizeof co);
		edge=0;
		fo(i,1,n) scanf("%d",&tow[i]),insert(tow[i],i);
		ans=0;
		fo(i,1,n)
		if (co[i]==0)
		{
			int top=1;
			d[1]=i;
			memset(t,0,sizeof t);
			fo(j,1,top)
			{
				int now=d[j];
				t[now]=1;
				if (t[tow[now]]) break; else d[++top]=tow[now];
			}
			if (tow[d[top]]!=i) continue; else
			if (top<=2) 
			{
				ans=max(ans,2);
				continue;
			} else
			{
				ans=max(ans,top);
				fo(j,1,top) co[d[j]]=1;
			}
		}
		int sum=0;
		memset(t,0,sizeof t);
		fo(i,1,n)
		if (tow[tow[i]]==i && t[i]==0)
		{
			t[i]=t[tow[i]]=1;
			sum+=dfs(i)+dfs(tow[i]);
		}
		ans=max(sum,ans);
		printf("Case #%d: ",cas);
		printf("%d\n",ans);
	}	
}
