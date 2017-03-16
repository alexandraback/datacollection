#include <stdio.h>

main()
{
	int T,A,B;
	int i,j,k;
	double I[1000000],minnum,typenum,rate;

	scanf("%d",&T);

	for(i=1;i<=T;i++)
	{
		scanf("%d %d",&A,&B);
		rate=1;
		minnum=B+2;
		for(j=1;j<=A;j++)
		{
			scanf("%lf",I+j-1);

			rate*=I[j-1];
			typenum=rate*((A-j)+B-j+1)+(1-rate)*((A-j)+B-j+1+B+1);
			if(typenum<minnum)
			{
				minnum=typenum;
			}
		}
		printf("Case #%d: %lf\n",i,minnum);
	}
}







