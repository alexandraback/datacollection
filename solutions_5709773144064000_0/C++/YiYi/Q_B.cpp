#include<cstdio>

int main()
{
	freopen("B-small-attempt0.in", "r", stdin);
	freopen("B-small-attempt0.out", "w", stdout);
	int T;
	scanf("%d", &T);
	for(int cas = 1; cas <= T; cas ++)
	{
		double c, f, x;
		scanf("%lf %lf %lf", &c, &f, &x);
		
		double v = 2, next = 0, ans = x/v;
		double t = 0;
		
		int i;
		for(i = 1;; i ++)
		{
			t += c/v;
			v += f;
			next = t + x/v;
			if(ans < next)break;
			ans = next;
			//printf("%lf %lf\n", ans, next);
		}
		printf("Case #%d: %.9lf\n", cas, ans);
	}
	return 0;
}
