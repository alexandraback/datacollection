#include<cstdio>

int main()
{
	int t, a, b;
	bool *used = new bool[2000000];
	scanf("%d", &t);
	for(int d = 1; d <= t; ++d)
	{
		scanf("%d %d", &a, &b);
		for(int i = a; i <= b; ++i)
			used[i] = 0;
		int dl = 0, tmp = a, ans = 0, pairs = 0, base = 1;
		while(tmp != 0)
		{
			tmp /= 10;
			dl++;
			base *= 10;
		}
		base /= 10;
		dl--;
		for(int x = a; x <= b; ++x)
			if(used[x] == 0)
			{
				used[x] = 1;
				pairs = 1;
				tmp = x;
				for(int i = 0; i < dl; ++i)
				{
					tmp = (tmp % base) * 10 + (tmp / base);
					if(tmp >= a && tmp <= b && used[tmp] == 0)
					{
						pairs++;
						used[tmp] = 1;
					}
				}
				ans = ans + ((pairs * (pairs - 1)) / 2);
			}
		printf("Case #%d: %d\n", d, ans);
	}
}