// 2015q3.cpp : Defines the entry point for the console application.;
//

#include "stdafx.h"
#include <string>
#include <iostream>
#include <sstream>
#include <fstream>
#include <algorithm>
#include <functional>
//#include <boost/math/special_functions/sign.hpp>


using namespace std;

string problem(std::ifstream& fin, std::ofstream& ferr) {

	long N,s;
	int d[2560] , r[64];
	stringstream resultline  ;

	fin >> N;
	memset(d, 0, sizeof(d));
	memset(r, 0, sizeof(r));

	for (int r = 1; r < N*2 ; r++) {
		for (int c = 0; c < N; c++) {
			fin >> s;
			d[s]++;
		}
	}

	int j = 0;
	for (int i = 0; i < 2560; i++) {
		if (d[i] % 2)
			r[j++] = i;
	}
	
	sort(r, r+N);

	for (int i = 0; i < N; i++) {
		resultline << r[i] << ' ';
	}


	return resultline.str();
}

int main()
{
	int T;
	string filename;

	string result;

	cout << "Enter the file prefix" << endl;
	cin >> filename;

	std::ifstream f_in(filename + ".in");
	std::ofstream f_out(filename + ".out");
	std::ofstream f_err(filename + ".err");

	
	if (!f_in) { cerr << "Failed to open input file." << endl; }
	if (!f_out) { cerr << "Failed to open output file." << endl; }
	if (!f_out) { cerr << "Failed to open debug file." << endl; }

	if (f_in && f_out) {

		f_in >> T;

		for (int i = 1; i <= T; i++) {
			result = problem(f_in, f_err);
			cerr << "Case #" << i << ": " << result << endl;
			f_out << "Case #" << i << ": " << result << endl;
		}

		f_in.close();
		f_out.close();
	}
}
