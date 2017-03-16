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
const int N = 1010, M = 0, Z = 1e9 + 7, ms63 = 0x3f3f3f3f;
#include<sstream>
int casenum, casei;
void fre() 
{ 
	freopen("c://test//input.in", "r", stdin); 
	freopen("c://test//output.out", "w", stdout); 
}
LL ans[1000010];
void table()
{
	int aim = (1 << 10) - 1;
	for (int X = 1; X <= 1000000; ++X)
	{
		LL x = X;
		int sta = 0;
		int step = 0;
		while (1)
		{
			++step;
			LL y = x;
			while (y)
			{
				sta |= 1 << y % 10;
				y /= 10;
			}
			if (sta == aim)break;
			x += X;
		}
		ans[X] = x;
	}
}
int main()
{
	//fre();
	table();
	scanf("%d", &casenum);
	for (casei = 1; casei <= casenum; ++casei)
	{
		int x;
		scanf("%d", &x);
		if (x == 0)printf("Case #%d: INSOMNIA\n", casei);
		else printf("Case #%d: %lld\n", casei, ans[x]);
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