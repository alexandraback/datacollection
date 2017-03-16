#include <cstdio>

using namespace std;

double compute(double C, double F, double X)
{
	double sec = 0.0;
	double rate = 2.0;
	bool done = false;
	while (!done)
	{
		double nextC = C / rate + C / F;
		double nextX = X / rate;
		if (nextC < nextX) // build another farm
		{
			sec += C / rate;
			rate += F;
		}
		else // thats it
		{
			sec += nextX;
			done = true;
		}
	}
	return sec;
}

int main (int argc, const char * argv[])
{
	freopen(argv[1], "r", stdin);
	if (argc == 3)
		freopen(argv[2], "w", stdout);

	int num_tc;
	scanf("%d\n", &num_tc);
	for (int i = 0; i < num_tc; i++)
	{
		double C, F, X;
		scanf("%lf %lf %lf\n", &C, &F, &X);
		double sec = compute(C, F, X);
		printf("Case #%d: %.7lf\n", i + 1, sec);
	}

	fclose(stdin);
	if (argc == 3)
		fclose(stdout);
	return 0;
}
