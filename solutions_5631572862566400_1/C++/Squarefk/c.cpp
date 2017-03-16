#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>
#define REP(i,n) for (int i=1;i<=n;++i)
#define FOR(i,n) for (__typeof(n.begin())i=n.begin();i!=n.end();++i)
using namespace std;

vector<int> v[1010];
vector<int> vv[1010];
int T,n,ans;
int a[1010];
int dep[1010];
int line[1010];
bool boo[1010];

int bfs(int k) {
	line[1]=k;
	memset(boo,false,sizeof(boo));
	memset(dep,0,sizeof(dep));
	boo[k]=true;
	int l,r;
	for (l=1,r=1;l<=r;++l) {
//		printf("%d ",line[l]);
		FOR(p,v[line[l]])
			if (!boo[*p]) {
				line[++r]=*p;
				boo[*p]=true;
				dep[*p]=dep[line[l]]+1;
			} else {
				if (*p==k)
					return dep[line[l]]+1;
			}
	}
	return 2;
}

int dfs_len(int k, int kk) {
	line[1]=k;
	memset(boo,false,sizeof(boo));
	memset(dep,0,sizeof(dep));
	boo[k]=boo[kk]=true;
	int l,r;
	for (l=1,r=1;l<=r;++l) {
//		printf("%d ",line[l]);
		FOR(p,vv[line[l]])
			if (!boo[*p]) {
				line[++r]=*p;
				boo[*p]=true;
				dep[*p]=dep[line[l]]+1;
			}
	}
//	puts("");
	return dep[line[r]];
}

int main() {
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
	scanf("%d",&T);
	REP(T_T,T) {
		printf("Case #%d: ",T_T);
		scanf("%d",&n);
		REP(i,n) {
			int x;
			scanf("%d",&x);
			a[i]=x;
			v[i].push_back(x);
			vv[x].push_back(i);
		}
		ans=0;
		REP(i,n) {
			ans=max(ans,bfs(i));
//			puts("");
		}
		int ttt=0;
		REP(i,n) REP(j,i-1)
			if (a[i]==j && a[j]==i) {
				ttt+=dfs_len(i,j)+dfs_len(j,i)+2;
//				printf("%d %d  %d %d\n", i, j, dfs_len(i,j),dfs_len(j,i));
			}
		REP(i,n) v[i].clear();
		REP(i,n) vv[i].clear();
//		printf("%d %d\n",ans,ttt);
		printf("%d\n",max(ans,ttt));
	}
	return 0;
}
