#include<stdio.h>
#include<stdlib.h>

int main()
{	int t1,t,n,s[300],i,j,check,k,pos,neg;
	float sum, mean,a[300],k1;
	scanf("%d",&t1);
	for( t = 1; t <= t1; t++)
	{	scanf("%d",&n);
		sum = 0;
		for( i = 0 ; i < n; i++)
		{	scanf("%d",&s[i]);
			sum += s[i];
		}
		
		pos = 0;
		neg = 0;
		mean = sum*2.0 / n;
		printf("Case #%d:",t);
		j=0;
		k=0;
		for( i = 0 ; i < n ; i++)
		{	a[i] = (mean-s[i])/sum*100;	
			if( a[i] >=0)
			pos++;
		}
		for( i = 0 ; i < n;i++)
		{	if(a[i] < 0)
			{	k1 = a[i]/pos;
				for(j = 0 ; j < n ; j++)
				{	if(a[j] >=0)
					a[j] += k1;
				}
				a[i] = -1;
			}
		}
		for( i = 0 ; i < n ; i++)
		{	if( a[i] >=0)
			printf(" %f",a[i]);
			else
			printf(" 0.000000");
		}
		printf("\n");


	}
}
