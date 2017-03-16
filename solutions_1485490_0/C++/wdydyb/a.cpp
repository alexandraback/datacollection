#include<iostream>
#include<vector>
#include<string>
#include<set>
#include<map>
#include<algorithm>
#include<queue>
#include<set>
#define all(c) c.begin(),c.end()
#define pb push_back
#define uni(c) c.erase(unique(all(c)),c.end())
using namespace std;
typedef __int64 ll;
typedef pair<ll,ll> P;
int n,m;
ll d[200][200];
int dfs(int nn,int nm,vector<P> s,vector<P> t){
	ll ret=0;
	ll ans=0;
	if(d[nn][nm]!=-1)
	return d[nn][nm];
	if(s[nn].second==t[nm].second){
		ret+=min(s[nn].first,t[nm].first);
		s[nn].first-=ret;
		t[nm].first-=ret;
	}
	if(nn==n-1&&nm==m-1)
		return ret;
	for(int i=1;i+nn<n;i++){
		ll q=dfs(nn+i,nm,s,t);
		if(ans<q)
		ans=q;
	}
	for(int i=1;i+nm<m;i++){
		ll q=dfs(nn,nm+i,s,t);
		if(ans<q)
		ans=q;
	}
	return d[nn][nm]=ans+ret;
}
int main(){
	int t;
	cin>>t;
	int cnt=1;
	while(t--){
		memset(d,-1,sizeof(d));
		cout<<"Case #"<<cnt++<<": ";
		cin>>n>>m;
		vector<P> s(n);
		vector<P> t(m);
		ll a,b;
		for(int i=0;i<n;i++){
			cin>>a>>b;
			s[i]=P(a,b);
		}
		for(int i=0;i<m;i++){
			cin>>a>>b;
			t[i]=P(a,b);
		}
		
		cout<<dfs(0,0,s,t)<<endl;
	}
	return 0;
}