#include <stdio.h>
typedef long long i64;

i64 gcd(i64 a, i64 b) { return b ? gcd(b, a%b) : a; }

int main()
{
	int T, C, n, ans;
	int i, j, k;
	long long p, q, g;
	i64 arr[45];

	arr[0] = 1;
	for (i = 1; i <= 40; i++)
		arr[i] = arr[i-1] * 2; 
	
	scanf("%d", &T);
	for (C = 1; C <= T; C++)
	{
		scanf("%lld/%lld", &p, &q);
		g = gcd(p, q);
		p /= g;
		q /= g;

		bool flag = false;
		for (j = 0; !flag && j <= 40; j++)
			if (q == arr[j])
				flag = true;
		printf("Case #%d: ", C);
		if (flag)
		{
			ans = 0;
			while (p < q && ans <= 40)
			{
				p *= 2;
				ans++;
			}
			if (p >= q)
				printf("%d\n", ans);
			else
				puts("impossible");
		}
		else puts("impossible");
	}
	return 0;
}
