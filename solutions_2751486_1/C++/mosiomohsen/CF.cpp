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

#define MAX 5000
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
#define PLL pair<ll,ll>
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

string in="aeiou";
vector<PII> v;

ll SUM(ll a,ll b)
{
	return (b*(b+1)/2)-(a*(a-1)/2);
}

int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	int T; cin>>T;
	FR(q,T)
	{
		v.clear();
		cout<<"Case #"<<q+1<<": ";

		string s; cin>>s;
		ll n; cin>>n;

		ll res=0,cnt=0,beg=-1;
		FR(i,s.size())
		{
			if(find(ALL(in),s[i])==in.end())
			{
				if(cnt==0) beg=i;
				cnt++;
			}
			else 
			{
				if(cnt>=n) v.push_back(PII(beg,i-1));
				cnt=0;
			}
		}
		if(find(ALL(in),s[s.size()-1])==in.end() && cnt>=n-1)
			v.push_back(PII(beg,s.size()-1));

		FR(i,v.size())
		{
			ll dif=SUM(s.size()-v[i].second,s.size()-(v[i].first+n-1));
			res+=((v[i].first-i+1)*dif);
		}
		
		cout<<res<<endl;
	}
	
	return 0;
}