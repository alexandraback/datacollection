// CodeJam 2013
// Autor: Benjamín de la Fuente Ranea

#include <stdarg.h>
#include <iostream>
#include <fstream>
#include <vector>
#include <set>
#include <algorithm>
#include <math.h>

using namespace std;

#include "BigIntegerLibrary.hh"

#define FILE_INPUT	"A-large"

void main()
{
	freopen(FILE_INPUT".in", "r", stdin);
	freopen(FILE_INPUT".out", "w", stdout);

	int numCases;
	scanf("%d\n", &numCases);
	for (int i = 1; i <= numCases; ++i)
	{
		double cookiesPerSecond = 2;
		double C, F, X;
		scanf("%lf %lf %lf\n", &C, &F, &X);

		double accum = 0;
		double totalTime = 0;
		do {
			const double targetTime = X / cookiesPerSecond;
			totalTime = accum + targetTime;
			const double farmTime = C / cookiesPerSecond;
			const double otherWayTime = accum + farmTime + X / (cookiesPerSecond + F);
			if (otherWayTime < totalTime)
			{
				accum += farmTime;
				cookiesPerSecond += F;
			}
			else
				break;
		} while(true);

		printf("Case #%d: %.7f\n", i, totalTime);
	}
}
