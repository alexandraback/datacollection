#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <iostream>
#include <algorithm>
using namespace std;

const int N = 1000;

int a[N], b[N], n;
int one[N * 2], two[N], onen, twon;
bool legal()
{
	int i, j, p = 0;
	sort(one, one + onen);
	sort(two, two + twon);
	i = 0;
	j = 0;
	while (i < onen || j < twon)
	{
		if (i < onen && one[i] <= p)
		{
			i++;
			p++;
		}
		else if (j < twon && two[j] <= p)
		{
			j++;
			p += 2;
		}
		else
			return false;
	}
	return true;
}
int main(void)
{
	int T, c, i;
	unsigned j;
	int ans;
	freopen("B.in", "r", stdin);
	freopen("B.out", "w", stdout);
	scanf("%d", &T);
	for (c = 1; c <= T; c++)
	{
		scanf("%d", &n);
		for (i = 0; i < n; i++)
			scanf("%d%d", &a[i], &b[i]);/*
		for (i = 0; i < n; i++)
		{
			one[i] = a[i];
			one[i + n] = b[i];
		}
		sort(one, one + n + n);
		for (i = 0; i < n + n; i++)
			if (one[i] > i)
				break;
		if (i < n + n)
		{
			printf("Case #%d: Too Bad\n", c);
			continue;
		}*/
		ans = n + n + 1;
		for (j = 0; j < (1 << n); j++)
		{
			onen = 0;
			twon = 0;
			for (i = 0; i < n; i++)
			{
				if (j & (1 << i))
				{
					one[onen++] = a[i];
					one[onen++] = b[i];
				}
				else
				{
					two[twon++] = b[i];
				}
			}
			//if (legal()) printf("j = %d, legal = %d\n", j, legal());
			if (legal() && ans > onen + twon)
				ans = onen + twon;
		}
		if (ans <= n + n)
			printf("Case #%d: %d\n", c, ans);
		else
			printf("Case #%d: Too Bad\n", c);
	}
	return 0;
}
