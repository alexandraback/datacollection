
#include <cstdio>

FILE *file_in = fopen("input.txt", "rt"),
*file_out = fopen("output.txt", "wt");

#include <algorithm>
#include <vector>
#include <set>
#include <stack>
#include <queue>
#include <limits>
#include <functional>
#include <iterator>
using namespace std;

void testCase()
{
	double c, f, x;
	fscanf(file_in, "%lf%lf%lf", &c, &f, &x);

	double farmTime = 0;

	double best = numeric_limits<double>::max();

	for (int farms = 0; farms <= (x / c + 1024); farms++)
	{
		double cps = 2 + farms * f;
		double total = x / cps + farmTime;
		best = min(best, total);
		farmTime += c / cps;
	}

	fprintf(file_out, "%.7lf", best);
}

int main()
{
	int t;
	fscanf(file_in, "%d", &t);

	for (int i = 1; i <= t; i++)
	{
		fprintf(file_out, "Case #%d: ", i);
		testCase();
		fprintf(file_out, "\n");
	}

	return 0;
}
