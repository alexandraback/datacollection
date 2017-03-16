#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main(int argc, char const *argv[])
{
	ll t;
	cin>>t;
	for(int j=1;j<=t;j++)
	{
		ll n;
		cin>>n;
		string s;
		cin>>s;
		ll total=s[0]-48;
		ll ans=0;
		for(int i=1;i<s.length();i++)
		{
			if(i>total && s[i]!='0')
			{
				ans+=(i-total);
				total=i;
			}
			total+=(s[i]-48);
		}
		cout<<"Case #"<<j<<": "<<ans<<endl;
	}
	return 0;
}
