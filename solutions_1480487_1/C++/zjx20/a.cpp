#include <cstdio>
#include <algorithm>

using namespace std;

double s[1000];

double judge(int j, double x, double sum, int n)
{
	double sc = s[j] + x * sum + 1e-8;
	double tt = x;
	for(int i=0;i<n;i++)
	{
		if(i == j) continue;
		if(sc - s[i] > 0)
			tt += (sc - s[i]) / sum;
	}
	return tt >= 1.0;
}

int main()
{
	freopen("A-large.in", "r", stdin);
	freopen("out.txt", "w", stdout);

	int t,ca=0;

	scanf("%d",&t);
	while(t--)
	{
		printf("Case #%d: ",++ca);
		int n,i;
		scanf("%d",&n);
		for(i=0;i<n;i++)
			scanf("%lf",&s[i]);

		double x = 0;
		for(i=0;i<n;i++) x += s[i];

		for(int j=0;j<n;j++)
		{
			double left = 0, right = 1, mid = (left+right)/2.0;
			while(right - left > 1e-15)
			{
				if(judge(j, mid, x, n)) right = mid;
				else left = mid;
				mid = (left+right)/2.0;
			}

			printf("%.6lf", right * 100);
			if(j<n-1) printf(" ");
			else printf("\n");
		}
	}
	return 0;
}