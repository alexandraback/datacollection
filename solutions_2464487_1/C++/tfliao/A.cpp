#include <iostream>
#include <cmath>
using namespace std;

typedef long long ll ;


long long RR, TT ;

int T, nCase = 1 ;

bool test ( ll N )
{
	long double n = N;
	long double a = 2, b = (2*RR-1);
	return (long double)(TT) - (a*n*n + b*n) + 1 >= 0 ;
	
	// return a*n*n + b*n - 0.1 <= double(TT)+0.1 ;
}

/*
long long solv()
{
	const static double eps = 0.000000001;
	double r = RR, t = TT;
	double a = -2, b = -(2*r-1), c = t;
	double d = b*b-4*a*c ;
	double n = (-b-sqrt(d)+eps)/(2*a) ;
	cout << a << ", " << b << ", " << c << ", " << d << ", " << n << endl;
	
	
	return (long long)(n);
}
*/

ll solv()
{
	ll L = 0, R = TT;
	ll M ;
	while ( L+1<R ) {
		M = (L+R)/2;
		if ( test(M) ) L = M ;
		else R = M;
	}
	return L ;
}

int main()
{
	cin >> T;
	while ( T-- ) {
		cin >> RR >> TT ;
		cout << "Case #" << nCase ++ << ": " << solv() << endl;
	}
	return 0;
}