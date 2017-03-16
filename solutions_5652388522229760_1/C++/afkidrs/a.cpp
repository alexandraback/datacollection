#include <bits/stdc++.h>
#define N 10
#define MAX 100000

using namespace std;
typedef long long ll;
bool seen[N];
int t;
ll n;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin>>t;
	for(int c=1;c<=t;++c)
	{
		fill(seen,seen+N,false);
		int cnt=0;
		cin>>n;
		ll i;
		for(i=0;i<MAX;++i)
		{
			ll a = i*n;
			ll b = a;
			while(b!=0)
			{
				int c = b%10;
				if(!seen[c])
				{
					seen[c]++;
					cnt++;
				}
				b/=10;
			}
			if(cnt==N)
			{
				cout<<"Case #"<<c<<": "<<a<<endl;
				break;
			}
		}
		if(i==MAX && cnt<N)
		{
			cout<<"Case #"<<c<<": INSOMNIA"<<endl;
		}
	}
	return 0;
}