#include<bits/stdc++.h>
using namespace std;
//cout<<"Case #"<<i<<": ";
int main()
{
	int t;
	cin>>t;
	for(int ii=1;ii<=t;ii++)
	{
	int a,b,k;
	cin>>a>>b>>k;
	int ans=0;
	for(int i=0;i<a;i++)
	{
		for(int j=0;j<b;j++)
		{
			int pp=i&j;
			if(pp<k)
			{
				ans++;
			}
		}
	}
	cout<<"Case #"<<ii<<": "<<ans<<endl;
	}
	return 0;
}
