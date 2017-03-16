#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include <string>
#include <string.h>
#include <map>
#include <set>
#include <cmath>
#include <queue>

using namespace std;

#define MAX 2000001
#define INF 10000000000000
#define MOD 1000000009
#define CLR(a,x) memset(a,x,sizeof a)
#define ll long long
#define ALL(v) v.begin(),v.end()
#define FR(i,n) for(ll i=0;i<n;i++)
#define FAB(i,a,b) for(ll i=a;i<b;i++)
#define FBA(i,b,a) for(ll i=b;i>=a;i--)
#define IIN(x) scanf("%d",&x)
#define IIN2(x,y) scanf("%d%d",&x,&y)
#define LIN(x) scanf("%I64d",&x)
#define LIN2(x,y) scanf("%I64d%I64d",&x,&y)
#define PII pair<int,int>
#define PI 3.141592653589793238
#define VI vector<int>
#define VLL vector<ll>
#define VS vector<string>
#define SI set<int>
#define SLL set<ll>
#define SS set<string>
#define MII map<int,int>
#define MIV map<int,VI>
#define MSI map<string,int>
#define MIS map<int,string>
#define PLL pair<ll,ll>
#define PIS pair<int,string>

ll v[11],n,res,E;

void back(ll pos,ll e,ll r,ll sum)
{
	if(pos==n)
	{
		res=max(res,sum);
		return;
	}

	FR(i,e+1)
	{
		back(pos+1,min(e-i+r,E),r,sum+(i*v[pos]));
	}
}

int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	ll T; cin>>T;
	FR(q,T)
	{
		cout<<"Case #"<<q+1<<": ";

		ll r,x,sum; cin>>E>>r>>n;
		sum=0;

		if(E<=r)
		{
			FR(i,n)
			{
				cin>>x;
				sum+=x;
			}
			cout<<sum*E<<endl;
			continue;
		}

		FR(i,n)	cin>>v[i];

		res=0;
		back(0,E,r,0);

		cout<<res<<endl;
	}

	return 0;
}