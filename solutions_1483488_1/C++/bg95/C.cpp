#include <cstdio>
#include <cstdlib>
#include <iostream>

int p10[8];
bool vis[2000010];
int main(void)
{
	int i, j, t;
	int A, B, cnt;
	long long ans;
	int T, c, m;
	freopen("C.in", "r", stdin);
	freopen("C.out", "w", stdout);
	memset(vis, 0, sizeof(vis));
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
			t = i;
			for (j = 1; j < m; j++)
			{
				t = t * 10 % p10[m] + t * 10 / p10[m];
				if (t <= B && t > i && !vis[t])
				{
					vis[t] = true;
					ans++;
				}
			}
			t = i;
			for (j = 1; j < m; j++)
			{
				t = t * 10 % p10[m] + t * 10 / p10[m];
				if (t <= B && t > i)
				{
					vis[t] = false;
				}
			}
		}
		printf("Case #%d: ", c);
		std::cout << ans << "\n";
	}
	return 0;
}
