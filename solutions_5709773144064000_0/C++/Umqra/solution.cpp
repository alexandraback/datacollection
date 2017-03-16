#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;
int main()
{
	freopen ("input.txt", "r", stdin);
	freopen ("output.txt", "w", stdout);

	int t;
	scanf("%d", &t);
	for (int i = 0; i < t; i++)
	{
		double c, f, x;
		scanf("%lf%lf%lf", &c, &f, &x);
		double ans = 1e18;
		double curTime = 0;
		double curVel = 2;
		for (int cnt = 0;; cnt++)
		{
			if (curTime > ans)
				break;
			ans = min(ans, curTime + x / curVel);
			curTime += c / curVel;
			curVel += f;
		}
		printf("Case #%d: %.7lf\n", i + 1, ans);
	}

	return 0;
}