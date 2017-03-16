#include <stdio.h>
#include <iostream>
#include <cstdlib>
#include <cmath>

using namespace std;

int main()
{
	int cases;
	cin >> cases;
	cout.precision(25);

	for(int i = 0; i < cases; i++)
	{
		long long r; long long t;
		cin >> r;
		cin >> t;
		
		long double r2 = r;
		long double t2 = t;
		
		long double b = 2*r - 1;
		long double c = -t;
		
		long double res = -b + sqrt(b*b - 8*c);
		//long double res = sqrt(4*r2*r2 - 4*r2 + 8*t2 + 1) - 2 * r2 + 1;
		res = floor(res/4);
		
		cout << "Case #" << (i+1) <<  ": " << res << endl;
	}

}
