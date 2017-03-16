#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>

int main()
{
	int i, j, k;
	int t;
	double d;
	double tt[3000], x[3000], aa;
	int n, a;
	
	double fastest, other, time, temp, v;
	int lastpos;
	
	scanf("%d", &t);
	for(i = 0; i < t; ++i)
	{
		printf("Case #%d:\n", i+1);	
		scanf("%lf %d %d", &d, &n, &a);
		for(j = 0; j < n; ++j)
		{
			scanf("%lf %lf", &tt[j], &x[j]);
		}
		for(j = 0; j < a; ++j)
		{
			scanf("%lf", &aa);
			//printf("%lf %lf\n", d, aa);
			fastest = sqrt(2*d/aa);
			lastpos = 0;
			time = 0.0;
			v = 0.0;
			for(k = 0; k < n-1; ++k)
			{
				
				
				if(x[k+1] == d)
				{
					other = tt[k+1];
				}
				else if(x[k] < d && x[k+1] > d)
				{
					other = d/(x[k] + x[k+1])*(tt[k] + tt[k+1]);
					break;
				}
				
				temp = 0.5*aa*(tt[k+1]-tt[lastpos])*(tt[k+1]-tt[lastpos]);
				if(temp > x[k+1]-x[lastpos])
				{
					time += tt[k+1]-tt[lastpos];
					//printf("  %lf\n", time);
					lastpos = k+1;
				}
				
			}
			time += sqrt(2*(d-x[lastpos])/aa);
			//printf("%lf\n", time);
			
			if(other > fastest && other > time)
			{	
				printf("%lf\n", other);
			}
			else if(time> fastest)
			{
				printf("%lf\n", time);
			}
			else
			{
				printf("%lf\n", fastest);
			}
		}
		
		
		
	}
	
	return 0;
}