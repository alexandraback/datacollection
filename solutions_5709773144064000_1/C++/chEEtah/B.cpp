#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cctype>
#include <cmath>
#include <cassert>
#include <sstream>
#include <functional>
#include <algorithm>
#include <map>
#include <string>
#include <vector>
#include <set>
#include <queue>

using namespace std;

int nt;
double farmCost, farmRate, goal, rate;

int main()
{
	int nt;
	scanf("%d", &nt);
	for(int tt = 1; tt <= nt; tt++)
	{
		fprintf(stderr, "test = %d\n", tt);
		printf("Case #%d: ", tt);
		
		scanf("%lf %lf %lf", &farmCost, &farmRate, &goal);
		rate = 2.0;

		double best = goal / rate;
		double t = 0.0;

		int farms = 0;

		while(farms * farmCost < goal)
		{
			t += farmCost / rate;
			rate += farmRate;
			farms++;
			best = min(best, t + goal / rate);
		}
		
		printf("%.7lf\n", best);
	}
	return 0;
}