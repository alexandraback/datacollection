/*========================================================================
#   FileName: 130413c1.cpp
#     Author: YIMMON
#      Email: yimmon.zhuang@gmail.com
#   HomePage: http://qr.ae/8DMzu
# LastChange: 2013-04-13 12:08:53
========================================================================*/
#include <iostream>
#include <cstdio>
using namespace std;

int T, num[5] = {1,4,9,121,484}, a, b;

int main(int argc, char **argv)
{
	scanf("%d", &T);
	for(int cas = 1; cas <= T; ++cas)
	{
		scanf("%d%d", &a, &b);
		int ans = 0;
		for(int i = 0; i < 5; ++i)
			if(num[i] <= b && num[i] >= a)
				ans++;
		printf("Case #%d: %d\n", cas, ans);
	}

	return 0;
}
