#include <bits/stdc++.h>
using namespace std;

void solve(int test)
{
	int r, c, w;
	scanf("%d %d %d", &r, &c, &w);
	int ans = 0, res = 0;
	
	for (int i = 1; i<=c; i++){
		if (i % w == 0) ++ans;
		if (i == c)res = max(res, ans + w - 1);
		else res = max(res, ans + w);
	}
	res += (c / w) * (r-1);
	printf("Case #%d: %d\n", test, res);
}

int main()
{
	int t;
	scanf("%d", &t);
	for (int i = 1; i<=t; i++)
		solve(i);
	return 0;
}