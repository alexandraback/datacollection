#include <cstdio>
#include <queue>
#include <vector>
#include <algorithm>
#define scanf(args...) scanf(args) ? : 0
using namespace std;
const int MAX=60;
vector< vector<int> > W;
vector<int> V;
vector<int> G[MAX];
int C[MAX];
int Q;
int n;
bool visited[MAX];
bool cmp(const vector<int>& A, const vector<int>& B)
{
	for(int i=0;i<n;i++)
		if(A[i]!=B[i])
			return C[A[i]]<C[B[i]];
	return true;
} 
bool good(int v)
{
	for(int i=0;i<=Q;i++)
		if(V[i]==v)
			return true;
	return false;
}
void clear()
{
	for(int i=0;i<n;i++)
	{
		G[i].clear();
		visited[i]=false;
	}
	W.clear();
}
void dfs(int v)
{
	visited[v]=true;
	Q++;
	for(int Z=0;Z<100;Z++)
	{
		for(int i=0;i<(int)G[v].size();i++)
			if(!visited[G[v][i]] && good(G[v][i]))
				dfs(G[v][i]);
	}
}
void check()
{
	for(int i=0;i<n;i++)
		visited[i]=false;
	Q=0;
	dfs(V[0]);
	for(int i=0;i<n;i++)
		if(!visited[i])
			return;
	W.push_back(V);
}
void solve()
{
	int m,a,b;
	scanf("%d%d",&n,&m);
	clear();
	for(int i=0;i<n;i++)
		scanf("%d",&C[i]);
	while(m--)
	{
		scanf("%d%d",&a,&b);
		a--;
		b--;
		if(a>=0 && a<n && b>=0 && b<n)
		{
			G[a].push_back(b);
			G[b].push_back(a);
		}
	}
	V.resize(n);
	for(int i=0;i<n;i++)
		V[i]=i;
	do check();
	while(next_permutation(V.begin(),V.end()));
	sort(W.begin(),W.end(),cmp);
	//
	//printf("%d\n",(int)W.size());
	/*for(int i=0;i<W.size();i++)
	{
		for(int j=0;j<n;j++)
			printf("%d ",W[i][j]);
		printf("\n");
	}*/
	
	//
	for(int i=0;i<n;i++)
		printf("%d",C[W[0][i]]);
	printf("\n");
}
int main()
{
	int t;
	scanf("%d",&t);
	for(int i=1;i<=t;i++)
	{
		printf("Case #%d: ",i);
		solve();
	}
}