#include<bits/stdc++.h>
#define ll long long int
#define MOD 1000000007
#define pb push_back
using namespace std;

string ans,s;

int main()
{
	freopen("A-large.in","r",stdin);
	freopen("out1.out","w",stdout);
	ll t;
	scanf("%lld",&t);
	for(ll x=1;x<=t;++x)
	{
		cin>>s;
		ans="";
		for(ll i=0;i<s.length();++i)
		{
			if(i==0)
			ans=s[0];
			else
			{
				if(s[i]<ans[0])
				ans=ans+s[i];
				else
				ans=s[i]+ans;
			}
		}
		printf("Case #%lld: ",x);
		cout<<ans<<endl;
	}
	return 0;
}
