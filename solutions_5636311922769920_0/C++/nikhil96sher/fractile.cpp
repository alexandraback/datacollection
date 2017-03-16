#include<bits/stdc++.h>

using namespace std;
#define in(n) scanf("%lld",&n)
#define ll long long
#define MOD 1000000007

ll c,k,s;

long long win()
{
	for(int i=1;i<=s;i++)
		cout<<i<<" ";
	cout<<endl;
}

int main()
{
	long long t;
	in(t);
	ll ans;
	for(int i=1;i<=t;i++)
	{
		in(k);
		in(c);
		in(s);
		cout<<"Case #"<<i<<": ";
		win();
	}
}