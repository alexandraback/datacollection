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

	ofile.open("B-large-practice-out.txt");
	ifile.open("B-small-attempt0.in");

	long T;


	ifile >> T;
	for (int iT = 1; iT <= T; iT++)
	{
		int n;
		ifile >> n;
		int a[2501];
		for (int i = 0; i < 2501; i++) a[i] = 0;
		for (int i = 1; i <= 2 * n - 1; i++)
		{
			for (int j = 0; j < n; j++)
			{
				int t;
				ifile >> t;
				a[t]++;
			}
			
		}
		ofile << "Case #" << iT << ":";
		for (int i = 0; i < 2501; i++)
		{
			if (a[i] % 2 == 1) ofile << ' ' << i;
		}
		ofile << endl;

	}
	ifile.close();
	ofile.close();
	system("pause");
}