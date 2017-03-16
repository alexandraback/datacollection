#include <cstdio>
#include <cmath>
#include <vector>
#include <algorithm>
#include <iostream>
#include <set>
#include <queue>

using namespace std;

int a[1000];
double ans[1000];

int main()
{
	freopen("A-small-attempt3.in", "r", stdin);
	freopen("a.out", "w", stdout);

	int t;
	scanf("%d", &t);

	for(int tt = 0; tt < t; tt++)
	{
		int n;
		scanf("%d", &n);
		double sum = 0;
		for(int i = 0; i < n; i++)
		{
			scanf("%d", &a[i]);
			sum += a[i];
		}

		double per = sum * 2 / n;
		int del = 0;
		double sum1 = 0;
		for(int i = 0; i < n; i++)
			if(a[i] < per)
				del ++;
			else 
				sum1 += a[i];
		double per1 = (2 * sum - sum1) / del;
		for(int i = 0; i < n; i++)
		{
			ans[i] = (per1 - a[i]) * 100 / sum;
			if(ans[i] < 0)
				ans[i] = 0;
		}
		printf("Case #%d:", tt+1);
		for(int i = 0; i < n; i++)
			printf(" %.7lf", ans[i]);
		printf("\n");
	}

	return 0;
}