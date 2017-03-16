#include<cstdio>
#include<cmath>

int main()
{
	int T;
	double value, p, c, f, x, t;
	scanf("%d", &T);
	for(int k = 1; k <= T; k++)
	{
		scanf("%lf%lf%lf", &c, &f, &x);
		t = value = 0.0;
		p = 2.0;
		while(true)
		{
			int cnt = floor(value / c + 0.5);
			if(cnt >= 1)
			{
				double t1 = (x - value) / p;
				double t2 = (x - (value - cnt*c)) / (p + f*cnt);
				if(t2 < t1)
				{
					value -= c * cnt;
					p += cnt * f;
				}
			}
			if(x - value <= c)
			{
				t += (x - value) / p;
				break;
			}
			else
			{
				cnt = floor(value / c + 0.5) + 1; //exist a problem
				t += (cnt * c - value) / p;
				value = cnt * c;
			}
		}
		printf("Case #%d: %.7lf\n", k, t);
	}
	return 0;
}
