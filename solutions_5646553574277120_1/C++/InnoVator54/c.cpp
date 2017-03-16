#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <unordered_map>
#include <unordered_set>

using namespace std;


#define ll long long
ll num[110];

int main()
{
	int T;
	int ca = 0;
	freopen("C-large.in", "r", stdin);
	freopen("out.txt", "w", stdout);
	scanf("%d", &T);
	ll c, d, v;
	while(T--)
	{
		scanf("%lld%lld%lld", &c, &d, &v);
		for (int i = 1; i <= d; ++i)
		{
			scanf("%lld", &num[i]);
		}
		ll res = 0;
		long long cur = c;
		if(num[1] != 1)
		{
			res++;
		}
		for (int i = 1; i <= d; ++i)
		{
			while(cur < num[i] - 1)
			{
				cur += (cur + 1) * c;
				//printf("%d %d\n", num[i], cur);
				res++;
			}
			if(num[i] != 1)
				cur += num[i] * c;
			//printf("cur = %d\n", cur);
		}
		while(cur < v)
		{
			cur += (cur + 1) * c;
			res++;
		}
		printf("Case #%d: %lld\n", ++ca, res);
	}
	return 0;
}