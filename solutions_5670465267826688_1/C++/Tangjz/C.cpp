#include <cstdio>
const int maxn = 10010, oper[4][4] = {
{ 1,  2,  3,  4},
{ 2, -1,  4, -3},
{ 3, -4, -1,  2},
{ 4,  3, -2, -1}};
int t, n, pre[maxn][4], suf[maxn][4];
long long m;
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
		scanf("%d%lld%s", &n, &m, str);
		pre[0][0] = 1;
		for(int i = 1; i <= n; ++i)
			pre[i][0] = op(pre[i - 1][0], trans(str[i - 1]));
		for(int k = 1; k < 4; ++k)
		{
			pre[0][k] = pre[n][k - 1];
			for(int i = 1; i <= n; ++i)
				pre[i][k] = op(pre[i - 1][k], trans(str[i - 1]));
		}
		suf[n + 1][0] = 1;
		for(int i = n; i >= 1; --i)
			suf[i][0] = op(trans(str[i - 1]), suf[i + 1][0]);
		for(int k = 1; k < 4; ++k)
		{
			suf[n + 1][k] = suf[1][k - 1];
			for(int i = n; i >= 1; --i)
				suf[i][k] = op(trans(str[i - 1]), suf[i + 1][k]);
		}
		int flag = 0;
		for(int i = 1; i <= n * 4 && !flag; ++i)
		{
			int ri = (i - 1) % n + 1, ci = (i - 1) / n;
			if(ci >= m)
				break;
			if(pre[ri][ci] != trans('i'))
				continue;
			for(int j = 1; j <= n * 4 && !flag; ++j)
			{
				int rj = (j - 1) % n + 1, cj = (j - 1) / n;
				if(ci + cj >= m)
					break;
				if(suf[rj][cj] != trans('k'))
					continue;
				int lk = ri + 1, rk = rj - 1;
				long long sk = m - ci - cj;
				if(lk > n)
				{
					lk = 1;
					--sk;
				}
				if(rk < 1)
				{
					rk = n;
					--sk;
				}
				if(sk <= 0 || sk == 1 && lk > rk)
					continue;
				int tmp;
				if(sk == 1)
					tmp = op(pre[rk][0], pre[lk - 1][0]);
				else
				{
					sk -= 2;
					tmp = suf[lk][0];
					for(int i = 0; i < sk % 4; ++i)
						tmp = op(tmp, pre[0][1]);
					tmp = op(tmp, pre[rk][0]);
				}
				if(tmp == trans('j'))
					flag = 1;
			}
		}
		printf("Case #%d: %s\n", Case, flag ? "YES" : "NO");
	}
	return 0;
}
