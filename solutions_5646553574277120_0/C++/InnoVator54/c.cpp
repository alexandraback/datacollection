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

int num[110];

int main()
{
	int T;
	int ca = 0;
	freopen("C-small-attempt0.in", "r", stdin);
	freopen("out.txt", "w", stdout);
	scanf("%d", &T);
	int c, d, v;
	while(T--)
	{
		scanf("%d%d%d", &c, &d, &v);
		for (int i = 1; i <= d; ++i)
		{
			scanf("%d", &num[i]);
		}
		int res = 0;
		int cur = 1;
		if(num[1] != 1)
		{
			res++;
		}
		for (int i = 1; i <= d; ++i)
		{
			while(cur < num[i] - 1)
			{
				cur += cur + 1;
				//printf("%d %d\n", num[i], cur);
				res++;
			}
			if(num[i] != 1)
				cur += num[i];
			//printf("cur = %d\n", cur);
		}
		while(cur < v)
		{
			cur += cur + 1;
			res++;
		}
		printf("Case #%d: %d\n", ++ca, res);
	}
	return 0;
}