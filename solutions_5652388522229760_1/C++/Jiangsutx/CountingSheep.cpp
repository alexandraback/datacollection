#include <iostream>
#include <fstream>
#include <iomanip>
#include <set>
#include <vector>
#include <iterator>
#include <algorithm>
using namespace std;

long add_n( long s, long x )
{
	while (x > 0)
	{
		s = s | (1 << (x % 10));
		x = x / 10;
	}
	return s;
}

int main()
{
	ofstream ofile;
	ifstream ifile;

	ofile.open("A-large-practice-out.txt");
	ifile.open("A-large.in");
	//ifile.open("B-small.txt");	

	long T;
	long N;
	

	ifile >> T;
	for (int iT = 1; iT <= T; iT++)
	{
		ifile >> N;
		long s = 0;
		long long lx = 0;
		//for (int i = 1; i <= 50; i++)
		int i = 0;
		if (N == 0)
		{
			ofile << "Case #" << iT << ": INSOMNIA" << endl;
			continue;
		}
		while (s != 1023)
		{
			i++;
			s = add_n(s, N*i);
			if (s == 1023)
			{
				lx = N*i;
				break;
			}
		}
		ofile << "Case #"<<iT<< ": "<< lx << endl;
	}
	ifile.close();
	ofile.close();
	system("pause");
}