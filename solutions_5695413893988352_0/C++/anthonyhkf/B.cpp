#include <bits/stdc++.h>

using namespace std;

char a[101], b[101];

char p[20] = {}, q[20] = {};
char tp[20], tq[20];

int l;
long long mindiff;

void rec(int x, int v, long long val1, long long val2)
{
	if (v == 1)
	{
		if (x == l)
		{
			if (abs(val1 - val2) < mindiff)
			{
				mindiff = abs(val1 - val2);
				for (int i = 0; i < l; ++i)
				{
					p[i] = tp[i];
					q[i] = tq[i];
				}
			}
			return;
		}
		else
		{
			if (b[x] == '?')
			{
				for (int i = 0; i < 10; ++i)
				{
					tq[x] = i + '0';
					rec(x + 1, v, val1, val2 * 10 + i);
				}
			}
			else
			{
				tq[x] = b[x];
				rec(x + 1, v, val1, val2 * 10 + b[x] - '0');
			}
		}
	}
	if (v == 0)
	{
		if (x == l)
		{
			rec(0, 1, val1, val2);
		}
		else
		if (a[x] == '?')
		{
			for (int i = 0; i < 10; ++i)
			{
				tp[x] = i + '0';
				rec(x + 1, v, val1 * 10 + i, val2);
			}
			
		}
		else
		{
			tp[x] = a[x];
			rec(x + 1, v, val1 * 10 + a[x] - '0', val2);
		}
	}
}

int main()
{
	int t;
	scanf("%d", &t);
	for (int tc = 1; tc <= t; ++tc)
	{
		scanf("%s %s", a, b);

		memset(p, 0, sizeof p);
		memset(q, 0, sizeof q);
		
		l = strlen(a);

		mindiff = 1e18;
		rec(0, 0, 0, 0);

		printf("Case #%d: %s %s\n", tc, p, q);
	}
	return 0;
}