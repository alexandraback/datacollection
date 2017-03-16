#include <cstdio>
#include <algorithm>

using namespace std;

#define MAX 1000000

int v[MAX];
int n;

int f(int i, int c)
{
	if (i == n)
		return 0;
	else if (v[i] < c)
	{
		c += v[i];
		return f(i + 1, c);
	}
	else
	{
		if (c + c - 1 != c)
			return 1 + min(f(i, c + c - 1), f(i + 1, c));
		else
			return 1 + f(i + 1, c);
	}
}

int main()
{
	int t;
	scanf("%d", &t);
	for (int i = 0; i < t; ++i)
	{
		int a;
		scanf("%d", &a);
			
		scanf("%d", &n);
		for (int j = 0; j < n; ++j)
		{
			scanf("%d", &v[j]);
		}
		
		sort(v, v + n);
		
		printf("Case #%d: %d\n", i + 1, f(0, a));
	}
	
	return 0;
}
