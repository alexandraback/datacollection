#include <cstdio>
#include <cstring>
const int maxn = 1000005;
int num, stk[maxn], sum, rev[maxn], ans[maxn];
int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int st = 1, en = 1;
	sum = 1;
	for (int i = 1; i <= 1000000; i++)
	{
		int p[9], ws = 0, tmp = i;
		while (tmp)
		{
			p[++ws] = tmp % 10;
			tmp /= 10;
		}
		for (int j = 1; j <= ws; j++)
			rev[i] = rev[i] * 10 + p[j];
		if (rev[i] > 1000000)
			rev[i] = 1;
	}
	stk[1] = ans[1] = 1;
	while (st <= en)
	{
		for (int i = st; i <= en; i++)
		{
			int now = stk[i];
			if (ans[now + 1] == 0 && now + 1 <= 1000000)
			{
				ans[now + 1] = ans[now] + 1;
				stk[++sum] = now + 1;
			}
			if (ans[rev[now]] == 0)
			{
				ans[rev[now]] = ans[now] + 1;
				stk[++sum] = rev[now];
			}
			if (ans[rev[rev[now]]] == 0)
			{
				ans[rev[rev[now]]] = ans[now] + 1;
				stk[++sum] = rev[rev[now]] + 1;
			}
			if (ans[rev[rev[rev[now]]]] == 0)
			{
				ans[rev[rev[rev[now]]]] = ans[now] + 1;
				stk[++sum] = rev[rev[rev[now]]];
			}
		}
		st = en + 1;
		en = sum;
	}
	int test;
	scanf("%d", &test);
	for (int tt = 1; tt <= test; tt++)
	{
		int p;
		scanf("%d", &p);
		printf("Case #%d: %d\n", tt, ans[p]);
	}
	return 0;
}
