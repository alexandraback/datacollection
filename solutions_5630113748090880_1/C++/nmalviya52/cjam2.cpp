#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define mp make_pair
#define pi pair<ll,ll>
#define MOD 1000000007
bool a[2501];
int main()
{
	ll t,n,temp;
	cin>>t;
	ll z=1;
	while(t--)
	{
		cin>>n;
		memset(a,0,sizeof(a));
		for(int i=1;i<2*n;i++)
		{
			for(int j=0;j<n;j++)
			{
				cin>>temp;
				if(a[temp]==false)
				{
					a[temp]=true;
				}
				else
				{
					a[temp]=false;
				}
			}
			
		}
		cout<<"Case #"<<z<<": ";
		for(int i=1;i<=2500;i++)
		{
			if(a[i]==true)
			{
				cout<<i<<" ";
			}
		}
		cout<<endl;
		z++;
	}
	return 0;
}