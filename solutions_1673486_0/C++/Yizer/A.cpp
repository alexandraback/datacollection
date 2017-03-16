#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
using namespace std;

double a[10000];
double sum[10000];
int main()
{
	int nCase;
	scanf("%d",&nCase);
	for (int nc = 0 ; nc < nCase ; nc++)
	{
		int n , K;
		scanf("%d%d",&n,&K);
		sum[0] = 1;
		for (int i=1;i<=n;i++)
			scanf("%lf",a+i),sum[i] = sum[i-1]*a[i];
			
		double ans = 0;
		ans = sum[n]*(K-n+1) + (1.0-sum[n])*(K-n+1+K+1);
		if (2+K < ans)
			ans = 2+K;
		
		for (int i=1;i<=n;i++)
		{
			double tmp = sum[n-i]*(i+K-n+i+1) + (1.0-sum[n-i])*(i+K-n+i+1+K+1);
			if (tmp < ans)
				ans = tmp;
		}
		printf("Case #%d: %.6lf\n",nc+1,ans);
	}
	return	0;
}
