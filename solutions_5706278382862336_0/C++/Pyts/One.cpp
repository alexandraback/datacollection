#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <stdio.h>
#include <iomanip>
#include <string>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <vector>
#include <cmath>
#include <set>

#define _CRT_SECURE_NO_WARNINGS
#define ll long long int

using namespace std;
// Code from www.rno.pl/nwd
long long int nwd(long long int a, long long int b) { return (b ? nwd(b, a%b) : a); }

int main()
{
	ifstream input ("input1.in");
	ofstream output ("answers1.txt");
	int t;
	input >> t;
	for( int k = 1; k <= t; ++k )
	{
		long long int P, Q;
		char c;
		int gen = 0;
		input >> P;
		input >> c;
		input >> Q;
		long long int nwdPQ = nwd(P,Q);
		P = P/nwdPQ;
		Q = Q/nwdPQ;
		bool pow = ( (Q & (Q - 1)) == 0 );
		if( !pow )
		{
			output << "Case #" << k << ": " << "impossible\n";
			continue;
		}
		while( Q > P )
		{
			Q = Q >> 1;
			++gen;
		}
		output << "Case #" << k << ": " << gen << endl;
	}
	input.close();
	output.close();
}
