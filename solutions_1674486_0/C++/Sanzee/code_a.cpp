// Author : Muhammad Rifayat Samee
// Problem : 
// Algorithm:
#pragma warning (disable : 4786)
#pragma comment(linker, "/STACK:16777216")

#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstdlib>
#include<cctype>
#include<cstring>
#include<algorithm>
#include<string>
#include<set>
#include<vector>
#include<map>
#include<queue>
#include<stack>
#define MAX(a,b) (a>b)?a:b
#define MIN(a,b) (a<b)?a:b
#define INF 987654321
#define pi (2*acos(0.0))
#define eps 1e-7

#ifdef ONLINE_JUDGE
#define i64 long long
#else
#define i64 __int64
#endif




using namespace std;
vector<int>graph[1005];
int n,m;
int bfs(int s){
	int i,u,v;
	int color[1005];
	memset(color,0,sizeof(color));
	queue<int>Q;
	color[s] = 1;
	Q.push(s);
	while(!Q.empty()){
		u = Q.front();
		Q.pop();
		for(i=0;i<graph[u].size();i++){
			v = graph[u][i];
			if(color[v]==1){
				return 1;
			}
			else{
				color[v] = 1;
				Q.push(v);
			}
		}
	}
	return 0;
}
int main(){

	freopen("asmall.in","r",stdin);
	freopen("out.txt","w",stdout);
	int cases,i,j,k,u,f,ct=1;
	scanf("%d",&cases);
	while(cases--){
		scanf("%d",&n);
		for(i=0;i<=n;i++){
			graph[i].clear();
		}
		for(i=1;i<=n;i++){
			scanf("%d",&m);
			for(j=0;j<m;j++){
				scanf("%d",&u);
				graph[i].push_back(u);
			}
		}
		f = 0;
		for(i=1;i<=n;i++){
			if(bfs(i)==1){
				f = 1;
				break;
			}
		}
		if(f==0)
			printf("Case #%d: No\n",ct++);
		else
			printf("Case #%d: Yes\n",ct++);
	}
	return 0;
}