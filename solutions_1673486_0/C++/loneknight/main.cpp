#include <iostream>
#include <algorithm>
#include <cstdio>

using namespace std;

const int BufferSize = 1000000;

int a, b;
double prob[BufferSize];

int main(int argc, char *argv[])
{
	int t;
	scanf("%d", &t);

	for (int index = 1; index <= t; ++index)
	{
		scanf("%d %d", &a, &b);
		for (int i = 0; i < a; ++i)
			scanf("%lf", &prob[i]);

		double minimum = b + 2;
		for (int i = 0; i < a; ++i)
		{
			double p = 1;
			for (int j = 0; j < a - i; ++j)
				p *= prob[j];

			double expected = p * (i + b - a + i + 1) + (1-p) * (i + b - a + i + 1 + b + 1);
			if (expected < minimum)
				minimum = expected;
		}

		printf("Case #%d: %.6f\n", index, minimum);
	}

	return 0;
}

