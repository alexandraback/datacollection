/*
 * $File: c.cpp
 * $Date: Sat Apr 14 11:44:25 2012 +0800
 * $Author: jiakai <jia.kai66@gmail.com>
 */

#include <cstdio>
#include <cassert>

static const int RANGE_MAX = 2000005;

static int work(int range_left, int range_right)
{
	static int used[RANGE_MAX], used_flag = 0;
	int ret = 0;
	for (int i = range_left; i <= range_right; i ++)
	{
		used_flag ++;

		int v0 = i, v1 = 0, pow_v0 = 1, pow_v1 = 1;
		while (pow_v1 <= i)
			pow_v1 *= 10;
		while (v0)
		{
			v1 += (v0 % 10) * pow_v0;
			v0 /= 10;
			pow_v0 *= 10;

			pow_v1 /= 10;
			int tmp = v1 * pow_v1 + v0;
			if (tmp >= range_left && tmp <= range_right && tmp > i && used[tmp] != used_flag)
			{
				used[tmp] = used_flag;
				ret ++;
			}
		}
	}
	return ret;
}

int main()
{
	int ncase;
	scanf("%d", &ncase);
	for (int casenu = 1; casenu <= ncase; casenu ++)
	{
		printf("Case #%d: ", casenu);
		int a, b;
		scanf("%d%d", &a, &b);
		printf("%d\n", work(a, b));
	}
}

