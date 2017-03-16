#include <cstdio>
#include <iostream>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <functional>
using namespace std;

#pragma comment(linker,"/STACK:100000000")

int a[150];

void solve(int T)
{
	int n, m;
	int i;
	scanf("%d%d", &m, &n);
	for (i = 0; i < n; ++i)
		scanf("%d", &a[i]);
	if (m == 1)
	{
		printf("Case #%d: %d\n", T, n);
		return;
	}
	sort(a, a + n);
	int ans = n;
	int cur = 0;
	i = 0;
	while (i < n)
	{
//		cerr << i << endl;
		while (i < n && m > a[i])
		{
			m += a[i];
			i++;
		}
		ans = min(ans, cur + n - i);
		if (i == n)
			break;
		cur++;
		m = 2*m - 1;
	}
	printf("Case #%d: %d\n", T, ans);
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int i, T;
	scanf("%d", &T);
	for (i = 0; i < T; ++i)
		solve(i + 1);
	return 0;
}