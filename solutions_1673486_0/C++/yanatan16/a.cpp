/*
 * a.cpp
 *
 *  Created on: Apr 27, 2012
 *  	Title: Code Jame 2012 Round 1A Problem A
 *      Author: jon eisen
 */
#include <iostream>
#include <sstream>
#include <string>
#include <iomanip>
#include <cmath>
#include <fstream>
#include <stdint.h>
#include <vector>
#include <map>

using namespace std;

#define FOR(i,n1,n2) for (uint32_t i = (n1); i < (n2); i++)

double solve(istream & in) {
	uint32_t A,B;
	in >> A >> B;
	double p[A];
	in >> p[0];
	FOR(i,1,A) {
		double x;
		in >> x;
		p[i] = x * p[i-1];
	}
	double press_enter = B + 2; // Press Enter
	double all_backspace = A + B + 1; // All backspace
	double best = min(press_enter, all_backspace);
	FOR(n,0,A) {
		double exp = B - A + 2*n + 1 + (1-p[A-n-1]) * (B+1);
		best = min(exp,best);
	}
	return best;
}

int main()
{
	string filebase = "/home/jon/Downloads/A-small-attempt0";
	ifstream i((filebase+".in").c_str(), ifstream::in);
	ofstream o((filebase+".out").c_str(),ofstream::out | ofstream::trunc);
	uint32_t n;
	i >> n;
	cout << n << " Test Cases" << endl;
	FOR(c,1,n+1) {
		stringstream output;
		output << "Case #" << c << ": ";

		// Parse output

		output << fixed << setprecision(6) << solve(i);
		cout << output.str() << endl;
		o << output.str() << endl;
	}
}

