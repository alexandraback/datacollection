#include<stdio.h>
#include<iostream>
#define FOR(i,x) for(i=1;i<=x;i++)
using namespace std;

int main()
{
	int it,t;
	cin>>t;
	FOR(it,t)
	{
		int r,c,w;
		cin>>r>>c>>w;
		cout<<"Case #"<<it<<": ";
		if(w==1)
		{
			cout<<(r*c)<<endl;
		}
		else if(w==c)
		{
			cout<<((r-1)+c)<<endl;
		}
		else
		{
			int ans;
			ans=(r)*(c/w);
			if(c%w==0)
			{
				ans+=(w-1);
			}
			else
				ans+=w;
			cout<<ans<<endl;
		}
	}
	return 0;
}
