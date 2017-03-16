#include <cstdio>
int T,n,ne;
int a[1013];
int b[1013],vis[1013], head[1013];
struct P{
	int x,y, next;
}edge[1013];
int max(int a,int b){
	return a>b?a:b;
}
void add(int x,int y){
	edge[ne].x = x;
	edge[ne].y = y;
	edge[ne].next = head[x];
	head[x] = ne++;
}
int dfs(int node){
//	printf(">> %d\n", node);
	int tmp = 1;
	for (int i=head[node];i!=-1;i=edge[i].next){
//		printf(">>> %d\n",edge[i].y);
		if (b[edge[i].y]==0){
			tmp = max(dfs(edge[i].y)+1,tmp);
		}
	}
	return tmp;
}
int main(){
	scanf("%d",&T);
	for (int Case=1;Case<=T;Case++){
		ne=0;
		scanf("%d",&n);
		for (int i=1;i<=n;i++)head[i]=-1;
		for (int i=1;i<=n;i++){
			scanf("%d",&a[i]);
			b[i]=0;
			add(a[i],i);
		}
		int ans=0;
		for (int i=1;i<=n;i++){
			if (b[i] == 0){
				int pt = a[i];
				int tmpans=0;
				for (int j=1;j<=n;j++)vis[j]=0;
				while (pt!=i && vis[pt]==0){
					vis[pt]=1;
					pt=a[pt];
					tmpans++;
				}
				if (pt==i && tmpans!=1){
					for (int j=1;j<=n;j++)b[j] |= vis[j];
					ans = max(ans,tmpans+1);
				}
			}
		}
		for (int i=1;i<=n;i++)b[i]=0;
		int ans2=0;
		for (int i=1;i<=n;i++){
			if (i == a[a[i]] && b[i]==0 && b[a[i]]==0){
				b[i] = b[a[i]]=1;
				ans2 += dfs(i) + dfs(a[i]);
			}
		}
		printf("Case #%d: %d\n",Case, max(ans2,ans));
	}
}
