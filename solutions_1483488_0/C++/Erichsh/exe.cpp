#include <cstdio>
#include <cstring>

bool vs[2000000+10];
long long ans;

int main ()
{
	//freopen("data.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int T;	scanf("%d", &T);
	for (int tc = 1; tc <= T; tc++)
	{
		memset(vs, 0, sizeof(vs));

		ans = 0;
		int a, b;	scanf("%d%d", &a, &b);
		int len = 0, tem = a;
		while (tem)		len++, tem /= 10;

		if (len ==1)	
		{
			printf("Case #%d: 0\n", tc);
			continue;
		}

		int q = 1;
		while (--len)		q *= 10;

		for (int i = a; i <= b; i++)
			if (!vs[i])
			{	//printf("%d ", i);
				vs[i] = 1;
				int x = i, tem = i, cnt = 1;
				while (1)
				{
					if (tem % 10 != 0)
					{
						tem = (tem / 10) + (tem % 10) * q;
						if (tem >= a && tem <= b && !vs[tem])	{	cnt++;	vs[tem] = 1;	/*printf("%d ", tem);*/}
						if (tem == x)	break;
					}
					else 
						tem = (tem / 10) + (tem % 10) * q;
				}
				ans += cnt * (cnt-1) / 2;	//printf("\n");
			}
		printf("Case #%d: %lld\n", tc, ans);
	}
}