#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cctype>

#include<cmath>
#include<iostream>
#include<fstream>

#include<string>
#include<vector>
#include<queue>
#include<map>
#include<algorithm>
#include<set>
#include<sstream>
#include<stack>
#include<iterator>
using namespace std;

#pragma comment(linker,"/STACK:16777216")
#pragma warning(disable:4786)

#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))
#define myabs(a) ((a)<0?(-(a)):(a))
#define pi acos(-1.0)
#define inf (1<<29)
#define CLR(a) memset(a,0,sizeof(a))
#define SET(a) memset(a,-1,sizeof(a))
#define pb push_back
#define all(a) a.begin(),a.end()
#define eps 1e-9
#define i64 __int64
#define MX 1009

typedef pair<int,int> pii;

int p[MX][MX],n,vi[MX],flag;
vector<int> g[MX];

void dfs(int u){
	if(flag || vi[u])return;
	vi[u]=1;
	int i,v,j;
	for(i=0;i<g[u].size();i++){
		v=g[u][i];
		if(!flag && !vi[v]){
			dfs(v);
		}
		if(!flag){
			for(j=1;j<=n;j++){
				p[u][j]+=p[v][j];
				if(p[u][j]>=2){
					flag=1;
					break;
				}
			}
		}
	}
}

int main()
{
	//freopen("in.txt","r",stdin);
	freopen("A-small-attempt1.in","r",stdin);
	freopen("out.txt","w",stdout);
	int cs,t=1,i,m,v;
	cin>>cs;
	while(cs--){
		cin>>n;
		CLR(p);
		for(i=1;i<=n;i++){
			cin>>m;
			g[i].clear();
			while(m--){
				cin>>v;
				g[i].pb(v);
				p[i][v]=1;
			}
		}
		CLR(vi);
		flag=0;
		for(i=1;i<=n;i++){
			if(!flag || !vi[i]){
				dfs(i);
			}
		}
		printf("Case #%d: ",t++);
		if(flag)printf("Yes\n");
		else printf("No\n");
	}
	return 0;
}


