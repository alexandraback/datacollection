// gcj2010.cpp : Defines the entry point for the console application.
//

#include <stdlib.h>
#include <iostream>
#include <fstream>

bool test(int N, bool** inh, bool* touched, int c)
{
	for (int i = 0; i < N; i++) {
		if (inh[c][i])
			if (touched[i])
				return true;
			else {
				touched[i] = true;
				if (test(N, inh, touched, i))
					return true;
			}
	}

	return false;
}

int main(int argc, char* argv[])
{
	// Read input
	FILE* f = fopen("A-small-attempt0.in", "r");
	FILE* fOut = fopen("output.txt", "w");

	unsigned int nCases;
	fscanf(f, "%i", &nCases);
	
	for (unsigned int i = 0; i < nCases; i++) {
		printf("Processing case %i\n", i + 1);

		int N;
		fscanf(f, "%i", &N);

		bool** inh = new bool*[N];
		for (int j = 0; j < N; j++) {
			inh[j] = new bool[N];
		}

		for (int j = 0; j < N; j++)
			for (int k = 0; k < N; k++)
				inh[j][k] = false;

		for (unsigned int j = 0; j < N; j++) {
			int m;
			fscanf(f, "%i", &m);
			for (int k = 0; k < m; k++) {
				int c;
				fscanf(f, "%i", &c);
				inh[j][c - 1] = true;
			}
		}

		/*
		for (int j = 0; j < N; j++) {
			for (int k = 0; k < N; k++) {
				printf("%i ", inh[j][k] ? 1 : 0);
			}

			printf("\n");
		}
		*/

		bool yes = false;
		for (int j = 0; j < N; j++) {
			bool* touched = new bool[N];
			for (int k = 0; k < N; k++)
				touched[k] = false;

			if (test(N, inh, touched, j)) {
				yes = true;
				break;
			}
		}

		fprintf(fOut, "Case #%i: %s\n", i + 1, yes ? "Yes" : "No");

		fflush(fOut);
	}

	printf("DONE!");

	getchar();

	fclose(f);
	fclose(fOut);

	return 0;
}

