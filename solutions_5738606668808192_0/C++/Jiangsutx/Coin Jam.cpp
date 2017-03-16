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

	ofile.open("C-large-practice-out.txt");
	ifile.open("C-small-attempt0.in");

	long T;


	ifile >> T;
	for (int iT = 1; iT <= T; iT++)
	{
		int N, J;
		ifile >> N >> J;
		ofile << "Case #" << iT << ": " << endl;
		for (int i = 0; i < J; i++)
		{
			ofile << "1";
			for (int j = 1; j < N-1; j++)
			{
				ofile << ((i >> ((j - 1)/2)) % 2);
			}
			ofile << "1";
			for (int j = 2; j <= 10; j++)
				ofile << " " << ((j % 2 == 0) ? (j + 1) : 2);
			ofile << endl;
		}
	}
	ifile.close();
	ofile.close();
	system("pause");
}