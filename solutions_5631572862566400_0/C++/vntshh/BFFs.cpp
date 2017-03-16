//Author: Vineet Shah
//IIT Indore
#include<bits/stdc++.h>
#define rep(i,start,lim) for(long long i=start;i<lim;i++)
#define repd(i,start,lim) for(long long i=start;i>=lim;i--)
#define MOD 1000000007
#define scan(x) scanf("%lld",&x)
#define print(x) printf("%lld",x)
#define sz(a) int((a).size())
#define pb push_back
#define mp make_pair
#define all(c) (c).begin(),(c).end()
#define present(c,x) ((c).find(x) != (c).end())
#define cpresent(c,x) (find(all(c),x) != (c).end())
#define br printf("\n")
#define bit(x,i) (x&(1<<i))
using namespace std;
typedef long long lld;
lld sta,a[1005],vis[1005],bhai;
pair<lld,lld> p1[1005];
map<lld,vector<lld> > m;
lld cnt,cnt2;
vector<pair<lld,lld> > v;
lld dfs(lld cur)
{
	if(vis[cur]==1 && cur==sta) return cnt;
	else if(vis[cur]==1) return -1;
	else
	{
		vis[cur]=1;
		cnt++;
		return dfs(p1[cur].second);
	}
}
lld doosra(lld cur)
{
	if(m[cur].size()==0) return 1;
	else
	{
		lld tmp=0;
		rep(i,0,m[cur].size())
		{
			if(m[cur][i]!=bhai)
				tmp=max(tmp,doosra(m[cur][i]));
		}
		return 1+tmp;
	}
}
int main()
{
	freopen("1245.in","r",stdin);
	freopen("1245.out","w",stdout);
	lld t,ans,n,stop1,tmp;
	cin>>t;
	rep(ttt,1,t+1)
	{
		m.clear();
		bool flag=false;
		ans=-1;
		cin>>n;
		rep(i,1,n+1)
		{
			cin>>a[i];
			p1[i]=mp(i,a[i]);
			m[a[i]].pb(i);
		}
		v.clear();
		rep(i,1,n+1)
			if(p1[i].first==p1[p1[i].second].second && p1[i].first<p1[i].second) v.pb(mp(p1[i].first,p1[i].second));
		rep(i,1,n+1)
		{
			rep(j,1,1005) vis[j]=0;
			sta=i;
			cnt=0;
			ans=max(ans,dfs(i));
			if(ans==n)
				break;
		}
	//	cout<<"Size:"<<v.size()<<endl;
		rep(i,0,v.size())
		{
			cnt2=0,bhai=v[i].second;
			lld ans1=doosra(v[i].first);
			cnt2=0,bhai=v[i].first;
			lld ans2=doosra(v[i].second);
			ans=max(ans1+ans2,ans);
			//cout<<ans1<<" "<<ans2<<" "<<ans<<endl;
		}
		printf("Case #%lld: %lld\n",ttt,ans);
	}

	return 0;
}


