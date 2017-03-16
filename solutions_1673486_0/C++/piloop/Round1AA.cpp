#include <iostream>
#include <fstream>
#include <algorithm>
#include <cmath>
#include <vector>

using namespace std;

ifstream fin( "A-small-attempt0.in" );
ofstream fout( "A-small-attempt0.out" );

#define cin fin
#define cout fout

int t;
double p[100000];

int main() {
	cin >> t;
	for( int T = 0; T < t; T++ ) {
		int a, b;
		cin >> a >> b;
		for( int i = 0; i < a; i++ )	cin >> p[i];
		double res = b + 2;
		double cor = 1.;
		for( int i = 0; i < a; i++ ) {
			cor *= p[i];
			int rem = a - i - 1;
			double cur = 2 * rem + b - a + 1 + (1 - cor) * (b + 1);
			res = min( cur, res );
		}
		cout.precision( 7 );
		cout.setf( ios::fixed | ios::showpoint );
		cout << "Case #" << T + 1 << ": " << res << endl;
	}
	return 0;
}
