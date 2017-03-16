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
int _, n, p[V];
int main()
{
    freopen("B.in", "r", stdin);
    freopen("B.out", "w", stdout);
	scanf("%d", &_);
	for(int ca = 1; ca <= _; ++ca)
	{
		scanf("%d", &n);
		for(int i = 0; i < n; ++i)
		scanf("%d", &p[i]);
		int mx = 0;
		for(int i = 0; i < n; ++i)
		mx = max(mx, p[i]);
		int ret = mx;
		for(int i = 1; i <= mx; ++i)
		{
			int extra = 0;
			for(int j = 0; j < n; ++j)
			{
				extra += (p[j] - 1)/ i;
			}
			ret = min(ret, i + extra);
		}
		printf("Case #%d: %d\n", ca, ret);
	}
	return 0;
}
