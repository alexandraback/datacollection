#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <iostream>
#include <algorithm>
using namespace std;

int t, n;
double a[2000], b[2000];
int ans1, ans2;

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	scanf("%d", &t);
	for (int w = 1; w <= t; w++)
	{
		ans1 = ans2 = 0;
		printf("Case #%d: ", w);
		scanf("%d", &n);
		for (int i = 0; i < n; i++)
			scanf("%lf", &b[i]);
		for (int i = 0; i < n; i++)
			scanf("%lf", &a[i]);
		sort(a, a + n);
		sort(b, b + n);
/*
		printf("%d\n", n);
		for (int i = 0; i < n; i++)
			printf("%.6lf ", a[i]);
		printf("\n");
		for (int i = 0; i < n; i++)
			printf("%.6lf ", b[i]);
		printf("\n");
		*/
		int it = 0;
		for (int i = 0; i < n; i++)
		{
			while (it < n && a[it] < b[i])
				it++;
			if (it == n)
				ans2 = n - i;
			it++;
		}
		
		for (ans1 = n; ans1 >= 0; ans1--)
		{
			bool good = true;
			for (int i = 0; i < ans1; i++)
				good &= b[i + (n - ans1)] > a[i];
			if (good)
				break;
		}
			
		printf("%d %d\n", ans1, ans2);
	}

	return 0;
}