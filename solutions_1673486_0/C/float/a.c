#include <stdio.h>
#include <stdlib.h>

int main()
{
	int T, i, j, A, B;
	double ans, p[100010], tmpp;
	scanf("%d", &T);
	for(i=1; i<=T; i++)
	{
		scanf("%d %d", &A, &B);
		p[0] = 1;
		for(j=1; j<=A; j++)
		{
			scanf("%lf", &p[j]);
			p[j] *= p[j-1];
		}
		ans = 2+B;
		tmpp = (double)(B-A+1)*p[A] + (double)(2*B-A+2)*(1-p[A]);
		if(tmpp < ans)
			ans = tmpp;
		for(j=1; j<A/2+1; j++)
		{
			tmpp = (double)(j*2+B-A+1)*p[A-j] + (double)(j*2+2*B-A+2)*(1-p[A-j]);
			if(tmpp < ans)
				ans = tmpp;
		}

		printf("Case #%d: %.6lf\n", i, ans);
	}
	return 0;
}
