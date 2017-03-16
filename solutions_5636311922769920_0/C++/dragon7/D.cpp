#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef vector<int> vi;
typedef pair<int,int> pii;

int main()
{
	int test;
	cin>>test;
	for(int z=1;z<=test;z++)
	{
		ll k, c, s;
		cin>>k>>c>>s;
		cout<<"Case #"<<z<<": ";
		ll x=1;
		for(int i=1;i<c;i++)
			x*=k;
		ll y = 1; 
		for(int i=1;i<=k;i++)
		{
			cout<<y<<" ";
			y+=x;
		}
		cout<<endl;
	}
}
