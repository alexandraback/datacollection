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

ll t, len;
string st;
int main() 
{
	freopen("Ainp1.in","r",stdin);
	freopen("out.txt","w",stdout);
	cin>>t;
	F(count,1,t)
	{
		cout<<"Case #"<<count<<": ";
		string ans="";
		cin>>st;
		len=st.length();
		ans=ans+st[0];
		F(i,1,len-1)
		{
			if(st[i]>=ans[0])
				ans=st[i]+ans;
			else
				ans=ans+st[i];
		}
		cout<<ans<<endl;
	}
	return 0;
}