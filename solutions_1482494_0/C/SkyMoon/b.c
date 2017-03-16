#include <stdio.h>

main()
{
	unsigned int T,N;
	unsigned int i,j,k,star,cnt,pnt=0,bad=0;
	unsigned int a[1000],b[1000],mina=0,minb=0;

	scanf("%d",&T);

	for(i=1;i<=T;i++)
	{
		scanf("%d",&N);
		star=0;
		cnt=0;
		pnt=0;
		bad=0;
		for(j=0;j<N;j++)
		{
			scanf("%d %d",a+j,b+j);
		}

		while(pnt<N)
		{
			mina=minb=pnt;
			for(j=pnt+1;j<N;j++)
			{
				if(a[j]<a[mina])
				{
					mina=j;
				}else if((a[j]==a[mina]) && (b[j]>b[mina]))
				{
					mina=j;
				}
					
				if(b[j]<b[minb])
				{
					minb=j;
				}
			}
			if(b[minb]<=star)
			{
				cnt++;
				if(a[minb]==-1)
				{
					star++;
				}else
				{
					star+=2;
				}
				a[minb]=a[pnt];
				b[minb]=b[pnt];
				pnt++;
			}else if(a[mina]<=star)
			{
				cnt++;
				star++;
				a[mina]=-1;
			}else
			{
				bad=1;
				break;
			}
			if(bad==1) break;
		}

		if(bad==1)
		{
			printf("Case #%d: Too Bad\n",i);
		}else
		{
			printf("Case #%d: %d\n",i,cnt);
		}
	}
}
