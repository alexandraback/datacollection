#include <stdio.h>
#include <string.h>
int main()
{
	freopen("B-small-attempt0.in","r",stdin);
	freopen("B.out","w",stdout);
	int time,n,s,p,t,cnt;
	int td,tm;
	scanf("%d",&time);
	for(int k=1;k<=time;++k)
	{
		cnt=0;
		scanf("%d%d%d",&n,&s,&p);
		for(int i=0;i<n;++i)
		{
			scanf("%d",&t);
			td=t/3;tm=t%3;
			if(td>=p)++cnt;
	//		else if(td<p-2)continue;
	//		else if(td==p-2&&tm==1)continue;//can't form
			else if(td==p-2&&tm==2)
			{
				if(s)--s,++cnt;
			}
			else if(td==p-1&&tm!=0)++cnt;
			else if(td==p-1&&tm==0)
			{
				if(s&&td>0)--s,++cnt;
			}
		}
		printf("Case #%d: %d\n",k,cnt);
	}
	return 0;
}
