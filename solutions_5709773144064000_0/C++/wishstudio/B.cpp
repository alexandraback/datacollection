#include <iostream>
#include <vector>
#include <cstdio>
#include <limits>
#include <algorithm>

using namespace std;

int main()
{
	int T;
	cin >> T;
	for (int z = 1; z <= T; z++)
	{
		double C, F, X;
		cin >> C >> F >> X;
		double ans = numeric_limits<double>::max();
		double gen = 2, time = 0;
		for (;;)
		{
			double current = X / gen + time;
			if (current > ans)
				break;
			ans = current;
			time += C / gen;
			gen += F;
		}
		printf("Case #%d: %.8f\n", z, ans);
	}
	return 0;
}
