#include <iostream>
#include <string>
#include <queue>
#include <stack>
#include <algorithm>
#include <cstdio>
#include <map>
#include <set>
#include <vector>
#include <cctype>
#include <sstream>
#include <cstring>
#include <list>
using namespace std;
#define oo (1<<31-1)
#define INFI (1e31)
#define ll long long
#define ull unsigned long long
#define PB(x) push_back(x)
#define ALL(x) (x).begin(),(x).end()
#define REP(i,l) for(int i=0;i<l;i++)
#define FOR(i,a,b) for(int i=a;i<b;i++)
bool solve();
bool DFS(int);
vector<vector<int> > G;
vector<bool> V;
vector<bool> vis;
int n;
int main(){
	int T;
	cin>>T;
	vector<int> v;
	for(int i=1;i<=T;i++){
		cin>>n;
		G.clear();
		G.resize(n+1,v);
		bool t=solve();
		printf("Case #%d: %s\n",i,t?"Yes":"No");
	}
return 0;}
bool solve(){
	for(int i=1;i<=n;i++){
		int q;
		cin>>q;
		for(int j=0;j<q;j++){
			int temp;
			scanf("%d",&temp);
			G[i].PB(temp);
		}
	}
	
	for(int i=1;i<=n;i++){

		vis.clear();
		vis.resize(n+1,false);
		if(DFS(i)) return true;
	}
	return false;
	
}
bool DFS(int x){
	vis[x]=true;
	for(int j=0,y;j<G[x].size();j++){
		y=G[x][j];
		if(vis[y]) {return true;}
		else if(DFS(y)){return true;}
	}
	return false;
}
