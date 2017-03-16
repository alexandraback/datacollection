#include <stdio.h>

main()
{
	int T,N,S,p,p1,p2;
	int t;
	int i,j,key1,key2,cnt;

	scanf("%d",&T);

	for(i=1;i<=T;i++)
	{
		cnt=0;
		scanf("%d %d %d",&N,&S,&p);
		for(j=0;j<N;j++)
		{
			p1=(p-1)>0?p-1:0;
			p2=(p-2)>0?p-2:0;
			key1=p+2*p1;
			key2=p+2*p2;

			scanf("%d",&t);
			if(t>=key1)
			{
				cnt++;
			}else if(t>=key2)
			{
				if(S>0)
				{
					S--;
					cnt++;
				}
			}
		}
		printf("Case #%d: %d\n",i,cnt);
	}
}
