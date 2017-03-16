#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

const int maxn = 10010;

int e, r, n;
int dat[maxn];

void init()
{
	scanf("%d%d%d", &e, &r, &n);
	for (int i = 0; i < n; i++) scanf("%d", &dat[i]);
}

long long work()
{
	long long ans = 0;
	r = min(r, e);
	for (int i = 0; i < n; i++) ans += (long long)r * dat[i];
	sort(dat, dat + n);
	ans += (long long)(e - r) * dat[n - 1];
	return ans;
}

int main()
{
	int t;
	scanf("%d", &t);
	for (int i = 1; i <= t; i++)
	{
		init();
		printf("Case #%d: %lld\n", i, work());
	}
	return 0;
}
