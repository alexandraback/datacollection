#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#define PAUSE system("pause")
main()
{
//	freopen("A_small.in","r",stdin);
//	freopen("A_small_out.txt","w",stdout);
	int Test,Case,i,j,k;
	long long r,t;
	double a;
	scanf("%d",&Test);
	for(Case=1;Case<=Test;Case++)
	{
		scanf("%I64d %I64d",&r,&t);
/*		a = 9*(double)t/r/r - 4/(double)r +4;
		a = sqrt(a);
		a = (9*(double)t/r -4) / (a+2);
		printf("Case #%d: %I64d\n",Case,(long long)((a+1)/4));*/
		
		for(i=0;t>=0;i++)
			t-=(r+r+1+4*i);
		printf("Case #%d: %d\n",Case,i-1);
	}
}
