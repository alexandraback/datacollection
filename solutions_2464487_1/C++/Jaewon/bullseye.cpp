#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	int nTests;
	cin>>nTests;
	for(int test=1; test<=nTests; test++) {

		long double r, t;
		cin>>r>>t;

		long double a = 2;
		long double b = 2*r - 1;
		long double c = -t;
		
		long double realNumRing = floor( (-b / (2*a)) + ((sqrt((b*b)-(4*a*c))) / (2*a)) );
		long long nRing = (long long)realNumRing;

		while( 2*(nRing+1)*(nRing+1) + (2*r-1)*(nRing+1) <= t )
			nRing++;

		while( 2*nRing*nRing + (2*r-1)*nRing > t )
			nRing--;

		cout<<"Case #"<<test<<": "<<nRing<<endl;
	}
	return 0;
}