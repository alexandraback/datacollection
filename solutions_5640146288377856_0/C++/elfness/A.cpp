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
int _, R, C, W;
int main()
{
    freopen("A.in", "r", stdin);
    freopen("A.out", "w", stdout);
	scanf("%d", &_);
	for(int ca = 1; ca <= _; ++ca)
	{
		scanf("%d%d%d", &R, &C, &W);
		int ret = 0;
		int last = 1;
		if(C % W == 0) last = 0;
		ret = (C / W - 1) * R;
		ret += max(R + last + W - 1, W);
		printf("Case #%d: %d\n", ca, ret);
	}
	return 0;
}
