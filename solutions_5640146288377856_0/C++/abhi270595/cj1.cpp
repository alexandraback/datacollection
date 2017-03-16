#include<bits/stdc++.h>

using namespace std;

int main()
{
	int t;
	cin>>t;
	for(int i=1;i<=t;i++)
	{
		int r,c,w;
		cin>>r>>c>>w;
		int ans=0;
		ans+=c/w;
		if(c%w!=0)
			ans++;
		if(w>=2)
			ans+=w-1;
		cout<<"Case #"<<i<<": "<<ans<<endl;
	}
	return 0;
}
