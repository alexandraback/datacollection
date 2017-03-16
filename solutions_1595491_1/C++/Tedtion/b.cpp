#include <stdio.h>
int main()
{
	int t, s, n, p, i, score[188];
	int ans, maxc;

	freopen("B-large.in", "r", stdin);
	freopen("b_large.out", "w", stdout);

	scanf("%d",&t);
	for (int cas = 1; cas <= t; cas++)
	{
		scanf("%d%d%d",&n, &s, &p);
		for (i=0; i<n; i++) scanf("%d", &score[i]);
		ans = 0;
		for (i=0; i<n; i++)
		{
			maxc = score[i]/3 + (score[i]%3+2)/3;
			if (maxc >= p) ans++;
			else if (s && score[i] >= 2 && score[i] <= 28)
			{
				maxc = (score[i]+1)/3 + 1;
				if (maxc >= p) {
					ans++;
					s--;
				}
			}
		}
		printf("Case #%d: %d\n", cas, ans);
	}
	return 0;
}
