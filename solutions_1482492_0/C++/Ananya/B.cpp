#include <cstdio>
#include <cmath>
using namespace std;

#define MAXN 2010
#define MAXA 260
double x[MAXN];
double t[MAXN];
double a[MAXA];

int main ()
{
	int T, N, A, i, j;
	double D;
	scanf("%d",&T);
	
	for ( int cnt = 1; cnt <= T; cnt++ )
	{
		scanf("%lf %d %d",&D,&N,&A);
		
		for ( i = 0; i < N; i++ )
		{
			scanf("%lf %lf",&t[i],&x[i]);
		}
		
		for ( i = 0; i < A; i++ )
		{
			scanf("%lf",&a[i]);
		}
		
		printf("Case #%d:\n",cnt);
		
		if ( N == 1 )
		{
			for ( i = 0; i < A; i++ )
			{
				printf("%lf\n",sqrt(2*D/a[i]));
			}
		}
		
		else
		{
			double v = (x[1]-x[0])/(t[1]-t[0]);
			double t;
			double d2;
			
			for ( i = 0; i < A; i++ )
			{
				t = (v + sqrt(v*v + 2*a[i]*x[0]))/(2*a[i]);
				
				if ( t < 0 || x[0]+v*t < D )
				{
					d2 = D - x[0]+v*t;
					printf("%lf\n",(D-x[0])/v);
				}
				
				else printf("%lf\n",sqrt(2*D/a[i]));
			}
		}
	}
}