#include <cstdio>
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
#include <string>
using namespace std;
	//freopen("E:\\ipt.txt", "r", stdin);
#define INF 0x3f3f3f3f
#define LL long long
#define mxn 105
#define mxe 300005

//int fst[mxn], nxt[mxe], to[mxe], sz, f[mxe];
int mp[mxn][mxn];
int cost[mxn];
int N;

string tostr(int x){
	string ret;
	for(; x; x/=10)
		ret+='0'+x%10;
	reverse(ret.begin(), ret.end());
	return ret;
}

struct node{
	int id, val;
	node(){}
	node(int x, int y):id(x), val(y){}
	bool operator<(const node & a) const{
		return a.val>val;
	}
};

string ans;
bool vis[mxn];
void dfs(int u){
	ans.append(tostr(cost[u]));
	vis[u]=1;
	vector<node> buf;
	for(int i=1; i<=N; ++i)
		if(mp[u][i] && !vis[i])
			buf.push_back(node(i, cost[i]));
	sort(buf.begin(), buf.end());
	for(int i=0; i<buf.size(); ++i) if(!vis[buf[i].id]) dfs(buf[i].id);
}

int main(){
	freopen("E:\\C-small-attempt0.in", "r", stdin);
	freopen("E:\\opt.txt", "w", stdout);
	int T, TT=0;
	cin>>T;
	while(++TT<=T){
		int M;
		cin>>N>>M;
		for(int i=1; i<=N; ++i) scanf("%d", cost+i);
		memset(mp, 0, sizeof(mp));
		while(M--){
			int x, y;
			scanf("%d%d", &x, &y);
			mp[x][y]=mp[y][x]=1;
		}
		string mn;
		bool f=0;
		for(int i=1; i<=N; ++i){
			ans.clear();
			memset(vis, 0, sizeof(vis));
			dfs(i);
			if(f && mn>ans) mn=ans; 
			else if(!f) mn=ans, f=1;
		}
		cout<<"Case #"<<TT<<": "<<mn<<endl;
	}
	return 0;
}