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

vector <double> getRow(int N, FILE *infile)
{
	double d;
	vector <double> v;

	for (int i = 0; i < N; i++)
	{
		fscanf_s(infile, "%lf", &d);
			v.push_back(d);
	}
	sort(v.begin(), v.end());
	return v;
}

int main()
{
	FILE *infile;
	if (fopen_s(&infile, "D-large.in", "r+"))
	{
		cout << "Error opening input file ";
		return getchar();
	}

	ofstream outfile("8.out", std::ios::out);
	if (outfile.bad())
	{
		cout << "Error opening output file ";
		return getchar();
	}

	int tcNumber;
	fscanf_s(infile, "%i\n", &tcNumber);

	for (int tc = 1; tc <= tcNumber; tc++)
	{
		int N;
		fscanf_s(infile, "%i\n", &N);

		vector <double> naomi = getRow(N, infile);
		vector <double> ken = getRow(N, infile);
		int y = 0, z = 0;

		// z is the number of points Naomi will score if she plays War optimally
		int curKen = 0;
		int kenGain = 0;
		for (int i = 0; i < N; i++)
		{
			for (int j = curKen; j < N; j++)
			{
				curKen++;
				if (ken[j] > naomi[i])
				{
					kenGain++;
					break;
				}
			}
		}
		z = N - kenGain;

		//  y is the number of points Naomi will score if she plays Deceitful War optimally
		int maxNaomiIdx = N - 1;
		kenGain = 0;
		for (int i = N-1; i >= 0; i--)		// cycle by ken
		{
			if (ken[i] > naomi[maxNaomiIdx])
			{
				// ken wins
				kenGain++;
			}
			else
			{
				// naomi wins
				maxNaomiIdx--;
			}
		}
		y = N - kenGain;

		outfile << "Case #" << tc << ": " << y << " " << z << endl;
		cout << "Case #" << tc << ": " << y << " " << z << endl;
	}

	outfile.close();
	return getchar();
}
