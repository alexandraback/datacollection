#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<vector>
#include<queue>
#include<map>
using namespace std;
#define max(x,y) (((x)>(y))?(x):(y))
#define min(x,y) (((x)<(y))?(x):(y))
#define INF (1<<29)
#define eps (1e-8)
#define feq(x,y) (fabs(x-y)<eps)
#define flt(x,y) (((y)-(x))>eps)
#define fgt(x,y) (((x)-(y))>eps)
#define ll long long

int T,n,edge[1005][15],m[1005];
bool out[1005],visit[1005];

bool dfs(int pos){
	bool ans=0;
	visit[pos]=1;
	//printf("%d!\n",pos);
	for (int i=0;i<m[pos];++i){
		if (!visit[edge[pos][i]]) ans=ans || dfs(edge[pos][i]);
		else ans=1;
	}
	return ans;
}

int main(){
	scanf("%d",&T);
	for (int t=1;t<=T;++t){
		memset(m,0,sizeof(m));
		memset(out,1,sizeof(out));

		scanf("%d",&n);
		for (int i=1;i<=n;++i){
			scanf("%d",&m[i]);
			for (int j=0;j<m[i];++j){
				scanf("%d",&edge[i][j]);
				out[edge[i][j]]=0;
			}
		}

		bool ans=0;
		for (int i=1;i<=n;++i){
			if (out[i]){
				memset(visit,0,sizeof(visit));
				//printf("%d!\n",i);
				ans = ans || dfs(i);
				if (ans) break;
			}
		}
		if (ans) printf("Case #%d: Yes\n",t);
		else printf("Case #%d: No\n",t);
	}
	return 0;
}
