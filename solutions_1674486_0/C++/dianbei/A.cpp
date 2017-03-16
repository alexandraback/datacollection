#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<algorithm>
#include<vector>
#include<queue>
#include<math.h>
#include<iostream>
using namespace std;
const int inf=1<<28;

int cnt[1010],visit[1010];
vector<int> e[1010];
int dfs(int pre,int u)
{
	for(int i=0;i<e[u].size();i++){
		if(e[u][i]==pre)
			continue;
		if(visit[e[u][i]])
			continue;
		visit[e[u][i]]=1;
		cnt[e[u][i]]++;
		if(cnt[e[u][i]]>=2)
			return 1;
		if(dfs(i,e[u][i]))
			return 1;
		visit[e[u][i]]=0;
	}
	return 0;
}
int main()
{
	freopen("A.in","r",stdin);
	freopen("A.out","w",stdout);
	int T,n,x,y,ri=1;
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		for(int i=0;i<=n;i++)
			e[i].clear();
		for(int i=0;i<n;i++){
			scanf("%d",&x);
			for(int j=0;j<x;j++){
				scanf("%d",&y);
				e[i+1].push_back(y);
			}
		}
		int flag=0;
		for(int i=1;i<=n;i++){
			memset(visit,0,sizeof(visit));
			memset(cnt,0,sizeof(cnt));
			visit[i]=1;
			if(dfs(i,i)){
				flag=1;
				break;
			}
		}
		printf("Case #%d: ",ri++);
		if(flag)
			printf("Yes\n");
		else
			printf("No\n");
	}
	return 0;
}
