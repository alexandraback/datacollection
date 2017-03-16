#include<iostream>
#include<string>
#include<cmath>

using namespace std;

int main()
{
	int T;
	cin>>T;
	for(int test=1;test<=T;test++)
	{
		long long int r,t;
		cin>>r>>t;
		long long int ans=(sqrt((2*r-1)*(2*r-1)+8*t)-(2*r-1))/4;
		cout<<"Case #"<<test<<": "<<ans<<endl;
		
		
	}
	return 0;
}
