#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;
int n,m;
#define maxn 1010
int point[maxn];
double po[maxn];
double ans[maxn];
int vis[maxn];
int main()
{
	int i,j,ncase,tt=0,f;
	double sum;
	freopen("A-small-attempt2.in", "r", stdin);
	freopen("A-small-attempt2.out", "w", stdout);
	scanf("%d",&ncase);
	while(ncase--)
	{
		scanf("%d",&n);
		sum=0;
		memset(vis,0,sizeof(vis));
		for(i=0;i<n;i++)
		{
			scanf("%lf",&po[i]);
			sum+=po[i];
		}
	//	for(i=0;i<n;i++)
	//		printf("%lf ",po[i]);
	//	printf("\n");
		double res=0.0;
		for(i=1;i<n;i++)
		{
			double tmp=po[i]-po[0];
			res-=tmp/sum;
		}
		ans[0]=(1-res)/n;
		for(i=1;i<n;i++)
		{
			ans[i]=ans[0]-(po[i]-po[0])/sum;
		}
		while(1)
		{
		//	memset(vis,0,sizeof(vis));
			f=0;
			for(i=0;i<n;i++)
			{
				if(ans[i]<0.0)
					vis[i]=1,f=1;
			}
			if(f)
			{
				for(i=0;i<n;i++) ans[i]=0;
				for(i=0;i<n;i++)
				{
					if(vis[i]) continue;
					else break;
				}
				int tot=1; res=0; int id=i;
				for(i++;i<n;i++)
				{
					if(vis[i]) continue;
					res-=(po[i]-po[id])/sum;
					tot++;
				}
				ans[id]=(1-res)/tot;
				for(i=id+1;i<n;i++)
				{
					if(vis[i]) ans[i]=0;
					else ans[i]=ans[id]-(po[i]-po[id])/sum;
				}
			}
			else break;
		}
		printf("Case #%d:",++tt);
		int out=0.0;
		for(i=0;i<n;i++)
		{
			if(!vis[i]) printf(" %.06lf",ans[i]*100.0);
			else printf(" %.06lf",out*100);
		}
		printf("\n");
	}
	return 0;
}
