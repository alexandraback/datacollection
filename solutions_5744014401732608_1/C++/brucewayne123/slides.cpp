/*input
1
7 25
*/
#include <bits/stdc++.h>
#include<stdio.h>
using namespace std;
#define pii pair<long long,long long>
#define F(i,a,b) for(ll i = (ll)(a); i <= (ll)(b); i++)
#define RF(i,a,b) for(ll i = (ll)(a); i >= (ll)(b); i--)
#define PI 3.14159265
#define ll long long
#define ff first
#define ss second
#define pb(x) push_back(x)
#define mp(x,y) make_pair(x,y)
#define debug(x) cout << #x << " = " << x << endl
#define INF 1000000009
#define mod 1000000007
ll gr[100][100];
int main() 
{
	std::ios::sync_with_stdio(false);
	freopen("il2.txt","r",stdin);
	freopen("ol2.txt","w",stdout);
	ll t;
	cin>>t;
	F(T,1,t)
	{
		cout<<"Case #"<<T<<": ";
		ll b,m;
		cin>>b>>m;
		ll temp = (1<<(b-2));
		//debug(temp);
		if(m>temp)
		{
			cout<<"IMPOSSIBLE"<<endl;
			continue;
		}
		else
		{
			cout<<"POSSIBLE"<<endl;
			memset(gr,0,sizeof(gr));
			ll ways = log2(m);
			//debug(ways);
			ll ver = ways+1;
			ways = (1<<ways);
			//debug(ways);
			//debug(ver);
			F(i,1,ver)
			{
				F(j,i+1,ver)
				{
					if(i==j)
						continue;
					gr[i][j]=1;
				}
			}
			F(i,1,ver)
			{
				gr[i][b]=1;
			}
			ll rem = m - ways;
			//debug(rem);
			ll c=0;
			vector <ll> v;
			v.clear();
			while(rem>0)
			{
				if(rem%2==1)
					v.pb(c);
				rem = rem/2;
				c++;
			}
			ll sz = v.size();
			F(i,0,sz-1)
			{
				//cout<<v[i]<<" ";
				gr[v[i]+2][ver+1]=1;
			}
			if(sz)
				gr[ver+1][b]=1;
			F(i,1,b)
			{
				F(j,1,b)
				{
					cout<<gr[i][j];
				}
				cout<<endl;
			}
		}
	}
	return 0;
}