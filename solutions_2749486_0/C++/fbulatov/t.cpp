#pragma comment(linker, "/STACK:500000000")
#include <functional>
#include <algorithm>
#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <sstream>
#include <ctype.h>
#include <stdio.h>
#include <bitset>
#include <vector>
#include <string>
#include <math.h>
#include <time.h>
#include <queue>
#include <stack>
#include <list>
#include <complex>
#include <map>
#include <set>
#define Int unsigned long long
#define inf 0x3f3f3f3f
#define eps 1e-9
using namespace std;
#define N 105

string res;

int main()
{
	freopen("i.txt", "rt", stdin);
	freopen("o.txt", "wt", stdout);
	int t, x, y, i;
	cin >> t;
	int tt = 0;
	while(t--)
	{
		tt++;
		scanf("%d %d", &x, &y);
		if(tt == 48)
			x = x;
		res.clear();
		int sx = 0, sy = 0;
		int len = 1;
		if(x > 0)
			while(sx + len <= x)
				sx += len, len++, res += "E";
		else
			while(sx - len >= x)
				sx -= len, len++, res += 'W';
		if(sx != x)
		{
			int cnt = abs(sx - x);
			while(cnt--)
			{
				if(sx < x)
					res += "WE", len += 2;
				else
					res += "EW", len += 2;
			}
		}

		if(y > 0)
			while(sy + len <= y)
				sy += len, len++, res += "N";
		else
			while(sy - len >= y)
				sy -= len, len++, res += 'S';
		if(sy != y)
		{
			int cnt = abs(sy - y);
			while(cnt--)
			{
				if(sy < y)
					res += "SN";
				else
					res += "NS";
			}
		}
		printf("Case #%d: %s\n", tt, res.c_str());
	}
}