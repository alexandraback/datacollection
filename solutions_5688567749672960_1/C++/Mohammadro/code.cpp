#include<iostream>
#include<cstdio>
#include<sstream>
#include<fstream>
#include<cctype>
#include<cstdlib>
#include<cmath>
#include<ctime>
#include<cstring>
#include<string>
#include<complex>
#include<bitset>
#include<map>
#include<set>
#include<vector>
#include<algorithm>
#include<queue>
#include<deque>
#include<stack>
#include<iomanip>
#include<utility>

#define pb push_back
#define pp pop_back
#define xx first
#define yy second
#define mp make_pair

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pii;

const int maxn=1000000+10;
const ll inf=1e9;

vi adj[maxn];
ll dis[maxn];
bool mark[maxn];
ll rev(ll x){
	ll ret=0;
	while(x){
		ret*=(ll)10;
		ret+=(x%(ll)10);
		x/=(ll)10;
	}
	return ret;
}
void bfs(){
	mark[1]=true;
	vi Q;
	Q.pb(1);
	dis[1]=1;
	for(int i=0;i<Q.size();i++){
		int u=Q[i];
		for(int j=0;j<adj[u].size();j++){
			int v=adj[u][j];
			if(!mark[v]){
				dis[v]=dis[u]+1;
				mark[v]=true;
				Q.pb(v);
			}
		}
	}
}
ll get(ll x){
	ll ret=0;
	while(x>1e4){
		ll cur=x;
		vi v;
		while(cur){
			v.pb(cur%(ll)10);
			cur/=10;
		}
		bool ok=false;
		int pos=v.size()/2;
		for(int i=0;i<pos;i++)if(v[i]!=0)ok=true;
		if(!ok){
			x--;
			ret++;
		}
		v.clear();
		cur=x;
		while(cur){
			v.pb(cur%(ll)10);
			cur/=10;
		}
		v[0]=1;
		pos=v.size()/2;
		for(int i=1;i<pos;i++)v[i]=0;
		ll nw=0;
		for(int i=v.size()-1;i>=0;i--){
			nw*=(ll)10;
			nw+=(ll)v[i];
		}
		ll num=0;
		for(int i=1;i<v.size();i++){
			num*=(ll)10;
			num+=(ll)9;
		}
		ret+=(x-nw+1);
		x=rev(nw);
		if(x==nw)ret--;
		ret+=(x-num);
		x=num;
	}
	return dis[x]+ret;
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	for(int i=1;i<=1000000;i++){
		adj[i].pb(i+1);
		adj[i].pb(rev(i));
	}
	bfs();
	int t;
	cin>>t;
	for(int l=1;l<=t;l++){
		ll n;
		cin>>n;
		cout<<"Case #"<<l<<": "<<get(n)<<endl;
	}
	return 0;
}
