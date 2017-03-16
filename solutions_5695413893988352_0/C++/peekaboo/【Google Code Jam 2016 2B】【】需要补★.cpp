#include<stdio.h>
#include<iostream>
#include<string.h>
#include<string>
#include<ctype.h>
#include<math.h>
#include<set>
#include<map>
#include<vector>
#include<queue>
#include<bitset>
#include<algorithm>
#include<time.h>
using namespace std;
void fre() { freopen("c://test//input.in", "r", stdin); freopen("c://test//output.out", "w", stdout); }
#define MS(x,y) memset(x,y,sizeof(x))
#define MC(x,y) memcpy(x,y,sizeof(x))
#define MP(x,y) make_pair(x,y)
#define ls o<<1
#define rs o<<1|1
typedef long long LL;
typedef unsigned long long UL;
typedef unsigned int UI;
template <class T1, class T2>inline void gmax(T1 &a, T2 b) { if (b>a)a = b; }
template <class T1, class T2>inline void gmin(T1 &a, T2 b) { if (b<a)a = b; }
const int N = 0, M = 0, Z = 1e9 + 7, ms63 = 0x3f3f3f3f;
int casenum, casei;
char a[20], b[20];
int n;
LL ans;
LL X,Y;
void dfs(int p, int d, LL x, LL y)
{
	if (abs(x - y) > ans)return;
	if (p == n)
	{
		if (abs(x - y) < ans)
		{
			ans = abs(x - y);
			Y = y;
			X = x;
		}
		else if(x < X || x== X && y < Y)
		{
			Y = y;
			X = x;
		}
		return;
	}
	if (d == 0)
	{
		if (a[p] == '?' && b[p] == '?')
		{
			if (p < n - 1 && a[p + 1] == '?'&&b[p + 1] == '?')
			{
				dfs(p + 1, 0, x * 10, y * 10);
			}
			else
			{
				dfs(p + 1, 0, x * 10, y * 10);
				dfs(p + 1, 1, x * 10 + 1, y * 10);
				dfs(p + 1, -1, x * 10, y * 10 + 1);
			}
		}
		else if (a[p] == '?')
		{
			dfs(p + 1, 0, x * 10 + b[p] - '0', y * 10 + b[p] - '0');
			if(b[p]>'0')dfs(p + 1, -1, x * 10 + b[p] - '0'-1, y * 10 + b[p] - '0');
			if(b[p]<'9')dfs(p + 1, +1, x * 10 + b[p] - '0'+1, y * 10 + b[p] - '0');
		}
		else if (b[p] == '?')
		{
			dfs(p + 1, 0, x * 10 + a[p] - '0', y * 10 + a[p] - '0');
			if (a[p]>'0')dfs(p + 1, +1, x * 10 + a[p] - '0', y * 10 + a[p] - '0'-1);
			if (a[p]<'9')dfs(p + 1, -1, x * 10 + a[p] - '0', y * 10 + a[p] - '0'+1);
		}
		else
		{
			if (a[p] == b[p])dfs(p + 1, 0, x * 10 + a[p] - '0', y * 10 + b[p] - '0');
			if (a[p] < b[p])dfs(p + 1, -1, x * 10 + a[p] - '0', y * 10 + b[p] - '0');
			if (a[p] > b[p])dfs(p + 1, +1, x * 10 + a[p] - '0', y * 10 + b[p] - '0');
		}
	}
	//前者'9'，后者'0';
	else if (d == -1)
	{
		dfs(p + 1, -1, x * 10 + (a[p] == '?' ? 9 : a[p] - '0'), y * 10 + (b[p] == '?' ? 0 : b[p] - '0'));
	}
	//前者'0'，后者'9'
	else if (d == 1)
	{
		dfs(p + 1, 1, x * 10 + (a[p] == '?' ? 0 : a[p] - '0'), y * 10 + (b[p] == '?' ? 9 : b[p] - '0'));
	}
}
int main()
{
	fre();
	scanf("%d", &casenum);
	for (casei = 1; casei <= casenum; ++casei)
	{
		scanf("%s%s", a, b);
		n = strlen(a);
		ans = 5e18;
		dfs(0, 0, 0, 0);
		if (n == 1)printf("Case #%d: %01lld %01lld\n", casei, X, Y);
		if (n == 2)printf("Case #%d: %02lld %02lld\n", casei, X, Y);
		if (n == 3)printf("Case #%d: %03lld %03lld\n", casei, X, Y);
		if (n == 4)printf("Case #%d: %04lld %04lld\n", casei, X, Y);
		if (n == 5)printf("Case #%d: %05lld %05lld\n", casei, X, Y);
		if (n == 6)printf("Case #%d: %06lld %06lld\n", casei, X, Y);
		if (n == 7)printf("Case #%d: %07lld %07lld\n", casei, X, Y);
		if (n == 8)printf("Case #%d: %08lld %08lld\n", casei, X, Y);
		if (n == 9)printf("Case #%d: %09lld %09lld\n", casei, X, Y);
		if (n == 10)printf("Case #%d: %010lld %010lld\n", casei, X, Y);
		if (n == 11)printf("Case #%d: %011lld %011lld\n", casei, X, Y);
		if (n == 12)printf("Case #%d: %012lld %012lld\n", casei, X, Y);
		if (n == 13)printf("Case #%d: %013lld %013lld\n", casei, X, Y);
		if (n == 14)printf("Case #%d: %014lld %014lld\n", casei, X, Y);
		if (n == 15)printf("Case #%d: %015lld %015lld\n", casei, X, Y);
		if (n == 16)printf("Case #%d: %016lld %016lld\n", casei, X, Y);
		if (n == 17)printf("Case #%d: %017lld %017lld\n", casei, X, Y);
		if (n == 18)printf("Case #%d: %018lld %018lld\n", casei, X, Y);
		
	}
	return 0;
}
/*
【trick&&吐槽】


【题意】


【类型】


【分析】


【时间复杂度&&优化】


【数据】


*/