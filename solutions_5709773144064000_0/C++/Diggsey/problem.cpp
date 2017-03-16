#include "stdafx.h"


int _tmain(int argc, _TCHAR* argv[])
{
	ifstream input("problem.in");
	ofstream output("problem.out");

	int t;
	input >> t;

	for (int i = 1; i <= t; ++i) {
		double rate = 2.0, time = 0.0;
		double c, f, x;
		input >> c >> f >> x;

		while (true) {
			double timeToX = x / rate;
			double timeToCX = c / rate;
			double timeToFX = timeToCX + (x / (rate + f));

			if (timeToX < timeToFX) {
				time += timeToX;
				break;
			}

			time += timeToCX;
			rate += f;
		}

		output << "Case #" << i << ": " << fixed << setprecision(7) << time << endl;
	}


	return 0;
}

