#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <map>
#include <string>
using namespace std;

int main(int argc, char **argv)
{
	FILE *infile, *outfile;

	int cases, A, B;

	double p[100000];
	double min, temp, temp2;

	infile = fopen("A-large.in", "r");
	outfile = fopen("out.txt", "w");
	fscanf(infile, "%d\n", &cases);
	for(int i = 0; i < cases; ++i)
	{
		fscanf(infile, "%d %d\n", &A, &B);
		min = 2000000;
		temp = 1;
		for(int j = 0; j < A; ++j)
		{
			fscanf(infile, "%lf ", p + j);
			p[j] *= temp;
			temp = p[j];
			temp2 = 2 * (A - j - 1) + B - A + 1 + (1 - p[j]) * (B + 1);
			if(temp2 < min)
			{
				min = temp2;
			}
		}
		temp2 = B + 2;
		if(temp2 < min)
			min = temp2;
		fprintf(outfile, "Case #%d: %.6lf\n", i + 1, min);
	}
	
	fclose(infile);
	fclose(outfile);

	return 0;
}