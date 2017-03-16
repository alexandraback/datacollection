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

	ofile.open("A-large-practice-out.txt");
	ifile.open("A-small-attempt0.in");

	long T;


	ifile >> T;
	for (int iT = 1; iT <= T; iT++)
	{
		string s;
		ifile >> s;
		string res;
		res += s[0];
		for (int i = 1; i < s.length(); i++)
		{
			if (res[0]>s[i])
			{
				res = res + s[i];
			}
			else
			{
				res = s[i] + res;
			}

		}
		ofile << "Case #" << iT << ": " << res << endl;
	}
	ifile.close();
	ofile.close();
	system("pause");
}