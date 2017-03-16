#include<cstdio>
#include<algorithm>
#include<cstring>
#define fo(i,a,b) for(int i=a;i<=b;i++)
#define fd(i,a,b) for(int i=a;i>=b;i--)
using namespace std;
int main()
{
	freopen("D.in","r",stdin);freopen("D.out","w",stdout);
	int T,pp=0;
	scanf("%d",&T);
	while (T--)
	{
		pp++;
		int k,c,s;
		scanf("%d%d%d",&k,&c,&s);
		if (k>s*c)
		{
			printf("Case #%d: IMPOSSIBLE\n",pp);
			continue;
		}
		printf("Case #%d:",pp);
		long long ans=0,tmp=0;
		fo(i,1,k)
		{
			tmp++;
			if (ans==-1) ans=0;
			ans=ans*k+i-1;
			if (tmp==c)
			{
				printf(" %lld",ans+1);
				tmp=0;
				ans=-1;
			}
		}
		if (ans!=-1) printf(" %lld",ans+1);
		printf("\n");
	}
}
