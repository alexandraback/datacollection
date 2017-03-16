#include <stdio.h>
#include <stdlib.h>
#include <string.h>

double p[110000] ;
double dpt[110000][2] ;
	
int main(void)
{
	int t ;
	int A, B, i ;
	double best ;
	
	scanf("%d",&t) ;
	
	int tc ;
	
	for(tc=1;tc<=t;tc++)
	{
		scanf("%d%d",&A,&B) ;
		dpt[0][0] = 1 ;
		best = 2+B ;
		for(i=1;i<=A;i++)
		{
			scanf("%lf",&p[i]) ;
			dpt[i][0] = dpt[i-1][0]*p[i] ;
			dpt[i][1] = dpt[i-1][0]*(1-p[i]) ;
		}
		double cur ;
		for(i=0;i<=A;i++)
		{
			cur = i+(B-A+i)+1+(1-dpt[A-i][0])*(B+1) ;
			if(cur<best) best = cur ;
		}
		printf("Case #%d: %.06lf\n",tc,best) ;
	}
	
	return 0 ;
}
