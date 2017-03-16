#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
	int t;
	cin >> t;
	cout.precision(7);
	
	for (int tt = 1; tt <= t; ++tt)
	{
		double c, f, x;
		cin >> c >> f >> x;
		double best = x / 2;
		double curT = 0;
		double r = 2;
		while (curT < best)
		{
			curT += c / r;
			r += f;
			if (curT + x / r < best)
				best = curT + x / r;
		}
		
		printf("Case #%d: %.7f\n", tt, best);
	}
	
	return 0;
}
