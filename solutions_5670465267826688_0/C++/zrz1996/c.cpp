#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <iostream>
#include <algorithm>
#include <set>
#include <map>
#include <vector>
#include <string>
#include <queue>
using namespace std;
typedef long long LL;
#define For(i,a,b) for (int i = (a); i <= (b); i++)
#define Cor(i,a,b) for (int i = (a); i >= (b); i--)
#define Fill(a,b) memset(a,b,sizeof(a))
const int maxn = 10010;
const int maxm = maxn * 7;
inline int multi(int a, int b)
{
	if (a == 1)
		return b;
	if (b == 1)
		return a;
	if (a == b)
		return -1;
	if (a == 2)
	{
		switch (b)
		{
			case 3: return 4;
			case 4: return -3;
		}
	}
	if (a == 3)
	{
		switch (b)
		{
			case 2: return -4;
			case 4: return 2;
		}
	}
	if (a == 4)
	{
		switch (b)
		{
			case 2: return 3;
			case 3: return -2;
		}
	}
}
int v[maxm], l, x, c[maxm];
char s[maxn];
void init()
{
	scanf("%d%d", &l, &x);
	scanf("%s", s);
	int ret = 1;
	for (int i = 0; i < l; i++)
	{
		switch (s[i])
		{
			case '1':
			{
				v[i] = 1;
				break;
			}
			case 'i':
			{
				v[i] = 2;
				break;
			}
			case 'j':
			{
				v[i] = 3;
				break;
			}
			case 'k':
			{
				v[i] = 4;
				break;
			}
		}
		if (ret < 0)
			ret = -multi(-ret, v[i]);
		else
			ret = multi(ret, v[i]);
	}
	LL tot = x % 4;
	int t = 1;
	For (i, 1, tot)
	{
		int w = 1;
		if (t < 0)
			t = -t, w *= -1;
		if (ret < 0)
			t = -multi(t, -ret) * w;
		else
			t = multi(t, ret) * w;
	}
	if (t != -1)
	{
		printf("NO\n");
		return;
	}
	int n;
	For(i, 1, min(5, x - 1))
		For(j, 0, l - 1)
		v[i * l + j] = v[j];
	n = min(6, x) * l - 1;
	c[0] = v[0];
	bool flag = (c[0] == 2);
	For(i, 1, n)
	{
		if (c[i - 1] < 0)
			c[i] = -multi(-c[i - 1], v[i]);
		else
			c[i] = multi(c[i - 1], v[i]);
		if (flag && c[i] == 4)
		{
			printf("YES\n");
			return;
		}
		if (c[i] == 2)
			flag = 1;
	}
	printf("NO\n");
}
int main()
{
	freopen("c.in", "r", stdin);
	freopen("c.out", "w", stdout);
	int t;
	scanf("%d", &t);
	For(i, 1, t)
	{
		printf("Case #%d: ", i);
		init();
	}
	return 0;
}
