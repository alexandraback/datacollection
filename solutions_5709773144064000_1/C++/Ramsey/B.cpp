#include <cstdlib>
#include <cstdio>
#include <vector>
#include <string>
#include <memory.h>
#include <algorithm>

using namespace std;

const char inFileName[] = "B-large.in";
const char outFileName[] = "B-large.out";

const int MaxN = 200;

int T;
double c, f, x;

int main() {
	
	FILE* inFile = fopen(inFileName, "r");
	FILE* outFile = fopen(outFileName, "w");

	fscanf(inFile, "%d", &T);
	for (int t = 0; t < T; t++) 
	{
		fscanf(inFile, "%lf%lf%lf", &c, &f, &x);

		double opt = x / 2;
		int factNum = 0;
		double currFactPrice = 0.0;
		double curr = opt;

		do
		{
			opt = curr;
			currFactPrice = currFactPrice + c / (factNum * f + 2.0);
			factNum++;
			curr = currFactPrice + x / (factNum * f + 2.0);
		} while (curr < opt);

		fprintf(outFile, "Case #%d: %.8lf\n", t + 1, opt);
	}	
	
	fclose(inFile);
	fclose(outFile);
	return 0;
}
