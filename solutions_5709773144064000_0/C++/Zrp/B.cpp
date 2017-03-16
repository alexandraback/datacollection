#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
#include <cmath>
#include <vector>
#include <map>
#include <set>
#include <cstring>
#define N 120001
#define oo 1000000000
#define eps 1e-7
using namespace std;
int main()
{
	int tot;
	freopen("B.in", "r", stdin);
	freopen("B.out", "w", stdout);
	scanf("%d", &tot);
	for (int tt = 1; tt <= tot; tt++)
	{
		double now = 0, ans = oo, pre = 2;
		double c, f, x;
		scanf("%lf%lf%lf", &c, &f, &x);
		for (int i = 0; i <= x; i++)
		{
			if (now > ans) break;
			double v = x / pre;
			if (now + v < ans) ans = now + v;
			now += c / pre;
			pre += f;
		}
		printf("Case #%d: %.7lf\n", tt, ans);
	}
	return 0;
}
