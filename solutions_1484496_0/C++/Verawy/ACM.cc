#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<algorithm>
using namespace std;

int a[50], c[2000100];

int main()
{
	int T, n, t, ans1, ans2, i;
		freopen("data.in","r",stdin);
	freopen("data.out","w",stdout);
	scanf("%d", &T);
	for (int tt = 1; tt <= T; tt++)
	{
		scanf("%d", &n);
		t = 0;
		for (int i = 0; i < n; i++)
			scanf("%d", &a[i]);
		memset(c, 0, sizeof(c));
		ans1 = ans2 = 0;
		for (i = 0; i < (1 << n); i++)
		{
			int temp = 0;
			for (int j = 0; j < n; ++j)
				if ((1 << j) & i)
					temp += a[j];
			if (c[temp] == 0)
				c[temp] = i;
			else
			{
				ans1 = c[temp];
				ans2 = i;
				break;
			}
		}
		t = ans1 & ans2;
		ans1 -= t;
		ans2 -= t;
		printf("Case #%d:\n", tt);
		if (ans1 && ans2)
		{
			bool flag1 = true, flag2 = true;
			for (i = 0; i < n; i++)
				if ((1 << i) & ans1)
				{
					if (!flag1)
						putchar(' ');
					else
						flag1 = false;
					printf("%d", a[i]);
				}
			puts("");
			for (i = 0; i < n; i++)
			{
				if ((1 << i) & ans2)
				{
					if (!flag2)
						putchar(' ');
					else
						flag2 = false;
					printf("%d", a[i]);
				}

			}
			puts("");
		}
		else
			printf("Impossible\n");
	}
	return 0;
}
