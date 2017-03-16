#include<iostream>
#include<fstream>
#include<algorithm>
#include<vector>
#include<cmath>
using namespace std;

int main()
{
	int T;
	ofstream outfile("D:\\codejam\\2015\\Bsmall.txt");
	ifstream infile("D:\\codejam\\2015\\testcase.txt");
	
	infile >> T;

	for (int casenum = 1; casenum <= T; casenum++)
	{
		int D;
		int P;
		int t_optimal;		// shortest time;
		int specialm = 0;
		int h;
		vector<int> pancake;
		
		infile >> D;
		for (int i = 0; i < D; i++)
		{
			infile >> P;
			pancake.push_back(P);
		}
		sort(pancake.begin(), pancake.end());
		int maxelm = pancake[D - 1];
		t_optimal = maxelm;

		for (h = 2; h < maxelm; h++)
		{
			specialm = 0;
			for (int j = 0; j < D; j++)
			{
				if (pancake[j] > h)
					specialm += ((int)ceil(pancake[j] * 1.0 / h) - 1);
			}
			t_optimal = min(t_optimal, h + specialm);
		}

		outfile << "Case #" << casenum << ": " << t_optimal << endl;

	}
	infile.close();
	outfile.close();
	
	return 0;
}