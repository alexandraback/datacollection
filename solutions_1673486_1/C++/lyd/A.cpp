#include <stdio.h>

const int mx=100010;

int n,m;
double p[mx];
double dp[mx];

int main()
{
	int i;
	int t,ca=0;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&m,&n);
		p[0]=1.0;
		for(i=1;i<=m;i++)
			scanf("%lf",&p[i]);
		double ac = 1.0;
		double ans = m + n + 1;
		if( ans > 1 + n + 1)
		{
			ans = 1 + n + 1;
		}
		//printf("%d %f\n",i,ans);
		for(i=0;i<=m;i++)
		{
			ac *= p[i];
			if(ans > m - i + ac * (n-i+1) + (1.0-ac)*(n-i+1+n+1))
				ans = m - i + ac * (n-i+1) + (1.0-ac)*(n-i+1+n+1);
			//printf("%d %f\n",i,m - i + ac * (n-i+1) + (1.0-ac)*(n-i+1+n+1));
		}
		printf("Case #%d: %.6f\n",++ca,ans);
	}

	return 0;
}

