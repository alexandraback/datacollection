#include <stdio.h>
#include <algorithm>
using namespace std;
#define K 2100
double p[K][K];
int main()
{
	int n, x, y, i, j, k, t, ts, a;
	double r;
	for(scanf("%d", &ts), t=1; t<=ts; t++)
	{
		printf("Case #%d: ", t);
		scanf("%d%d%d", &n, &x, &y);
		for(a=0, k=1; k<=n; n-=k, a+=2, k+=4);
		if(x+y>a || y-x>a) r=0;
		else if(x+y<a && y-x<a) r=1;
		else if(x==0) r=0;
		else
		{
			k=(k-1)/2;
			for(i=0; i<=n; i++)
				for(j=0; j<=n; p[i][j]=0, j++);
			for(p[0][0]=1, i=0; i<n; i++)
				for(j=0; j<=i && j<=k; j++)
					if(j==k) p[i+1][j]+=p[i][j];
					else { p[i+1][j]+=p[i][j]/2; p[i+1][j+1]+=p[i][j]/2; }
			for(r=0, j=y+1; j<=k && j<=n; r+=p[n][j], j++);
		}
		printf("%.13lf\n", r);
	}
	return 0;
}
