#include<bits/stdc++.h>

using namespace std;
#define in(n) scanf("%lld",&n)
#define ll long long
#define MOD 1000000007
ll n;
ll tens[] = {1,10,100,1000,10000,100000,1000000,10000000};
long long win()
{
	ll temp = n;
	int dig=0;
	while(temp)
	{
		temp/=10;
		dig++;
	}
	if(dig==0)
		return -1;
	set<int> myset;
	for(ll i=1;i<=10*tens[dig];i++)
	{
		temp = i*n;
		while(temp)
		{
			myset.insert(temp%10);
			temp/=10;
		}
		if(myset.size()==10)
			return i*n;
	}
	return -1;
}

int main()
{
	long long t;
	in(t);
	ll ans;
	for(int i=1;i<=t;i++)
	{
		in(n);
		ans = win();
		if(ans==-1)
			cout<<"Case #"<<i<<": INSOMNIA"<<endl;
		else
			cout<<"Case #"<<i<<": "<<ans<<endl;
	}
}