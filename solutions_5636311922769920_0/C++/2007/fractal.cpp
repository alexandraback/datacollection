#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll mpow(int k,int c)
{
	ll st = 1;
	for(int i=1; i<=c; i++)
		st = st*k;
	return st;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int T,c,k,s;
	cin>>T;
	for(int tc = 1; tc <= T; tc++)
	{
		cin>>k>>c>>s;
		cout<<"Case #"<<tc<<": ";
		if(k==1)
		{
			cout<<"1\n";
			continue;
		}
		ll step = (mpow(k,c) - 1) / (k-1), st = 1;
		for(int i=0; i<k; i++)
		{
			cout<<st<<" ";
			st+=step;
		}
		cout<<"\n";
	}
}