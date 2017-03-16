/*	In the name of God	*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <string>
#include <algorithm>
#include <vector>
#include <iostream>
#include <sstream>
#include <bitset>
#include <map>
#include <set>
#include <queue>
#include <stack>

#define rep(i,n) for((i)=0;(i)<(n);(i)++)
typedef long long ll;

using namespace std;

int T,n;
int sorted[1024],w[1024];
bool g[1024][1024],visit[1024];
char s[1024];
void dfs(int node){
	visit[node]=true;
	int i;
	for(i=0;i<n;i++)if(g[node][i] && !visit[i])
		dfs(i);
	sorted[T--]=node;
}
void topolsort(){
	int i;
	T=n-1;
	memset(visit,0,sizeof visit);
	for(i=0;i<n;i++)if(!visit[i])
		dfs(i);
}

bool dfs2(int v){
	if (visit[v])
		return 1;
	visit[v]=1;
	int i,r=0;
	rep(i,n)
		if (g[v][i])
			r=r||dfs2(i);
	return r;
}

int main(){
	freopen("A-small-attempt2 (1).in","r",stdin);
	freopen("A-small-attempt2 (1).out","w",stdout);	
	int i,ti,tc,j,k,x,y,m;
	scanf("%d",&tc);
	rep(ti,tc){
		memset(g,0,sizeof g);
		memset(w,0,sizeof w);
		scanf("%d",&n);
		rep(i,n){
			scanf("%d",&m);
			rep(j,m){
				scanf("%d",&x);
				g[i][x-1]=1;
			}
		}
		topolsort();
		bool r=0;
		rep(i,n){
			memset(visit,0,sizeof visit);
			r=r||dfs2(sorted[i]);
		}
		/*rep(i,n){
			k=sorted[i];
			if (!w[i])
				w[i]=1;
			rep(j,n){
				if (g[i][j])
					w[j]+=w[i];
			}
		}
		rep(i,n)
			if (w[i]>1)
				break;*/
		printf("Case #%d: ",ti+1);
		if (r==0)
			printf("No\n");
		else
			printf("Yes\n");

	}


	return 0;
}