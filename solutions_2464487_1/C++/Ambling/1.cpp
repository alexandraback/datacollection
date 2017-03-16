#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int main(int argc, char const *argv[])
{
	int T;
	cin>>T;

	for (int i = 0; i < T; ++i)
	{
		double r ,t;
		cin>>r>>t;

		double a = 2;
		double b = 2*r-1;
		double c = -t;

		long n = floor((sqrt(b*b - 4 * a *c)-b)/2/a);
		while(2.0*n*n+(2.0*r-1)*n-t > 0) n--;

		cout<<"Case #"<<i+1<<": "<<n<<endl;
	}
	return 0;
}