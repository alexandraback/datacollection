#include <cstdio>
#include <algorithm>

using namespace std;

int a, n;
int ns[100];

int solve(int ca, int d)
{
	if (d==n)
		return 0;
	
	if (ca == 1)
		return n - d;
	else
	{
		int cnt = 0;
		while (ca<=ns[d])
		{
			ca = 2*ca - 1;
			++cnt;
		}

		int t = cnt + solve(ca + ns[d], d + 1);
		return min(t, n - d);
	}
}

int main()
{
	int t;
	scanf("%d", &t);
	for (int c=1; c<=t; ++c)
	{
		scanf("%d %d", &a, &n);
		for (int i=0; i<n; ++i)
			scanf("%d", &ns[i]);

		sort(ns, ns+n);

		printf("Case #%d: %d\n", c, solve(a, 0));
	}
	
	return 0;
}