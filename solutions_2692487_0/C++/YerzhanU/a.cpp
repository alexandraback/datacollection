#include <iostream>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <algorithm>

using namespace std;

#define MAXN 101

int A;
int n;
int a[MAXN];

inline int solve()
{
	scanf("%d%d", &A, &n);
	for (int i = 0; i < n; ++i)
		scanf("%d", &a[i]);

	if (A == 1)
		return n;

	sort(a, a + n);

	int ans = n;          
	for (int i = 0, cur = 0; i < n; ++i)
	{
		while(A <= a[i])
		{
			A = A + A - 1;
			++cur;
		}
		A += a[i];
		ans = min(ans, cur + n - 1 - i);
	}
	return ans;
}

int main()
{
	int tt;
	scanf("%d", &tt);
	for (int t = 0; t < tt; ++t)
		printf("Case #%d: %d\n", t + 1, solve());
	return 0;
}
