#include <stdio.h>

int main() {
	int t;
	scanf("%d", &t);
	for(int it=1; it<=t; it++) {
		int x, y;
		scanf("%d %d", &x, &y);
		double res1 = y+2;
		double prawd[x];
		for(int i=0; i<x; i++)
			scanf("%lf", &prawd[i]);
		double res2 = 999999999.0;
		double tmp = 1.0;
		for(int i=0; i<x; i++) {
			tmp = tmp * prawd[i];
			if( (double)(x-i+y-i-1)+(1.0-tmp)*(y+1) < res2)
				res2 = (double)(x-i+y-i-1)+(1.0-tmp)*(y+1);
		}
		if(res1<res2)
			printf("Case #%d: %lf\n", it, res1);
		else
			printf("Case #%d: %lf\n", it, res2);
	}
}
	
