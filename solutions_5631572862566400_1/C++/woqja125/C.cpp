#include<stdio.h>
#include<algorithm>
int c[1001], bf[1001], ind[1001];
int max(int a, int b) { return a > b ? a : b; }
int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int T;
	scanf("%d", &T);
	for (int TT = 1; TT <= T; TT++)
	{
		int i, n, mc = 0, ch=0;
		int q[1010], f=-1, r=-1;
		scanf("%d", &n);
		for (i = 1; i <= n; i++) c[i] = ind[i] = 0;
		for (i = 1; i <= n; i++)
		{
			scanf("%d", bf + i);
			ind[bf[i]]++;
		}
		for (i = 1; i <= n; i++) if (ind[i] == 0) q[++r] = i;
		while (f < r)
		{
			int x = q[++f];
			c[bf[x]] = max(c[bf[x]], c[x] + 1);
			if (--ind[bf[x]] == 0) q[++r] = bf[x];
		}
		for (i = 1; i <= n; i++)
		{
			if (ind[i] != 0)
			{
				int cl = 1,t;
				ind[i] = 0;
				for (t = bf[i]; t != i; t = bf[t]) ind[t] = 0, cl++;
				if (cl == 2) ch += 2 + c[i] + c[bf[i]];
				else if (mc < cl) mc = cl;
			}
		}
		printf("Case #%d: %d\n", TT, max(ch, mc));	
	}
	return 0;
}