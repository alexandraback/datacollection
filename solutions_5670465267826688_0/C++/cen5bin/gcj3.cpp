#include <cstdio>
#include <cstring>

int a[5][5] = {{0}, {0, 1, 2, 3, 4}, {0, 2, -1, 4, -3}, {0, 3, -4, -1, 2}, {0, 4, 3, -2, -1}};


inline int cal(int x, int y)
{
	if (x == -1 || x == 1 || y == 1 || y == -1) return x*y;
	int tmp = 1;
	if (x < 0) x = -x, tmp = -tmp;
	if (y < 0) y = -y, tmp = -tmp;
	return a[x][y] * tmp;
}
inline int transition(char c)
{
	if (c == 'i') return 2;
	if (c == 'j') return 3;
	if (c == 'k') return 4;
	return 0;
}

typedef long long LL;
char s[10010];
int xx[10010];
struct aa
{
	int count, len;
}a1[10010], a2[10010];


int main()
{
	freopen("3in.txt", "r", stdin);
	freopen("3out.txt", "w", stdout);
	int T;
	scanf("%d", &T);
	for (int cas = 1; cas <= T; ++cas)
	{
		LL x, l;
		scanf("%lld%lld", &l, &x);
		scanf("%s", s);
		printf("Case #%d: ", cas);
		for (int i = 0; i < l; ++i)
			xx[i] = transition(s[i]);
		int ret = 1;
		for (int i = 0; i < l; ++i)
			ret = cal(ret, xx[i]);
		int tmp = ret;
		for (int i = 1; i < x % 4; ++i)
			ret = cal(ret, tmp);
		if (ret != -1)
		{
			puts("NO");
			continue;
		}
		int x0 = 1;
		int cnt1 = 0;
		for (int i = 0; i < l; ++i)
		{
			x0 = cal(x0, xx[i]);
			if (x0 == 2 || x0 == -2)
			{
				if (tmp == 1 && x0 == -2) continue;
				a1[cnt1].len = i;
				if (tmp == -1)
					a1[cnt1++].count = (x0 == 2 ? 0 : 1);
				else 
					a1[cnt1++].count = (x0 == 2 ? 0 : 2);
				continue;
			}
			if (x0 == 3 || x0 == -3)
			{
				if (tmp == 4 || tmp == -4)
				{
					a1[cnt1].len = i;
					a1[cnt1++].count = (x0 * tmp > 0 ? 3 : 1);
				}
				continue;
			}
			if (x0 == 4 || x0 == -4)
			{
				if (tmp == 3 || tmp == -3)
				{
					a1[cnt1].len = i;
					a1[cnt1++].count = (x0 * tmp > 0 ? 1 : 3);
				}
				continue;
			}
		}

		x0 = 1;
		int cnt2 = 0;
		for (int i = l - 1; i >= 0; --i)
		{
			x0 = cal(xx[i], x0);
			if (x0 == 4 || x0 == -4)
			{
				if (tmp == 1 && x0 == -4) continue;
				a2[cnt2].len = i;
				if (tmp == -1)
					a2[cnt2++].count = (x0 > 0 ? 0 : 1);
				else 
					a2[cnt2++].count = (x0 > 0 ? 0 : 2);
				continue;
			}
			if (x0 == 2 || x0 == -2)
			{
				if (tmp == 3 || tmp == -3)
				{
					a2[cnt2].len = i;
					a2[cnt2++].count = (x0 * tmp > 0 ? 1 : 3);
				}
				continue;
			}
			if (x0 == 3 || x0 == -3)
			{
				if (tmp == 2 || tmp == -2)
				{
					a2[cnt2].len = i;
					a2[cnt2++].count = (x0 * tmp < 0 ? 1 : 3);
				}
				continue;
			}
		}
		
		bool yes = 0;
		const int inf = 0x7fffffff;
		int ttt[4] = {inf, inf, inf, inf};
		for (int i = 0; i < cnt1; ++i)
			if (ttt[a1[i].count] > a1[i].len) ttt[a1[i].count] = a1[i].len;
		for (int i = 0; i < 4; ++i)
		if (ttt[i] != inf)
		{
			for (int j = 0; j < cnt2; ++j)
			{
				if (a2[j].count + i + 1 > x) continue;
				if (a2[j].len > ttt[i] + 1) 
				{
					yes = 1;
					break;
				}
				if (a2[j].count + i + 2 > x) continue;
				yes = 1;
				break;
			}
			if (yes) break;
		}
		if (yes) puts("YES");
		else puts("NO");
	}
	return 0;
}
