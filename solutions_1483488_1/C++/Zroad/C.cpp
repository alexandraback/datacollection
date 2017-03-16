#include <cstdio>
#include <cstring>

const int maxn = 20000000 + 5;
int T, tcase, A, B, ans;
bool v[maxn];

void update(int num)
{
	if (num < 10)  return;
	int tmp = num, len = 0, base = 1;
	for (base; base < num; base *= 10, len ++);
	base /= 10;
	for (int i = 1; i <= len; i ++)
	{
		tmp = tmp % 10 * base + tmp / 10;
		if (v[tmp])  continue;
		if (A <= tmp && tmp <= B)
		{
			v[tmp] = true;
			if (num < tmp)  ans ++;
		}
	}
	for (int i = 1; i <= len; i ++)
	{
		tmp = tmp % 10 * base + tmp / 10;
		if (A <= tmp && tmp <= B)  v[tmp] = false;
	}
}
int main()
{
	freopen("C.in", "r", stdin);
	freopen("C.out", "w", stdout);
	for (scanf("%d\n", &T), tcase = 1; tcase <= T; tcase ++)
	{
		scanf("%d%d", &A, &B), ans = 0;
		memset(v, false, sizeof(v));
		for (int i = A; i <= B; i ++)
			update(i);
		printf("Case #%d: %d\n", tcase, ans);
	}
	return 0;
}
