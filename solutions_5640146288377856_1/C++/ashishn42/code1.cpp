#include <bits/stdc++.h>
using namespace std;

int main() 
{
	int t,j=1;
	cin>>t;
	while(t--)
	{
		int r,c,w,ans;
		cin>>r>>c>>w;
		ans=c/w;
		ans*=r;
		ans+=w;
		if(c%w==0)
			ans--;
		cout<<"Case #"<<j++<<": "<<ans<<endl;
	}
	return 0;
}