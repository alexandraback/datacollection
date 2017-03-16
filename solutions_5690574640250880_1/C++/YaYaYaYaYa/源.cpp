#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <list>
#include <queue>
#include <vector>
#include <set>
#include <stack>
using namespace std;

#define PRINT_CASE_NO printf("Case #%d:\n", t + 1)

bool test(stack<int>& s, int max, int sum, int layer, int maxlayer)
{
	if (sum == 0)
		return true;
	if (sum < 2 || layer >= maxlayer)
		return false;
	for (int i = max; i >= 2; --i)
	{
		if (test(s, i, sum - i, layer + 1, maxlayer))
		{
			s.push(i);
			return true;
		}
	}
	return false;
}

int main()
{
	int T;
	scanf("%d", &T);
	for (int t = 0; t < T; ++t)
	{
		int m, r, c;
		scanf("%d%d%d", &r, &c, &m);
		PRINT_CASE_NO;
		bool flag = false;
		stack<int> s;
		if (r == 1)
		{
			if (flag = (c > m))
				s.push(c - m);
		}
		else if (c == 1)
		{
			if (flag = (r > m))
				for (int i = 0; i < r - m; ++i)
					s.push(1);
		}
		else
		{
			for (int i = min((r * c - m) / 2, c); i >= 2; --i)
			{
				while (!s.empty())
					s.pop();
				if (test(s, i, (r * c - m) - 2 * i, 2, r))
				{
					s.push(i);
					s.push(i);
					flag = true;
					break;
				}
			}
		}
		if (flag)
		{
			printf("c");
			for (int i = 0; i < r; ++i)
			{
				if (s.empty())
					for (int j = 0; j < c; ++j)
						printf("*");
				else
				{
					for (int j = (i == 0) ? 1 : 0; j < s.top(); ++j)
						printf(".");
					for (int j = s.top(); j < c; ++j)
						printf("*");
					s.pop();
				}
				printf("\n");
			}
		}
		else if (r * c == m + 1)
		{
			printf("c");
			for (int i = 0; i < r; ++i)
			{
				for (int j = (i == 0) ? 1 : 0; j < c; ++j)
					printf("*");
				printf("\n");
			}
		}
		else
		{
			printf("Impossible\n");
		}
	}
	return 0;
}