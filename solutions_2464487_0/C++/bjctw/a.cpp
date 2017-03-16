//=====================7=======================================================
// Name        : jam_test.cpp
// Author      :
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <fstream>
//#include <sstream>
//#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <stdarg.h>
#include <gmpxx.h>

using namespace std;


int main(int argc, char** argv)
{
	if(argc!=3)
	{
		cout << "Usage:" << endl;
		cout << "jam_test infile outfile" << endl;
		return 0;
	}

	ifstream infile(argv[1]);
	ofstream outfile(argv[2]);

	if(!infile)
		cout << "Input file open error!" << endl;

	if(!outfile)
		cout << "Output file open error!" << endl;

	int nCase;

	int i,j;
	string sr,st;
	int count;


	infile >> nCase ;
	cout << "Case Num:" << nCase << endl;

	for(int iCase=0; iCase<nCase; iCase++)
	{
		cout << "Case #" << iCase+1 << ": ";
		outfile << "Case #" << iCase+1 << ": ";

		infile >> sr;
		infile >> st;

		mpz_class r(sr);
		mpz_class t(st);
		mpz_class result(1);
		mpz_class tryvalue(0);
		mpz_class l(1);
		mpz_class u(t);

		while(l<u-1)
		{
			tryvalue = (l+u)/2;
			tryvalue = 2*r*tryvalue+tryvalue*(2*tryvalue-1);
			if(tryvalue > t)
				u = (l+u)/2;
			else
				l = (l+u)/2;
			result = l;
			//cout << "l:" << l << " u:" << u << endl;
		}

		//cout << "\n    " << r << "\n*\n    " << t;
		//cout << "\n--------------------\n" << r * t << "\n\n";

		outfile << result << endl;
		cout << result << endl;
		//outfile << endl;

	}

	return 0;
}
