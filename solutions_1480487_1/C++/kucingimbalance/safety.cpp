#include<cstdio>
#include<iostream>
#include<algorithm>

using namespace std;

#define MAXN 200

int t, tc, n, i, nn;
double a[MAXN+5], sum, k, ssum;

double dmax(double a, double b)
{
	if (a < b) return b;
	return a;
}

int main()
{
	freopen("a.in","r",stdin); freopen("a.out","w",stdout);
	scanf("%d", &tc);
	for (t = 1; t <= tc; t++)
	{
		scanf("%d", &n);
		for (i = 0; i < n; i++) scanf("%lf", &a[i]);
		
		sum = 0; ssum = 0; nn = n;
		for (i = 0; i < n; i++) sum = sum + a[i];
		
		k = sum * 2 / n;
		for (i = 0; i < n; i++) 
			if (a[i] >= k)
			{
				--nn;
				ssum += a[i] - k;
			}
		k = k-ssum/nn;
		//printf("%lf\n", k);
		
		printf("Case #%d:", t);
		for (i = 0; i < n; i++) 
			if (a[i] >= k) printf(" 0.000000"); 
				else printf(" %lf", 100*(k-a[i])/sum);
		puts("");
	}
}