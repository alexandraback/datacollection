#include <iostream>
#include <cstring>
#include <cstdio>
#include <queue>
using namespace std;

int n, ans, sum, a[100];
char ch;

int main()
{
	freopen("a.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	int times;
	scanf("%d", &times);
	for (int i = 1; i <= times; ++i)
	{
		printf("Case #%d: ", i);
		scanf("%d", &n);
		ans = 0;
		for (int i = 0; i < n; ++i)
		{
			scanf("%d", a + i);
			if (ans < a[i])
				ans = a[i];
		}
		for (int i = 1; i < ans; ++i)
		{
			int sum = 0;
			for (int j = 0; j < n; ++j)
			{
				int k = a[j] / i;
				if (a[j] % i != 0)
					++k;
				sum += k - 1;
			}
			if (ans > i + sum)
				ans = i + sum;
		}
		printf("%d\n", ans);
	}
	return 0;
}