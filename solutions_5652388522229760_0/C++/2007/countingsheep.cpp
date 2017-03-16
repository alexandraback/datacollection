#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int pw2[10];
const int ac = (1<<10) - 1;
int done(int n)
{
	int st = 0;
	while(n>0)
	{
		st = st | (pw2[n%10]);
		n/=10;
	}
	return st;
}
int main()
{
	pw2[0] = 1;
	for(int i=1; i<10; i++)
		pw2[i] = 2*pw2[i-1];
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int T,n,seen,tn;
	cin>>T;
	for(int tc = 1; tc <= T; tc++)
	{
		cin>>n;
		cout<<"Case #"<<tc<<": ";
		if(!n)
		{
			cout<<"INSOMNIA\n";
			continue;
		}
		seen = 0;
		tn = 0;
		while(seen!=ac)
		{
			tn+=n;
			seen = seen | done(tn);
		}
		cout<<tn<<"\n";
	}
}