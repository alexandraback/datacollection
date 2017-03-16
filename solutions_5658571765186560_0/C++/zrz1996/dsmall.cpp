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
int d3[5][5];
int d4[5][5];
void init()
{
	d3[3][1] = 0;
	d3[3][2] = 1;
	d3[3][3] = 1;
	d3[4][3] = 1;
	d4[2][2] = 0;
	d4[4][1] = 0;
	d4[4][2] = 0;
	d4[4][3] = 1;
	d4[4][4] = 1;
}
void solve()
{
	int n, r, c;
	scanf("%d%d%d", &n, &r, &c);
	if (n == 1)
	{
		printf("GABRIEL\n");
		return;
	}
	if (n == 2)
	{
		if (r * c % 2 == 0)
			printf("GABRIEL\n");
		else
			printf("RICHARD\n");
		return;
	}
	if (n == 3 || n == 4)
	{
		if (r * c % n != 0)
		{
			printf("RICHARD\n");
			return;
		}
		if (r < c)
			swap(r, c);
		if (n == 3)
		{
			if (d3[r][c] == 0)
				printf("RICHARD\n");
			else
				printf("GABRIEL\n");
		}
		if (n == 4)
		{
			if (d4[r][c] == 0)
				printf("RICHARD\n");
			else
				printf("GABRIEL\n");
		}
	}
}
int main()
{
	freopen("d.in", "r", stdin);
	freopen("d.out", "w", stdout);
	init();
	int t;
	scanf("%d", &t);
	For(i, 1, t)
	{
		printf("Case #%d: ", i);
		solve();
	}
	return 0;
}
