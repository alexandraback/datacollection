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
	ifile.open("B-large.in");

	long T;


	ifile >> T;
	for (int iT = 1; iT <= T; iT++)
	{
		string s;
		ifile >> s;
		int n = s.length();
		int a[101][2];

		a[0][0] = s[0] == '-' ? 0 : 1;
		a[0][1] = s[0] == '+' ? 0 : 1;
		for (int i = 1; i < n; i++)
		{
			a[i][0] = s[i] == '-' ? a[i - 1][0] : a[i - 1][1] + 1;
			a[i][1] = s[i] == '+' ? a[i - 1][1] : a[i - 1][0] + 1;
		}
		ofile << "Case #" << iT << ": " << a[n-1][1] << endl;
	}
	ifile.close();
	ofile.close();
	system("pause");
}