#include<bits/stdc++.h>

#define pb(x) push_back(x);
#define gc getchar_unlocked
#define pc(x) putchar_unlocked(x);
#define inf 1<<30
#define mod 1000000007
#define ll long long   

using namespace std;

typedef pair<int,int> pii;

int abso(int a,int b)
{
	if(a<b)
		return b-a;
	else
		return a-b;
}

ll power(ll x,ll e)
{
	ll temp;
	if(e==0)
		return 1;
	if(e%2==0)
	{
		temp=power(x,e/2);
		return temp*temp;
	}
	else
	{
		temp=power(x,e/2);
		return temp*temp*x;
	}
}

bool cmp(pair<pair<int,int>,int> x,pair<pair<int,int>,int> y)
{
	if(x.first.first==y.first.first)
	{
		if(x.first.second==y.first.second)
			return x.second<y.second;
		else
			return x.first.second>y.first.second;
	}
	return x.first.first>y.first.first;
}

bool cmp1(pii x,pii y)
{
	if(x.second==y.second)
		return x.first<y.first;
	return x.second<y.second;
}

int main()
{
	int t,n,ans,p,temp;
	cin>>t;
	for(int m=1;m<=t;m++)
	{
		cout<<"Case #"<<m<<": ";
		ans=0;
		cin>>n;
		string a,b;
		pair<string,string> arr[n+1];
		int cur = 0;
		vector<int> adj[1005],rev[1005];
		map<string,int> m1,m2;
		for(int i=1;i<=n;i++)
		{
			cin>>a>>b;
			arr[i].first = a;
			arr[i].second = b;
			if(m1[a]==0)
			{
				cur++;
				m1[a]=cur;
			}
		}
		p=cur;
		//cout<<p<<endl;
		int t1,t2;
		for(int i=1;i<=n;i++)
		{
			//cout<<"i "<<i<<endl;
			if(m2[arr[i].second]==0)
			{
				cur++;
				m2[arr[i].second]=cur;
			}
			t1=m1[arr[i].first];
			t2=m2[arr[i].second];
			//cout<<t1<<" "<<t2<<endl;
			adj[t1].pb(t2);
			rev[t2].pb(t1);
		}
		int visit[cur+10];
		memset(visit,0,sizeof visit);
		int flag=0;
		for(int i=1;i<=p;i++)
		{
			if(visit[i]==0)
			{
				flag=0;
				visit[i]=1;
				for(int j=0;j<adj[i].size();j++)
				{
					if(visit[adj[i][j]]==0)
					{
						flag=1;
						visit[adj[i][j]]=1;
						ans++;
						break;
					}
				}
				if(flag==0)
					ans++;
			}
		}		
		for(int i=cur;i>p;i--)
		{
			if(visit[i]==0)
			{
				visit[i]=1;
				ans++;
			}
		}
		cout<<n-ans<<endl;
	}
	return 0;
}
