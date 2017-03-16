#include <stdio.h>
#include <string.h>
#include <vector>
#define maxn 1010

using namespace std;

vector<int> a[maxn];
int deg[maxn];
int q[maxn];
int tag[maxn];
int n;
int dfs(int x){
	if (tag[x]) return 1;
	tag[x]=1;
	for (int i=0;i<(int)a[x].size();i++){
		int v=a[x][i];
		if (dfs(v)) return 1;
	}
	return 0;
}
int check(int sp){
	memset(tag,0,sizeof(tag));
	return dfs(sp);
}
int main(){
	int tn,cp;
	for (scanf("%d",&tn),cp=1;cp<=tn;cp++){
		scanf("%d",&n);
		memset(deg,0,sizeof(deg));
		for (int i=1;i<=n;i++){
			int k;
			a[i].clear();
			for (scanf("%d",&k);k;k--){
				int p;
				scanf("%d",&p);
				a[i].push_back(p);
				deg[p]++;
			}
		}
		int flag=0;
		for (int i=1;i<=n;i++)
			if (check(i)){
				flag=1;
				break;
			}
		printf("Case #%d: ",cp);
		puts(flag?"Yes":"No");
	}
	return 0;
}
