#include <iostream>
#include <iomanip>		// setprecision
#include <fstream>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <algorithm>		// sort, stable_sort
#include <cstdlib>			// atoi, atof, etc.
#include <cmath>			// floor
using namespace std;
typedef unsigned long long ull_int;

double solve(double c, double f, double x)
{	// 
	double t = x/c -1 - 2/f;
	if (t<0)		return x/2.0;
	int k = ceil(t);
	double res = x/( 2.0 + f*k );
	for (int i=0; i<k; i++)
		res += c/( 2.0 + f*i );
	return res;
}


int main()
{
	ifstream infile;
	infile.open("B-large.in");
	ofstream outfile;
	outfile.open("large.out");
	int nCases;
	infile >> nCases;
	infile.ignore(10,'\n');
	for (int t=1; t<=nCases; t++)
	{
		double c, f, x;
		infile >> c >> f >> x;
		infile.ignore(10,'\n');
		
		double res = solve(c, f, x);
		
		cout.precision(7);
		outfile.precision(7);
		outfile << "Case #" << t << ": "  << fixed << res << endl;
		cout << "Case #" << t << ": " << fixed  << res << endl;
	}
	infile.close();
	outfile.close();
	char c;
	cin >> c;
	return 0;
}