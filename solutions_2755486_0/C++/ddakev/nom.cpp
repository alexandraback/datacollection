#include<iostream>
#include<cstdio>
#include<fstream>
#include<algorithm>
#include<cmath>
#include<cstring>
#include<vector>
#include<queue>
#include<stack>
using namespace std;
long long t,n,d,m,w0,e0,s,dd,dp,ds,used[4001],g[4001];
vector<pair<pair<long long, long long>, pair<long long, long long> > > v;
int main()
{
	freopen("C-small-attempt0.in","r",stdin);
	freopen("C-small-attempt0.out","w",stdout);
	//ifstream cin;
	//ofstream cout;
	//cin.open(".in");
	//cout.open(".out");
	scanf("%lld",&t);
	for(int o=1; o<=t; o++)
	{
	    scanf("%lld",&n);
	    v.clear();
	    for(int i=1; i<=n; i++)
	    {
	        scanf("%lld%lld%lld%lld%lld%lld%lld%lld",&d,&m,&w0,&e0,&s,&dd,&dp,&ds);

	        for(int j=0; j<=m-1; j++)
	        {
	            v.push_back(make_pair(make_pair(d+dd*j,s+j*ds),make_pair(w0*2+j*dp*2+2000,e0*2+j*2*dp+2000)));
	        }
	    }
	    sort(v.begin(),v.end());
	    for(int i=1; i<=4000; i++) used[i]=g[i]=0;
	    int m=v.size();
	    int p=-1;
	    long long ans=0;
	    for(int i=0; i<=m-1; i++)
	    {
	        if(v[i].first.first!=p)
	        {
	            p=v[i].first.first;
	            for(int j=1; j<=4000; j++) used[j]=g[j];
	        }
	        int e=0;
	        for(int j=v[i].second.first; j<=v[i].second.second; j++)
	        {
	            if(v[i].first.second>used[j])
	            {
	                if(e==0) {ans++; e=1;}
	                g[j]=v[i].first.second;
	            }
	        }
	    }
	    printf("Case #%d: %lld\n",o,ans);
	}
	//cin.close();
	//cout.close();
	return 0;
}
