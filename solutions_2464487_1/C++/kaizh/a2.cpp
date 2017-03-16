#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	int T;
	cin>>T;
	for(int tt=1;tt<=T;tt++)
	{
		long long r,t;
		cin>>r>>t;
		long long cur=r+1;
		long long cnt=0;
		long long x=sqrt(2*t-r+1.0*r*r);
		long long ans=0;
		while(x>=0)
		{
			if((x+r)*(x-r+1)<=2*t)
			{
				ans=x;
				break;
			}
			x--;
		}
		if((ans-r)%2==0)ans--;
		if(ans < r)
			cout<<"Case #"<<tt<<": "<<0<<endl;
		else
			cout<<"Case #"<<tt<<": "<<(ans-r+1)/2<<endl;
	}
	return 0;
}
