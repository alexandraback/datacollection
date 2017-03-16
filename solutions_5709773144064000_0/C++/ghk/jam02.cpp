#include <cstdio>
#include <string>
#include <cstring>
#include <algorithm>
using namespace std;

string PROG = "B-small-attempt0";
FILE *fin, *fout;

int t, i, j, k;
double c, f, x;
const double v = 2.0;
double result, old_result;

int main()
{
	fin = fopen((PROG + ".in").c_str(), "r");
	fout = fopen((PROG + ".out").c_str(), "w");
	
	fscanf(fin, "%d", &t);
	for (k = 1; k <= t; k++)
	{
		fscanf(fin, "%lf %lf %lf", &c, &f, &x);
		result = x / v;
		double temp = 0, ff = v;
		while (true)
		{
			old_result = result;
			temp += c / ff;
			ff += f;
			result = temp + x / ff;
			if (result > old_result)
				break;
		}
		result = old_result;
		
		fprintf(fout, "Case #%d: %0.7lf\n", k, result);
	}
	return 0;
}