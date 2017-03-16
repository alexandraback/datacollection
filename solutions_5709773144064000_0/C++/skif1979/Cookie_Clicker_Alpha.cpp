#include <iostream>
#include <string>
#include <fstream>
#include <stdio.h>
#include <stdlib.h>
#include <cmath>       
#include <math.h> 
#include <vector>
#include <algorithm>
#include <iomanip>

using namespace std;

double time_to_get_farm(int farm_number, double C, double F, double X)
{
	double d = 0;
	for (int i = 1; i <= farm_number; i++)
		d += C / (2 + (i-1) * F);
	return d;
}


int main()
{
	FILE *infile;
	if (fopen_s(&infile, "B-small-attempt0.in", "r+"))
	{
		cout << "Error opening input file ";
		return getchar();
	}

	ofstream outfile("6.out", std::ios::out);
	if (outfile.bad())
	{
		cout << "Error opening output file ";
		return getchar();
	}

	int tcNumber;
	fscanf_s(infile, "%i\n", &tcNumber);

	for (int tc = 1; tc <= tcNumber; tc++)
	{
		double C, F, X;
		fscanf_s(infile, "%lf %lf %lf\n", &C, &F, &X );

		int farm_number = floor(X / C - 2 / F);
		if (farm_number < 0) 
			farm_number = 0;
		double time = time_to_get_farm(farm_number, C, F, X) + X / (2 + farm_number*F);
		outfile << "Case #" << tc << ": " << setprecision(15) << showpoint << time << endl;
	}

	//outfile
	outfile.close();
	return getchar();
}
