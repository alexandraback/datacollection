// ProbB.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
using namespace std;

double expected( vector<double> probs, int A, int B, int bs) {
	double probCorr = 1;
	for ( int i = 0; i < A - bs; i++ ) {
		probCorr *= probs[i];
	}
	return ( probCorr * ( 2*bs + (B-A) + 1 ) ) +
		( (1 - probCorr) * ( 2*bs + (B-A) + 2 + B ) );
}

int _tmain(int argc, _TCHAR* argv[])
{
	ifstream fin("A-small-attempt0.in");
	ofstream fout("out.txt");
	int T;
	fin >> T;

	for ( int i = 1; i <= T; i++ ) {
		int A,B;
		fin >> A;
		fin >> B;
		vector<double> probs;
		for ( int j = 0; j < A; j++ ) {
			double p;
			fin >> p;
			probs.push_back( p );
		}

		double min = B + 2;
		for ( int j = 0; j <= A; j++ ) {
			double e = expected( probs, A, B, j);
			if ( e < min ) min = e;
		}
		
		fout << fixed << setprecision(6) << "Case #" << i << ": " << min << endl;
	}

	fout.close();
	fin.close();
	cin.get();
	return 0;
}

