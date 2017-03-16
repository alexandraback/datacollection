#include <cstdio>
#include <vector>
#include <utility>
#include <cstring>
#include <algorithm>
using namespace std;
const int maxn = 10;
vector<int> G[maxn];
pair<int,int> z[maxn];
bool visit[maxn];
int n,m,cnt,a[maxn],p[maxn];
void add(int x,int y)
{
	G[x].push_back(y);
}
void init()
{
	for(int i = 0; i < n; ++i) G[i].clear();
	scanf("%d%d",&n,&m);
	for(int i = 0; i < n; ++i){
		scanf("%d",&z[i].first);
		z[i].second = i;
	}
	while(m--){
		int x,y;
		scanf("%d%d",&x,&y);
		add(x - 1,y - 1);
		add(y - 1,x - 1);
	}
}
void check(int x)
{
	visit[x] = 1;
	if(cnt == n - 1) return;
	while(1){
		int u = x,v = a[cnt + 1];
		bool flag = 0;
		for(int i = 0; i < G[u].size(); ++i)
			if(G[u][i] == v && !visit[G[u][i]]){
				++cnt;
				check(v);
				flag = 1;
			}
		if(flag == 0) break;
	}
}
void solve()
{
	sort(z,z + n);
	for(int i = 0; i < n; ++i)
		p[i] = i;
	do{
		for(int i = 0; i < n; ++i)
			a[i] = z[p[i]].second;
		memset(visit,0,sizeof(visit));
		cnt = 0;
		check(a[0]);
		if(visit[a[n - 1]]){
			for(int i = 0; i < n; ++i) printf("%d",z[p[i]].first);
			printf("\n");
			return;
		}
	}while(next_permutation(p,p + n));
}
int main()
{
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
	int T;
	scanf("%d",&T);
	for(int ca = 1; ca <= T; ++ca){
		init();
		printf("Case #%d: ",ca);
		solve();
	}
	return 0;
}

