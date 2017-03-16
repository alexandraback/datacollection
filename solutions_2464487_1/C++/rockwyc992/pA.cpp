/*************************************************************************
    > File Name: pA.cpp
    > Author: rockwyc992
    > Mail: rockwyc992@gmail.com 
    > Created Time: 2013年04月27日 (週六) 08時52分43秒
 ************************************************************************/

#include <stdio.h>
#include <string.h>
#include <map>
#include <queue>
#include <vector>
#include <algorithm>

int T;

typedef unsigned long long ull;

ull r, want;
ull tmp;

bool check(ull x)
{
	tmp = (r<<1) + (x<<1) - 1;
	tmp *= x;

	return tmp <= want;
}

ull bs()
{
	ull start = 0, end = 2147483647;

	while(start < end)
	{
		#define mid ((start+end)/2+1)
		if(check(mid))
			start = mid;
		else
			end = mid-1;

		#undef mid
	}
	return start;
}

int main()
{
	scanf("%d", &T);

	for(int t=1 ; t<=T ; t++)
	{
		scanf("%llu%llu", &r, &want);

		printf("Case #%d: %llu\n", t, bs());
	}
	putchar('\n');
	return 0;
}

