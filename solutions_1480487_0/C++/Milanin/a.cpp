#include <stdio.h>
#include <algorithm>
#include <set>
#include <map>
#include <vector>
#include <string>
#include <queue>
#include <math.h>
#define N 200
using namespace std;
int a[N];
int main()
{
	int t, n, ts, i, s, j, k;
	double v, l, c, r;
	for(scanf("%d", &ts), t=1; t<=ts; t++)
	{
		for(scanf("%d", &n), s=0, i=0; i<n; scanf("%d", &a[i]), s+=a[i], i++);
		printf("Case #%d:", t);
		for(i=0; i<n; i++)
		{
			for(l=0, r=1, j=0; j<100; j++)
			{
				c=(l+r)/2;
				for(v=c, k=0; k<n; k++)
					if(k!=i && a[i]+s*c>a[k]) v+=(a[i]+s*c-a[k])/s;
				if(v>1) r=c;
				else l=c;
			}
			printf(" %.13lf", r*100);
		}
		printf("\n");
	}
	return 0;
}