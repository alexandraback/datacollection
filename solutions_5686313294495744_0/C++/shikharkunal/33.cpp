#include <bits/stdc++.h>

using namespace std;
typedef long long ll;


struct edge
{
	ll to,cap,rev;
};


vector<edge>graph[3000];
bool visited[3000];
 
void createED(ll src,ll to,ll cap)
{
	graph[src].push_back((edge){to,cap,graph[to].size()});
	graph[to].push_back((edge){src,0,graph[src].size()-1});
}


ll dfs(ll v,ll t,ll f)
{ 
	if(v==t) 
		return f;
	visited[v]=true;
	for(ll i=0;i<graph[v].size();i++)
	{
		edge &e=graph[v][i];
		if(!visited[e.to] && e.cap>0)
		{ 
			ll d=dfs(e.to,t,min(f,e.cap));
			if(d>0) 
			{ 
				e.cap-=d;
				graph[e.to][e.rev].cap+=d;
				return d;
			}
		}
	}
	return 0;
}


ll calculateflow(ll s,ll t)
{ 
	ll ans=0;
	while(1)
	{ 
		for(ll i=0;i<2990;i++)
			visited[i]=false;
		ll temp=dfs(s,t,LLONG_MAX);
		if(temp==0)
		 return ans;
		else ans+=temp;
	}
}

main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	ll t;
	cin>>t;
	for(ll cases=1;cases<=t;cases++)
	{
		for(ll i=0;i<3000;i++)
		 graph[i].clear();
		printf("Case #%lld: ",cases);
		ll ans=0;
		ll step=1;
		ll n;
		string s[1005],t[1005];
		cin>>n;
		map<string,int>L,R;
		for(ll i=0;i<n;i++)
		{
			cin>>s[i]>>t[i];
			L[s[i]]=0;
			R[t[i]]=0;
		}
	
		
		map<string,int>::iterator it;
		for(it=L.begin();it!=L.end();it++)
		{
			createED(2098,step,1);
			it->second=step++;
		}
		ans+=step-1;
		step=1;
		for(it=R.begin();it!=R.end();it++)
		{
			createED(1050+step,2099,1);
			it->second=step++;
		}
		ans+=step-1;
		for(ll i=0;i<n;i++)
			createED(L[s[i]],R[t[i]]+1050,1);
		ans-=calculateflow(2098,2099);
		ans=n-ans;
		printf("%lld\n",ans);
	}
	return 0;
}
