// gcj2010.cpp : Defines the entry point for the console application.
//

#include <stdlib.h>
#include <iostream>
#include <fstream>

double calc(double D, int N, double* times, double* pos, double a) {
	double xx = 0;
	double vv = 0;

	double tprev = times[0];
	double xprev = pos[0];

	for (int i = 0; i < N; i++) {
		double t = times[i];
		double dt = t - tprev;
		double x = pos[i];
		double dx = x - xprev;
		double v = dx / dt;

		double vv0 = vv;
		double xx0 = xx;

		if (i == 0) {
			
		}

		vv = vv + a * dt;
		xx = xx + vv0 * dt + a * dt * dt / 2;

		if (xx > x) {
			vv = v;
			xx = x;

			if (xx >= D) {
				return t - (xx - D) / v;
			}
		}

		if (xx >= D) {
			double bb = vv0;
			double c = 2 * (xx0 - D);
			double delta = bb * bb - a * c;
			double x1 = (-bb + sqrt(delta)) / a;

			// double tt = sqrt((D - xx0) * 2 / a);
			// return tprev + (D - xx0) / v;
			return tprev + x1;
		}

		tprev = t;
		xprev = x;
	}

	if (xx < D) {
		double bb = vv;
		double c = 2 * (xx - D);
		double delta = bb * bb - a * c;
		double x1 = (-bb + sqrt(delta)) / a;
		// return times[N - 1] + sqrt((D - xx) * 2 / a);
		return times[N - 1] + x1;
	}
	else {
		printf("ERROR!");
	}
}

int main(int argc, char* argv[])
{
	// Read input
	FILE* f = fopen("B-small-attempt2.in", "r");
	// FILE* f = fopen("input.txt", "r");
	FILE* fOut = fopen("output.txt", "w");

	unsigned int nCases;
	fscanf(f, "%i", &nCases);
	
	for (unsigned int i = 0; i < nCases; i++) {
		printf("Processing case %i\n", i + 1);

		double D;
		fscanf(f, "%lf", &D);

		int N;
		fscanf(f, "%i", &N);

		int A;
		fscanf(f, "%i", &A);

		// 

		double* times = new double[N];
		double* pos = new double[N];

		for (int j = 0; j < N; j++) {
			fscanf(f, "%lf %lf", &times[j], &pos[j]);
		}

		double* acc = new double[A];
		
		for (int j = 0; j < A; j++) {
			fscanf(f, "%lf", &acc[j]);
		}

		//

		fprintf(fOut, "Case #%i:\n", i + 1);

		for (int j = 0; j < A; j++) {
			double a = acc[j];
			double f = calc(D, N, times, pos, a);
			fprintf(fOut, "%lf\n", f);
		}

		fflush(fOut);
	}

	printf("DONE!");

	getchar();

	fclose(f);
	fclose(fOut);

	return 0;
}

