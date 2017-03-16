#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <string>
#include <cmath>
#include <algorithm>
#include <ctime>
#include <stack>
using namespace std;
typedef long long ll;
const int maxn = 5e5 + 9;
const int inf = 1e9 + 9;

int alen, blen;
string a, b;
int del, x, y;

int dfs1(int l, int v);
int dfs2(int l, int v, int tv, int tl);

int main()
{
	freopen("B-small-attempt0.in","r",stdin);
	freopen("out.txt","w",stdout);

	int t;
	scanf("%d", &t);
	int cass = 1;
	while (t--)
	{
		del = 10000, x = 1000, y = 1000;
		cin >> a >> b;
		alen = a.length(), blen = b.length();
		printf("Case #%d: ", cass++);
		dfs1(0, 0);
		int zz = pow(10, alen - 1);
		for (int i = 0; i<alen; i++)
		{
			printf("%d", x / zz);
			x %= zz; zz /= 10;
		}
		printf(" ");
		int tt = pow(10, blen - 1);
		for (int i = 0; i<blen; i++)
		{
			printf("%d", y / tt);
			y %= tt; tt /= 10;
		}
		printf("\n");
	}
	return 0;
}

int dfs2(int l, int v, int tv, int tl)
{
	if (l == blen)
	{
		if (abs(v - tv) == del)
		{
			del = min(del, abs(v - tv));
			if (tv == x)
			{
				if (v<y) y = v;
			}
			else if (tv<x)
			{
				x = tv; y = v;
			}
		}
		else if (abs(v - tv)<del)
		{
			del = abs(v - tv);
			x = tv, y = v;
		}
		return 0;
	}
	if (b[l] != '?')
		dfs2(l + 1, v * 10 + b[l] - '0', tv, tl);
	else
	{
		for (int i = 0; i<10; i++)
			dfs2(l + 1, v * 10 + i, tv, tl);
	}
	return 0;
}

int dfs1(int l, int v)
{
	if (l == alen)
	{
		dfs2(0, 0, v, l); return 0;
	}
	if (a[l] != '?')
	{
		dfs1(l + 1, v * 10 + a[l] - '0'); return 0;
	}
	for (int i = 0; i<10; i++)
	{
		dfs1(l + 1, v * 10 + i);
	}
	return 0;
}
