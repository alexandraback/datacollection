// 2015q3.cpp : Defines the entry point for the console application.;
//

#include "stdafx.h"
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <functional>
//#include <boost/math/special_functions/sign.hpp>


using namespace std;

string problem(std::ifstream& fin, std::ofstream& ferr) {

	long long B,M;
	
	stringstream res;

	// at most 50 buildings

	char b[64][64];



	fin >> B >> M;
	// no loops allowed so x-> y and y -> x not allowed

	// 2,1 12   3,2 13 123   4,4 14 124 134 1234   5:1+3+2+1  15 125 135 145 1235 1345 1245 12345  = 8    6 16 126 136 146 156 1236 
	// for 4 and 3 routes dont include direct - for -1
	// for -2 ? 

	// number of routes = 2^( B-2) for 4 eliminate 34 (2) 12=2 13=1 14=1 23=1 24=1 34=2, for 5 eliminate (13)   15=1 12=4 13=2 14=1 25=1 23=2 24=1 34=2 35=2
	// for 6; 16 = 1, 26=1 36=2 46=4 56=8   

	//

	if (M > (1 << (B - 2)) ){
		return "IMPOSSIBLE";
	}

	for (int i = 0; i < B; ++i) {
		for (int j = 0; j <= i; j++)
			b[i][j] = '0';
		for (int j = i+1; j < B; j++)
			b[i][j] = '1';
		b[i][B] = 0;
	}

	// eliminate routes 
	long long elim = (1 << (B - 2)) - M;

	long long route = 1;

	for (int i = 1; i; i <<= 1) {
		if (i & elim) {
			b[route][B-1] = '0';

			//	for (int clear = 0; clear <= B; clear++) {
			//		b[clear][route] = '0';
			//	}
		}
			route++;
	}

	res << "POSSIBLE" << endl;

	for (int i = 0; i < B; ++i) {
		res << b[i] << endl;
	}

	return res.str();

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
