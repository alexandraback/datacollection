#include <cstdio>
const int maxn = 10010, oper[4][4] = {
{ 1,  2,  3,  4},
{ 2, -1,  4, -3},
{ 3, -4, -1,  2},
{ 4,  3, -2, -1}};
int t, n, m, pre[maxn], suf[maxn];
char str[maxn];
int trans(char ch)
{
	if(ch == 'i')
		return 2;
	if(ch == 'j')
		return 3;
	if(ch == 'k')
		return 4;
}
int op(int x, int y)
{
	int sgn = 0;
	if(x < 0)
	{
		x = -x;
		sgn ^= 1;
	}
	if(y < 0)
	{
		y = -y;
		sgn ^= 1;
	}
	return sgn ? -oper[x - 1][y - 1] : oper[x - 1][y - 1];
}
int main()
{
	scanf("%d", &t);
	for(int Case = 1; Case <= t; ++Case)
	{
		scanf("%d%d%s", &n, &m, str);
		for(int i = 1; i < m; ++i)
			for(int j = 0; j < n; ++j)
				str[n * i + j] = str[j];
		n *= m;
		pre[0] = 1;
		for(int i = 1; i <= n; ++i)
			pre[i] = op(pre[i - 1], trans(str[i - 1]));
		suf[n + 1] = 1;
		for(int i = n; i >= 1; --i)
			suf[i] = op(trans(str[i - 1]), suf[i + 1]);
		int flag = 0;
		for(int i = 1; i <= n && !flag; ++i)
		{
			if(pre[i] != trans('i'))
				continue;
			for(int j = 1; j <= n && !flag; ++j)
			{
				if(suf[j] != trans('k'))
					continue;
				int lk = i + 1, rk = j - 1;
				if(lk > rk)
					continue;
				int tmp;
				/*
				tmp = 1;
				for(int i = lk; i <= rk; ++i)
					tmp = op(tmp, trans(str[i - 1]));
				*/
				tmp = op(pre[rk], pre[lk - 1]);
				if(tmp == trans('j'))
					flag = 1;
			}
		}
		printf("Case #%d: %s\n", Case, flag ? "YES" : "NO");
	}
	return 0;
}
