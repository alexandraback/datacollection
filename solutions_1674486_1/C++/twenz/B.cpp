#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cmath>
using namespace std;
#define N 1002
int m[N],tag[N],flag[N];
vector<int> v[N];
bool ans;
void dfs(int x)
{
	if(ans)return;
	int i;
	for(i=0;i<v[x].size();i++)
		if(flag[v[x][i]]){ans=true;return;}
		else{flag[v[x][i]] = true; dfs(v[x][i]);}
}
int main()
{
	//freopen("A-small-attempt0.in","r",stdin);
	//	freopen("B-large-practice.in","r",stdin);
	freopen("A-large.in","r",stdin);
	freopen("out.txt","w",stdout);
	int i,j,k,t,n,x;
	scanf("%d",&t);
	for(i=1;i<=t;i++){
		scanf("%d",&n);
		memset(tag,0,sizeof(tag));
		for(j=1;j<=n;j++){
			scanf("%d",&m[j]);
			v[j].clear();
			for(k=0;k<m[j];k++){
				scanf("%d",&x);
				v[j].push_back(x);
				tag[x] ++;
			}
		}
		ans = false;
		for(j=1;j<=n && !ans;j++){
			if(tag[j])continue;
			memset(flag,false,sizeof(flag));
			dfs(j);
		}
		if(ans)
			printf("Case #%d: Yes\n",i);
		else printf("Case #%d: No\n",i);
	}
	return 0;
}