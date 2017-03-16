#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#define PAUSE system("pause")
main()
{
//	freopen("A_large.in","r",stdin);
//	freopen("A_large_out.txt","w",stdout);
	int Test,Case,i,j,k;
	unsigned long long r,t;
	double a;
	scanf("%d",&Test);
	for(Case=1;Case<=Test;Case++)
	{
		scanf("%I64u %I64u",&r,&t);
		a = (8*t + 1)/(double)r/r - 4/(double)r +4;
		a = sqrt(a);
		a = ((8*t + 1)/(double)r -4) / (a+2);
		printf("Case #%d: %I64d\n",Case,(long long)((a+1)/4));
	}
}
