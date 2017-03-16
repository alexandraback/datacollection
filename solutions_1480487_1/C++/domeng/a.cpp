#include <stdio.h>
#include <algorithm>
#include <map>
#include <vector>
using namespace std;
typedef pair<int,int> pii;
int main()
{
	int T;scanf("%d",&T);
	for (int kase=1;kase<=T;++kase)
	{
		fprintf(stderr,"%d\n",kase);
		int n,dt[205],sum = 0;
		scanf("%d",&n);
		for (int q=0;q<n;++q)
		{
			scanf("%d",&dt[q]);
			sum += dt[q];
		}
		printf("Case #%d: ",kase);
		for (int q=0;q<n;++q)
		{
			double lo = 0., hi = 100.;
			for (int w=0;w<30;++w)
			{
				double mid = (lo + hi) / 2.;
				double myScore = dt[q] + sum * mid / 100.;
				double needs = 0;
				for (int e=0;e<n;++e)
				{
					if (q==e) continue;
					if (dt[e]<myScore) needs += (myScore - dt[e]) /sum * 100.;
				}
				if (needs>100. - mid)   hi = mid;
				else					lo = mid;
			}
			printf("%.6lf ",(lo+hi)/2.);
		}
		printf("\n");
	}
	
	return 0;
}