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
char a[10][10] = { "ZERO","ONE","TWO","THREE","FOUR","FIVE","SIX","SEVEN","EIGHT","NINE" };
int b[10];
map<string, int>mop;
void init()
{
	for (int i = 0; i < 10; ++i)
	{
		int n = strlen(a[i]);
		for (int j = 0; j < n; ++j)b[j] = j;
		do
		{
			string s = "";
			for (int j = 0; j < n; ++j)s = s + a[i][b[j]];
			mop[s] = i;
		} while (next_permutation(b, b + n));
	}
}
char s[2020];
int cnt[128];
int v[10];
int main()
{
	fre();
	init();
	scanf("%d", &casenum);
	for (casei = 1; casei <= casenum; ++casei)
	{
		scanf("%s", s);
		int n = strlen(s);
		MS(cnt, 0);
		for (int i = 0; i < n; ++i)++cnt[s[i]];
		MS(v, 0);

		v[0] = cnt['Z'];
		for (int i = 0; a[0][i]; ++i)cnt[a[0][i]] -= v[0];

		v[2] = cnt['W'];
		for (int i = 0; a[2][i]; ++i)cnt[a[2][i]] -= v[2];

		v[4] = cnt['U'];
		for (int i = 0; a[4][i]; ++i)cnt[a[4][i]] -= v[4];

		v[1] = cnt['O'];
		for (int i = 0; a[1][i]; ++i)cnt[a[1][i]] -= v[1];

		v[3] = cnt['R'];
		for (int i = 0; a[3][i]; ++i)cnt[a[3][i]] -= v[3];

		v[5] = cnt['F'];
		for (int i = 0; a[5][i]; ++i)cnt[a[5][i]] -= v[5];

		v[6] = cnt['X'];
		for (int i = 0; a[6][i]; ++i)cnt[a[6][i]] -= v[6];

		v[7] = cnt['S'];
		for (int i = 0; a[7][i]; ++i)cnt[a[7][i]] -= v[7];

		v[8] = cnt['G'];
		for (int i = 0; a[8][i]; ++i)cnt[a[8][i]] -= v[8];

		v[9] = cnt['E'];
		for (int i = 0; a[9][i]; ++i)cnt[a[9][i]] -= v[9];

		printf("Case #%d: ", casei);
		for (int i = 0; i < 10; ++i)
		{
			while (v[i]--)printf("%d", i);
		}
		puts("");
	}
	return 0;
}
/*
【trick&&吐槽】
ZEROONETWOTHREEFOURFIVESIXSEVENEIGHTNINE

【题意】


【类型】


【分析】


【时间复杂度&&优化】


【数据】


*/