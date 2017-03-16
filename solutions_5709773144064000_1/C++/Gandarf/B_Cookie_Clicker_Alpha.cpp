#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>

using namespace std;

int test, caseNum;
double c, f, x;

int main()
{
	FILE *in = fopen("B-large.in", "r");
	//FILE *in = fopen("input.txt", "r");
	FILE *out = fopen("output.txt", "w");

	caseNum = 1;
	fscanf(in, "%d", &test);
	while(caseNum <= test)
	{
		fscanf(in, "%lf %lf %lf", &c, &f, &x);

		double res = 0.0;
		double p = 2.0;

		if (c >= x)
			res = x/p;
		else {
			while(1) {
				res += (c / p);
				if ((x-c)/p <= x/(p+f)) {
					res += (x-c)/p;
					break;
				}
				else
					p += f;
			}
		}	
		
		fprintf(out, "Case #%d: %.7lf\n", caseNum++, res);
	}

	fcloseall();

	return 0;
}
