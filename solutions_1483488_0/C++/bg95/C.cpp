#include <cstdio>
#include <cstdlib>
#include <iostream>

int p10[8];
int main(void)
{
	int i, j, t;
	int A, B, cnt;
	long long ans;
	int T, c, m;
	freopen("C.in", "r", stdin);
	freopen("C.out", "w", stdout);
	p10[0] = 1;
	for (i = 1; i < 8; i++)
		p10[i] = p10[i - 1] * 10;
	scanf("%d", &T);
	for (c = 1; c <= T; c++)
	{
		scanf("%d%d", &A, &B);
		ans = 0;
		for (m = 1; p10[m] <= A; m++);
		for (i = A; i < B; i++)
		{
			//cnt = 0;
			t = i;
			for (j = 1; j < m; j++)
			{
				t = t * 10 % p10[m] + t * 10 / p10[m];
				if (t <= B && t > i)
				{
					//printf("%d %d\n", i, t);
					ans++;
				}
			}/*
			if (j < m)
				continue;
			ans += (long long)cnt * (cnt - 1) / 2;
			printf("i = %d, cnt = %d, ans += %I64d\n", i, cnt, (long long)cnt * (cnt - 1) / 2);*/
		}
		printf("Case #%d: ", c);
		std::cout << ans << "\n";
	}
	return 0;
}
