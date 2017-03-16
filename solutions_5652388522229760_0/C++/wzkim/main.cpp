#include <bits/stdc++.h>

using namespace std;

int cnt;
bool vis[10];

void countNum(long long x)
{
	while(x)
	{
		if(vis[x%10]==0)
		{
			vis[x%10]=1;
			cnt++;
		}
		x/=10;
	}
}
int main()
{
	freopen("A-small-attempt0.in","r",stdin);
	freopen("A-small-attempt0.out","w",stdout);

	int cases;

	while(scanf("%d",&cases)!=EOF)
	{
		for(int t=1;t<=cases;t++)
		{
			int n;
			scanf("%d",&n);
			if(n==0)
			{
				printf("Case #%d: INSOMNIA\n",t);
				continue;
			}
			long long base=n;
			cnt=0;
			memset(vis,0,sizeof(vis));
			while(cnt!=10)
			{
				countNum(base);
				if(cnt==10)
				{
					printf("Case #%d: %lld\n",t,base);
					break;
				}
				base+=n;
			}

		}
	}
	return 0;
}
