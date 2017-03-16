#include<stdio.h>
#include<stdlib.h>
#include<math.h>

long long r, t;

int main()
{
	int T;
	scanf("%d", &T);
	int Case = 1;
	while ( T-- ) {
		scanf("%lld%lld", &r, &t);
		double U = t;
		double L = 0;
		while ( U > L ) {
			double n = floor((U+L)/2);
			if ( (2*n-1+2*r)*n <= t ) {
				L = n+1;
			}
			else {
				U = n-1;
			}
		}
		double n;
		for ( n = L-2 ; (2*n-1+2*r)*n <= t ; n++ ) {
			
		}
		n--;
		printf("Case #%d: %.0lf\n", Case++, n);
	}
	return 0;
}
