#include <stdio.h>

main()
{
	int i,j,T,N,X,X2,cnt;
	int m[200];
	double r[200]={0};

	scanf("%d",&T);

	for(i=1;i<=T;i++)
	{
		scanf("%d",&N);
		X=X2=0;
		cnt=N;
		for(j=0;j<N;j++)
		{
			scanf("%d",m+j);
			X+=m[j];
		}
		printf("Case #%d:",i);

		X2=X;
		for(j=0;j<N;j++)
		{
			if(m[j]>2.0*X/N)
			{
				r[j]=-1;
				X2-=m[j];
				cnt--;
			}
		}
		for(j=0;j<N;j++)
		{
			if(r[j]<0)
			{
				continue;
			}
			if(X==0)
			{
				r[j]=100.0/cnt;
			}else
			{
				r[j]=100.0*(X2+X-cnt*m[j])/(1.0*cnt*X);
			}
		}
		for(j=0;j<N;j++)
		{
			if(r[j]<0)
			{
				printf(" %lf",0.0);
			}else
			{
				printf(" %lf",r[j]);
			}
			r[j]=0;
		}
		printf("\n");
	}
}
