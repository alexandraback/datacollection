/*input

*/

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define PII pair<ll, ll>
#define f first
#define s second
#define F(i,a,b) for(ll i = (ll)(a); i <= (ll)(b); i++)
#define RF(i,a,b) for(ll i = (ll)(a); i >= (ll)(b); i--)
#define inf LLONG_MAX
#define mod 1000000007
#define MAXN 100005
#define pb(x) push_back(x)

ll t, n, x;
ll has[2555];
int main() 
{
	freopen("B-large.in","r",stdin);
	freopen("out.txt","w",stdout);
	cin>>t;
	F(count,1,t)
	{
		memset(has,0,sizeof(has));
		cout<<"Case #"<<count<<": ";
		cin>>n;
		F(i,1,2*n-1)
		{
			F(j,1,n)
			{
				cin>>x;
				has[x]++;
			}
		}
		F(i,1,2500)
		{
			if(has[i]%2)
				cout<<i<<" ";
		}
		cout<<endl;
	}
	return 0;
}