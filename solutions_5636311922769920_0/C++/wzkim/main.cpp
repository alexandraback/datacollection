#include <bits/stdc++.h>

using namespace std;

int cases,k,c,s;

int main()
{
	freopen("D-small-attempt1.in","r",stdin);
	freopen("out","w",stdout);
	while(scanf("%d",&cases)!=EOF)
	{
		for(int t=1;t<=cases;t++)
		{
			scanf("%d%d%d",&k,&c,&s);
			if(s*c<k)
			{
				printf("Case #%d: IMPOSSIBLE\n",t);
				continue;
			}
			else
			{
				printf("Case #%d:",t);
				int cnt=0;
				while(cnt<k)
				{
					long long x=0;
					for(int i=1;i<=c;i++)
					{
						x*=k;
						if(cnt<k)
							cnt++;
						if(i<c)
							x+=(cnt-1);
						else
							x+=cnt;
					}
					printf(" %lld",x);
				}
				puts("");
			}
		}
	}
	return 0;
}
