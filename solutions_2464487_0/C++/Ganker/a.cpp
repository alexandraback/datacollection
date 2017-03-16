#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;

ifstream fin( "a.in" , ios::in );
ofstream fout( "ans.out" , ios::out );

int main()
{
	int T;
	int k;
	double r, t;
	long long n;

	fin >> T;
	k = 1;
	while ( k <= T )
	{
		fin >> r >> t;
		n = ( long long )( ( sqrt( 4*r*r - 4*r + 1 + 8*t ) + 1 - 2 * r ) / 4 );
		fout << "Case #" << k++ << ": " << n << endl;
	}
}
