#include<bits/stdc++.h>

using namespace std;

int main()
{
	int t;
	cin>>t;
	for(int w=1;w<=t;++w)
	{
		int a,b,k;
		cin>>a>>b>>k;
		int ans=0;
		for(int i=0;i<a;++i)
		{
			for(int j=0;j<b;++j)
			{
				ans+=((i&j)<k)?1:0;
			}
		}
		cout<<"Case #"<<w<<": "<<ans<<endl;
	}
	return 0;
}
