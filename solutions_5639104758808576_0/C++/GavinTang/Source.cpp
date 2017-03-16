#include <iostream>
#include <algorithm>
#include <fstream>

using namespace std;

int get_result(int *a, int num)
{
	int culnum = 0;
	int res = 0;
	for (int i = 0; i < num + 1; i++)
	{
		if (culnum < i)
		{
			res += i - culnum;
			culnum = i + a[i];
		}
		else culnum += a[i];
	}
	return res;
}


int T;

int main()
{
	ifstream ifile;
	ofstream ofile;
	ifile.open("A-small-attempt0.txt");
	ofile.open("output.txt");

	ifile >> T;
	int smax;
	char a;
	int aa[10005];
	int casenum = 0;
	while (casenum < T)
	{
		casenum++;
		ifile >> smax;
		for (int i = 0; i < smax + 1; i++)
		{
			ifile >> a;
			aa[i] = a - '0';
		}
		ofile << "Case #" << casenum << ": " << get_result(aa, smax) << endl;
	}
	return 0;
}