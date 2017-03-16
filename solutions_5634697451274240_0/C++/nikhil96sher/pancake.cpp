#include<bits/stdc++.h>

using namespace std;
#define in(n) scanf("%lld",&n)
#define ll long long
#define MOD 1000000007

string s;

long long win()
{
	if(s.length()==1)
	{
		if(s[0]=='-')
			return 1;
		else
			return 0;
	}
	int group;
	group = 1;
	for(int i=1;i<s.length();i++)
	{
		if(s[i]!=s[i-1])
		{
			group++;
		}
	}
	if(s[s.length()-1]=='+')
		return group-1;
	else
		return group;
}

int main()
{
	long long t;
	in(t);
	ll ans;
	for(int i=1;i<=t;i++)
	{
		cin>>s;
		ans = win();
		cout<<"Case #"<<i<<": "<<ans<<endl;
	}
}