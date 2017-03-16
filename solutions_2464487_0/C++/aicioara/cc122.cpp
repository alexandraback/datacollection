#include <fstream>
#include <iostream>
using namespace std;

ifstream f("A-small-attempt0.in"); ofstream g("A-small-attempt0.out");

int i, j, m, k, x, y, t;
long long n;
double r, p;

int main(){
	f>>t;
	for (i=1; i<=t; i++){
		f>>r>>p;
		double delta = (2*r-1)*(2*r-1)+8*p;
		long long n = (long long) ((1-2*r+sqrt(delta))/2);
		n/=2;
		g<<"Case #"<<i<<": "<<n<<"\n";
	}
}
