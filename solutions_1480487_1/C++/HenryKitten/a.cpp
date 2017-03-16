#include <cstdio>
#include <cstdlib>
#include <cmath>

int main()
{
	int ncas;
	scanf("%d",&ncas);
	for(int t=1;t<=ncas;t++)
	{
		int n;
		double a[201];
		double sum = 0;
		scanf("%d", &n);
		for(int i=0;i<n;i++)
		{
			scanf("%lf",&a[i]);
			sum += a[i];
		}
		printf("Case #%d:",t);
		for(int i=0;i<n;i++)
		{
			double lb = 0, ub = 1;
			double mid;
			while(fabs(lb - ub) >= 1e-9)
			{
				mid = (lb + ub) / 2;
				//printf("mid:%lf\n",mid);
				double remain = 1 - mid;
			       	double target = a[i] + sum*mid;
				double diff;
				for(int j=0;j<n;j++)
				{
					if(i == j) continue;
					if(a[j] >= target) continue;
					diff = target - a[j];
					remain -= diff / sum;
				}
				//printf("re:%lf %lf %lf\n",diff,sum,remain);
				if(remain < 0) ub = mid;
				else lb = mid;
			}
			printf(" %.6lf",ub*100);
		}
		putchar(10);
	}
	return 0;
}
