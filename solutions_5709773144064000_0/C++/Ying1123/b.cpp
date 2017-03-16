#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <algorithm>
using namespace std;

int T;
double C, F, X;

void work()
{
	scanf("%lf%lf%lf", &C, &F, &X);
	double speed = 2, time = 0;
	while (1)
	{
		double t1 = X / speed;
		double t2 = C / speed + X / (speed + F);
		if (t2 - t1 > 0.)
		{
			printf("%.7f\n", time + t1);
			return;
		}
		time += C / speed;
		speed += F;
	}
}

int main()
{
	scanf("%d", &T);
	for (int i = 0; i < T; ++i)
	{
		printf("Case #%d: ", i + 1);
		work();
	}
	return 0;
}
