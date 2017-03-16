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

void solve(int T)
{
	double c, f, x;
	scanf("%lf%lf%lf", &c, &f, &x);
	double ans = x/2;
	double cur = 0;
	for (int k = 0; k < 2*x; ++k)
	{
		if (cur + x/(2 + k*f) < ans)
		{
			ans = cur + x/(2 + k*f);
		}
		cur += c/(2 + k*f);
	}
	printf("Case #%d: %.10lf\n", T, ans);
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int T;
	scanf("%d", &T);
	for (int i = 0; i < T; ++i)
		solve(i + 1);
	return 0;
}