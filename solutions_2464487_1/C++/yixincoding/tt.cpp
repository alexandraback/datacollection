
#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <cmath>
using namespace std;




int main()
{
	freopen("input.in","r",stdin);
	freopen("output.out","w",stdout);
	
	int T;cin>>T;
	for (int qq=1;qq<=T;qq++)
	{
		long long r,t;
		cin>>r>>t;
		int total=0;
		int num=1;
		long long k=0;
		int kk=2*r;
		k=(sqrt((4.0*r*r)+8*(t+0.0)+4)-2*r-2)/4;
		//if (  ((k*4+2*r+3)*(k*4+2*r+3))!=((2*r-1)*(2*r-1)+8*t) ) k++;
		if  ((2*k*k+(2*r+2)*k+2*r)==t)  k++;
		cout << "Case #"<<qq<<": "<<k<<endl;

	//	cout<< sqrt(100000000000000000000000000000000.0) << endl;

	}



	
	return 0;
}