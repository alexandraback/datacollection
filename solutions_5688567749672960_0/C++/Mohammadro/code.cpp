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
const int inf=1e9;

vi adj[maxn];
int dis[maxn];
bool mark[maxn];
int rev(int x){
	int ret=0;
	while(x){
		ret*=10;
		ret+=(x%10);
		x/=10;
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
		int n;
		cin>>n;
		cout<<"Case #"<<l<<": "<<dis[n]<<endl;
	}
	return 0;
}
