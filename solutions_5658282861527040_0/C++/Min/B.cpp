// CodeJam 2014
// Autor: Benjamín de la Fuente Ranea

#include "BigIntegerLibrary.hh"

#include <stdarg.h>
#include <stdint.h>
#include <iostream>
#include <fstream>
#include <vector>
#include <set>
#include <algorithm>
#include <functional>
#include <math.h>

using namespace std;

#define FILE_INPUT	"B-small-attempt0"

void main()
{
	freopen(FILE_INPUT".in", "r", stdin);
	freopen(FILE_INPUT".out", "w", stdout);

	int numCases;
	scanf("%d\n", &numCases);
	for (int i = 1; i <= numCases; ++i)
	{
		unsigned A, B, K;
		scanf("%d %d %d\n", &A, &B, &K);

		unsigned count = 0;
		for (unsigned a = 0; a < A; ++a)
		{
			for (unsigned b = 0; b < B; ++b)
			{
				const unsigned and = a & b;
				if (and < K)
					++count;
			}
		}

		printf("Case #%d: %d\n", i, count);
	}
}
