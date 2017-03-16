#include<iostream>
#include<vector>
#include<algorithm>
#include<functional>
#include<math.h>

using namespace std;

int main()
{


	long long T,r,t;
	cin>>T;

	for (int i = 0; i < T; i++)
	{
		cin>>r>>t;
		double a,b,c;
		long long temp;
		a=2;
		b=(2*r)-1;
		c=-t;

		temp=(-b+sqrt( pow(b,2) - (4*a*c) ))/(2*a);

		cout<<"Case #"<<i+1<<": "<<temp<<endl;
	}
	return 0;
}