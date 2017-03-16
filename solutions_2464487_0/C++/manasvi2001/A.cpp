#include <bits/stdc++.h>
using namespace std;
#define ll long long int
int main()
{
	int t,u;
	cin>>t;
	u=t;
	while(t--)
	{
		ll r,t1;
		cin>>r>>t1;
		ll i=1,sum=0,ans=0,area;
		while(1)
		{
			area=((r+i)*(r+i))-((r+i-1)*(r+i-1));
			sum+=area;
			if(sum>t1)
				break;
			ans++;
			i+=2;
		}
		cout<<"Case #"<<u-t<<": "<<ans<<endl;
	}
	return 0;
}