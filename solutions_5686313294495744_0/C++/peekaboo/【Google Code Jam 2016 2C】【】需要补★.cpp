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
int n;
int b[24];
set<string>sot[2];
char s[16][2][24];
bool check(int i)
{
	for (int j = 0; j < n; ++j)if (~i&b[j])
	{
		if (!sot[0].count(s[j][0]))return 0;
		if (!sot[1].count(s[j][1]))return 0;
	}
	return 1;
}
int main()
{
	fre();
	for (int i = 0; i <= 20; ++i)b[i] = 1 << i;
	scanf("%d", &casenum);
	for (casei = 1; casei <= casenum; ++casei)
	{
		scanf("%d", &n);
		for (int i = 0; i < n; ++i)
		{
			scanf("%s", s[i][0]);
			scanf("%s", s[i][1]);
		}
		int top = 1 << n;
		int ans = 0;
		for (int i = 0; i < top; ++i)
		{
			sot[0].clear();
			sot[1].clear();
			int num = n;
			for (int j = 0; j < n; ++j)if (i&b[j])
			{
				--num;
				sot[0].insert(s[j][0]);
				sot[1].insert(s[j][1]);
			}
			if (num > ans&&check(i))ans = num;
		}
		printf("Case #%d: %d\n", casei, ans);
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