/*
	Author: elfness@UESTC
*/
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
using namespace std;
typedef long long LL;
const int V = 100100;
int trans[4][4] = {
	{0,1,2,3},
	{1,0,3,2},
	{2,3,0,1},
	{3,2,1,0},
};
int sign[4][4] = {
	{1,1,1,1},
	{1,-1,1,-1},
	{1,-1,-1,1},
	{1,1,-1,-1},
};
char s[V];
int a[V];
int _, n;
LL m;
int main()
{
    freopen("C.in", "r", stdin);
    freopen("C.out", "w", stdout);
	scanf("%d", &_);
	for(int ca = 1; ca <= _; ++ca)
	{
		cerr << ca << endl;
		scanf("%d%d", &n, &m);
		scanf("%s", s);
		for(int i = 0; i < n; ++i)
		if(s[i] == 'i') a[i] = 1;
		else if(s[i] == 'j') a[i] = 2;
		else a[i] = 3;
		int sg = 1;
		int now = 0;
		int st = 0;
		if(m > 20) m = m % 4 + 20;
		for(int i = 0; i < m * n; ++i)
		{
			sg *= sign[now][a[i % n]];
			now = trans[now][a[i % n]];
			if(sg == 1 && now == st + 1)
			{
				++st, now = 0;
			}
		}
		if(st == 3 && sg == 1 && now == 0) printf("Case #%d: YES\n", ca);
		else printf("Case #%d: NO\n", ca);
	}
	return 0;
}
