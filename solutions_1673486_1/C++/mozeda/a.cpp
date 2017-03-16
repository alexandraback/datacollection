#include <cstdio>

int main()
{
	int N;
	scanf("%d",&N);
	for (int I = 1; I<= N;++I)
	{
		int n,m;
		scanf("%d%d",&n, &m);
		double a[n+2];
		for (int i=0;i<n;++i)
			scanf("%lf", &a[i]);
		double e = m+2, tmp=1;
		for (int i=0;i<n;++i)
		{
			tmp=tmp*a[i];
//			printf("%d %d %.2lf\n", n-i-1+m-i, i, (n-i-1+m-i)+(1-tmp)*(m+1));
			e<?=(n-i-1+m-i)+(1-tmp)*(m+1);
			
		}
		printf("Case #%d: %.6lf\n", I, e);
	}
} 
