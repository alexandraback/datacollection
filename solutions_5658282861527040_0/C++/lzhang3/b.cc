#include <stdio.h>

#include <algorithm>

using namespace std;

void solve()
{
	int a, b, k; scanf("%d%d%d", &a,&b,&k);
	int sum = 0;
	for (int i = 0; i < a; ++i)
		for (int j = 0; j < b; ++j)
			if ((i&j) < k) 
				++sum;
	printf("%d\n", sum);
}

int main(void)
{
	int t; scanf("%d", &t);
	for (int i = 1; i <= t; ++i)
	{
		printf("Case #%d: ", i);
		solve();
	}
}