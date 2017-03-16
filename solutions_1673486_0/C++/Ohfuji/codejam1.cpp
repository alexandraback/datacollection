#include <algorithm>
#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <sstream>
#include <math.h>
#include <string.h>

using namespace std;

double calc(int A, int B, vector<double> prop)
{
	double min = B + 2;
	for ( int i = 0; i < A; i++ ) {
		double p = 1.0;
		for ( int j = 0; j < A - i; j++ ) {
			p *= prop[j];
		}
		
		double exp = p * (B-A+1+i*2) + (1-p)*(B-A+1+i*2+B+1);
		if ( min > exp ) min = exp;
	}

	return min;
}

int main(int argc, char* argv[])
{
	int	casenum;

	cin >> casenum;
	string g;
	for ( int i = 1; i <= casenum; i++ ) {
		int A, B;
		cin >> A >> B;
		vector<double>	prop(A,0);
		for ( int j = 0; j < A; j++ ) {
			cin >> prop[j];
		}
		cout << setprecision(6) << setiosflags(ios::fixed); 
		cout << "Case #" << i << ": " << calc(A, B, prop) << endl;
	}

	return 0;
}

