#include<stdio.h>
#include<iostream>
#include<string.h>
#include<algorithm>
#include<math.h>
using namespace std;

double ti[2002] ; 
double xi[2002] ;
double aa[2002] ; 

int main()
{
	int t ;
	int n , m ; 
	double D ;
	int i ; 
	int total = 1 ; 
	double ourTime ; 
	double otherTime ; 
	double vel ; 
	scanf("%d",&t);

	while(t--)
	{
		scanf("%lf%d%d",&D,&n,&m);
		for(i= 0 ; i < n ; i++)
		{
			scanf("%lf%lf",&ti[i],&xi[i]);
		}

		for(i = 0 ; i < m ; i++)
		{
			scanf("%lf",&aa[i]);
		}
		
		printf("Case #%d:\n",total++);

		if(n == 1)
		{
			for(i = 0 ; i < m ; i++)
			{
				ourTime = sqrt((2*D)/aa[i]);
				printf("%lf\n",ourTime);
			}
			continue ; 
		}


		for(i = 0 ; i < m ; i++)
		{
			ourTime = sqrt((2*D)/aa[i]);
			if(xi[0] > D)
				printf("%lf\n",ourTime);
			else
			{
				vel = (xi[1] - xi[0])/(ti[1] - ti[0]);
				otherTime = (D - xi[0])/vel ;
				if(ourTime < otherTime)
					printf("%lf\n",otherTime);
				else
					printf("%lf\n",ourTime);
			}
		}
	}
	return 0;
}
