#include<bits/stdc++.h>
#define ll long long int
using namespace std;
int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	ll t;
	cin>>t;
	for(int k=1;k<=t;k++)
	{

		ll r, c, w;
		cin>>r>>c>>w;
		ll ans1=0;
		ans1=(r-1)*(c/w);
		ll ans=0;
		if(w==1 || w==c-1 || w==c)
			ans=c;
		else
		{
			if(w>c/2)
			{
				ans=w+1;
			}
			else
			{
				ll tw=w;
				while(1)
				{
					if(tw>=c)
					{
						ans+=w;
						break;
					}
					ans++;
					tw=tw+w;
				}
			}
		}
		cout<<"Case #"<<k<<": "<<ans+ans1<<"\n";
	}
	return 0;
}