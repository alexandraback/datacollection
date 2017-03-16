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
const int V = 110;
int _, C, n, K, a[V];
int main()
{
    freopen("C.in", "r", stdin);
    freopen("C.out", "w", stdout);
	scanf("%d", &_);
	for(int ca = 1; ca <= _; ++ca)
	{
		scanf("%d%d%d", &C, &n, &K);
		for(int i = 0; i < n; ++i)
		scanf("%d", &a[i]);
		a[n++] = K + 1;
		LL R = 0;
		int ret = 0;
		for(int i = 0; i < n; ++i)
		{
			while(R + 1 < a[i])
			{
				LL tmp = R + 1;
				R += tmp * C;
				ret++;
			}
			R += a[i] * C;
		}
		printf("Case #%d: %d\n", ca, ret);
	}
	return 0;
}
