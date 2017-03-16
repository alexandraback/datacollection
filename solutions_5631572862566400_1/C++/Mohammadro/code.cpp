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

int n,f[2000],cur,mx;
bool mark[2000],is[2000],valid[2000];
vi adj[2000];

void dfs(int v,int len){
	mx=max(mx,len);
	mark[v]=true;
	valid[v]=true;
	for(int i=0;i<adj[v].size();i++){
		int u=adj[v][i];
		if(!mark[u] && !is[u]){
			dfs(u,len+1);
		}
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin>>t;
	for(int l=1;l<=t;l++){
		memset(f,0,sizeof(f));
		memset(mark,0,sizeof(mark));
		memset(is,0,sizeof(is));
		memset(valid,0,sizeof(valid));
		int ans=0;
		cin>>n;
		for(int i=0;i<2000;i++)adj[i].clear();
		for(int i=0;i<n;i++){
			cin>>f[i];
			f[i]--;
			adj[f[i]].pb(i);
		}
		for(int i=0;i<n;i++){
			memset(mark,0,sizeof(mark));
			int pos=i;
			int cnt=0;
			while(true){
				mark[pos]=true;
				cnt++;
				pos=f[pos];
				if(mark[pos])break;
			}
			if(pos==i){
				ans=max(ans,cnt);
			}
		}
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				if(j==f[i] && i==f[j]){
					is[i]=true;
					is[j]=true;
				}
			}
		}
		cur=0;
		for(int i=0;i<n;i++){
			if(is[i]){
				mx=0;
				memset(mark,0,sizeof(mark));
				dfs(i,1);
				cur+=mx;
			}
		}
		ans=max(ans,cur);
		cout<<"Case #"<<l<<": "<<ans<<endl;
	}
	return 0;
}
