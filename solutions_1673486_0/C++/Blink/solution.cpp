#include <vector>
#include <algorithm>
#include <iostream>
#include <cstdio>
#include <string>
#include <cmath>

using namespace std;

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int t;
	cin >> t;
	for (int c = 1; c <= t; ++c)
	{
		int a, b;
		cin >> a >> b;
		vector <double> p(a + 1);
		p[0] = 1;
		for (int i = 1; i <= a; ++i)
		{
			cin >> p[i];
			p[i] *= p[i - 1];
		}
		for (int i = 0; i <= a; ++i)
			p[i] = 1 - p[i];
		double ans = b + 2;
		for (int k = 0; k <= a; ++k)
			ans = min(ans, 2 * k + b - a + 1 + (b + 1) * p[a - k]);
		printf("Case #%d: %lf\n", c, ans);
	}
	return 0;
}