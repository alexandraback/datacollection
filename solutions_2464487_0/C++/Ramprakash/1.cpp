#include<fstream>
#include<iostream>
using namespace std;
#include<math.h>
int main()
{
	unsigned long long int t,k,r,p;
	ifstream f("1.in");
	ofstream g("1.out");
	f>>t;
	for(k=1;k<=t;k++)
	{
		f>>r>>p;
		unsigned long long int q=(2*r)-1;
		unsigned long long int ans=(sqrt((q*q)+(8*p))-q)/4;
		g<<"Case #"<<k<<": "<<ans<<endl;
	}
	return 0;
}
