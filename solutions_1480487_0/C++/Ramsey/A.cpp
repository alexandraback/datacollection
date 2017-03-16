#include <cstdlib>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

const char inFileName[] = "A-small.in";
const char outFileName[] = "A-small.out";

const int MaxN = 300;
const double error = 0.00000001;

int T, n, x;
int s[MaxN];
double sol[MaxN];

bool check(int i)
{
	double val = s[i] + x * sol[i];
	double currSum = 1.0 - sol[i];
	for (int j = 0; j < n; j++)
		if (j != i && s[j] < val)
		{
			currSum -= (val - s[j]) / x;
		}
	if (currSum > 0) return false;
	else return true;
}


int main() {
	
	FILE* inFile = fopen(inFileName, "r");
	FILE* outFile = fopen(outFileName, "w");

	fscanf(inFile, "%d", &T);
	for (int t = 0; t < T; t++) 
	{
		fscanf(inFile, "%d", &n);
		for (int i = 0; i < n; i++) fscanf(inFile, "%d", &s[i]);
		x = 0;
		for (int i = 0; i < n; i++) x += s[i];

		for (int i = 0; i < n; i++)
		{
			double low = 0.0, high = 1.0;
			while (high - low > error)
			{
				sol[i] = (low + high) / 2;
				if (check(i))
				{
					high = sol[i];
				}
				else
				{
					low = sol[i];
				}
			}
		}

		fprintf(outFile, "Case #%d: ", t + 1);
		for (int i = 0; i < n - 1; i++)
			fprintf(outFile, "%.7lf ", 100 * sol[i]);
		fprintf(outFile, "%.7lf\n", 100 * sol[n - 1]);
	}
	
	fclose(inFile);
	fclose(outFile);
	return 0;
}
