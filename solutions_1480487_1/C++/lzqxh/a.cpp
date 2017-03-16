//By Lin
#include<cstdio>
#include<cstring>
#include<cmath>
#define eps 1e-9
using namespace std; 

int		n; 
double	s[205],sum; 
double	pan(double x , int i ) 
{
	double y = 1-x, z = s[i]+x*sum;
	for (int k = 0; k<n; k++ ) 
	{
		if ( k == i ) continue; 
		if ( s[k] > z ) continue; 
		else 
			y -= (z-s[k])/sum; 
	}
	return y>0; 
}

int		main()
{
	int cas, tt = 0; 
	scanf("%d", &cas );
	while ( cas -- )
	{
		scanf("%d" , &n );
		sum = 0; 
		for (int i = 0; i<n; i++) {
			scanf("%lf" , &s[i] );
			sum += s[i]; 
		}
		printf("Case #%d:", ++ tt );
		for (int i = 0; i<n; i++) 
		{
			double g  = 0 , h = 1.0; 
			while ( h-g > eps ) 
			{
				double mid = (g+h)/2;
				if ( pan(mid,i) ) g = mid; 
				else h = mid; 
			}
			printf(" %.6f" , g*100);
		}
		printf("\n");
	}
	return 0; 
}
