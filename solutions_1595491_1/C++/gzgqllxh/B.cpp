#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
int main()
{
	int i,tcase,casenum=0,N,S,P,T,ans,x;
	freopen("B.in","r",stdin);
	freopen("B.out","w",stdout);
	scanf("%d",&tcase);
	while(tcase--)
	{
		ans=0;
		scanf("%d%d%d",&N,&S,&P);
		for(i=0;i<N;i++)
		{
			scanf("%d",&T);
			x=(int)T/3;
			if(x>=P)
			{
				ans++;
				continue;
			}
			if(T%3==0&&S&&x&&x+1>=P)
			{
				ans++;
				S--;
				continue;
			}
			if(T%3==1&&x+1>=P)
			{
				ans++;
				continue;
			}
			if(T%3==2)
			{
				if(x+1>=P)
				{
					ans++;
				}
				else
				{
					if(S&&x+2>=P)
					{
						S--;
						ans++;
					}
				}
				continue;
			}
		}
		printf("Case #%d: %d\n",++casenum,ans);
	}
	return 0;
}
