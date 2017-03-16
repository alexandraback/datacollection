#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;
const int maxn = 2005;
vector<int> G[maxn];
int n,match[maxn],V,ans1,ans2;
bool used[maxn];
double a[maxn],b[maxn];
void add(int u,int v)
{
	G[u].push_back(v);
	G[v].push_back(u);
}
bool dfs(int v)
{
	used[v] = 1;
	for(int i = 0; i < G[v].size(); ++i){
		int u = G[v][i],w = match[u];
		if(w < 0 || (!used[w] && dfs(w))){
			match[v] = u;
			match[u] = v;
			return true;
		}
	}
	return false;
}
int bipartite_matching()
{
	int res = 0;
	memset(match,-1,sizeof(match));
	for(int v = 0; v < V; ++v)
		if(match[v] < 0){
			memset(used,0,sizeof(used));
			if(dfs(v)) ++res;
		}
	return res;
}
void init()
{
	scanf("%d",&n);
	V = 2 * n;
	for(int i = 0; i < n; ++i) scanf("%lf",&a[i]);
	for(int i = 0; i < n; ++i) scanf("%lf",&b[i]);
}
void solve1()
{
	for(int i = 0; i < V; ++i) G[i].clear();
	for(int i = 0; i < n; ++i)
		for(int j = 0; j < n; ++j)
			if(a[i] > b[j]) add(i,n + j);
	ans1 = bipartite_matching();
}
void solve2()
{
	ans2 = 0;
	memset(used,0,sizeof(used));
	b[n] = 1;
	sort(b,b + n);
	for(int i = 0; i < n; ++i){
		int tmp = n;
		for(int j = 0; j < n; ++j)
			if(!used[j] && b[j] > a[i]){
				tmp = j;
				break;
			}
		if(tmp == n){
			for(int j = 0; j < n; ++j)
				if(!used[j]){
					used[j] = 1;
					break;
				}
			++ans2;
		}
		else used[tmp] = 1;
	}
}
int main()
{
	int T;
	scanf("%d",&T);
	for(int ca = 1; ca <= T; ++ca){
		init();
		solve1();
		solve2();
		printf("Case #%d: %d %d\n",ca,ans1,ans2);
	}
	return 0;
}

