
#include <iostream>
#include <iomanip>

using namespace std;

double solve( double c, double f, double x )
{
	double t = 0;
	double v = 2;
	double best = x / v;
	double sol;
	while ( true ) {
		t += c / v;
		v += f;
		sol = t + x / v;
		if ( sol > best )
			break;
		best = sol;
	}
	return best;
}

int main()
{
	int T;
	cin >> T;
	for ( int t = 1; t <= T; ++t ) {
		double c, f, x;
		cin >> c >> f >> x;
		cout << "Case #" << t << ": " << setiosflags( ios::fixed | ios::showpoint ) << 
			setprecision( 7 ) << solve( c, f, x ) << endl;
	}
	return 0;
}
