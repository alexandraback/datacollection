#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <vector>
#include <iterator>
#include <algorithm>
using namespace std;

int main()
{
	ofstream ofile;
	ifstream ifile;

	ofile.open("D-large-practice-out.txt");
	ifile.open("D-large.in");

	long T;


	ifile >> T;
	for (int iT = 1; iT <= T; iT++)
	{
		int K, C, S;
		int total = 0;
		ifile >> K >> C >> S;
		if (C == 1 && S < K)
		{
			ofile << "Case #" << iT << ": IMPOSSIBLE" << endl;
			continue;
		}
		if (C > 1 && S < ceil(1.0f*K / 2))
		{
			ofile << "Case #" << iT << ": IMPOSSIBLE" << endl;
			continue;
		}
		if (C == 1)
		{
			ofile << "Case #" << iT << ":";
			for (int i = 1; i <= K; i++)
				ofile << " " << i;
			ofile << endl;
			continue;
		}
		long long base = pow(K, C - 1);
		long long t = 0;
		ofile << "Case #" << iT << ":";
		for (int i = 1; i <= K; i++)
		{
			if (i % 2 == 1)
			{
				long long tmp = ((i + 1) > K) ? (t + i) : (t + (i + 1));
				ofile << " " << tmp;
				t += 2*base;
			}
		}
		ofile << endl;
	}
	ifile.close();
	ofile.close();
	system("pause");
}