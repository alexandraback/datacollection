#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int sum[10000007];
int snum[20];

bool isGood(long long num)
{
	int idx = 0;
	while(num > 0)
	{
		snum[idx++] = (num % 10);
		num /= 10;
	}
	for(int i = 0; i < idx; i++)
		if(snum[i] != snum[idx - i - 1])
			return 0;
	return 1;
}

int main()
{
	freopen("C-large-1.in", "r", stdin);
	freopen("a.out", "w", stdout);

	for(int i = 1; i <= 10000000; i++)
		if(isGood(i) && isGood(1ll * i * i))
			sum[i] = 1;
	for(int i = 1; i <= 10000000; i++)
		sum[i] += sum[i-1];

	int t;
	scanf("%d", &t);

	for(int tt = 0; tt < t; tt++) 
	{
		long long a, b;
		scanf("%lld%lld", &a, &b);

		long long as = sqrt((double)(a + 0.5)), bs = sqrt((double)(b + 0.5));
		if(as * as == a)
			as --;
		int ans = sum[bs] - sum[as];
		printf("Case #%d: %d\n", tt + 1, ans);
	}

	return 0;
}