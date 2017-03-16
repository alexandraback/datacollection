#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#define pb push_back
using namespace std;
vector < int > g[1101];
vector < int > g2[1101];
int ans[1101];
int fin[1101];
bool fix[1101];
bool ff[1111];
int N;
void dfs2(int u)
{
	fix[u] = true;
	fin[u] = 1;
	int z = 0;
	for(int i = 0 ;  i < g2[u].size() ; i++)
	{
//	if(u==4)		cout << g2[u][i] << 'y'<<ff[g2[u][i]] << endl;
		if(!fix[g2[u][i]])
			dfs2(g2[u][i]);
		if(!fix[g2[u][i]])z = max(z, fin[g2[u][i]]+1);
	//	cout << z << 'y' << endl;	
	}
//	if(u == 10){
//	cout << g2[u][0] << ' ' <<  g2[u][1]<< endl;
//	cout << fin[g2[u][0]] << 'x' << fin[g2[u][1]] << endl;
//	cout << g2[u].size()<<'t' << endl;
//}
//if(u==4) cout << fin[u] << endl;
	fin[u] = max(z,fin[u]);
	fix[u] = false;
	
}
void dfs(int u)
{
	ff[u] = true;
	fix[u] = true;
	ans[u] = 1;
	int z = 0;
	for(int i = 0 ;  i < g[u].size() ; i++)
	{
		if(!fix[g[u][i]])
			dfs(g[u][i]);
		if(!fix[g[u][i]])z = max(z, ans[g[u][i]]+1);	
	}	
//if(u == 5) cout << g[u].size() << " -- "<< z << endl;
dfs2(u);

ans[u] = max(ans[u],max(z,fin[u]));
//cout << u << 'p' << ans[u] <<"f" << fin[u] <<"z" << z<< endl;

fix[u] = false;
}
void solve()
{
	cin >> N;
	for(int i = 1;i<=1000;i++)
	{
	
		ans[i] = 0;
		fix[i] = false;
		ff[i] = false;
		fin[i] = 0;
		
		g2[i].clear();
		g[i].clear();
	
	}
	for(int i= 1 ; i  <= N ;i++)
	{

		int p;
		cin >> p;
		g[i].pb(p);
		g2[p].pb(i);
	}
	int maxans=0;
	//dfs2(10);
	//cout << fin[10] << endl;
	for(int i = 1; i <= N ; i++)
	{
		if(!ff[i])
		{
			dfs(i);
		}
		
	}
	for(int i = 1; i <=N;i++)
	{
//		cout << i << ' ' << ans[i] << ' ' << fin[i] << endl; 
		maxans = max(maxans,ans[i]);
	}
	cout << maxans<<endl;
	
}
int main()
{
	freopen("C-small-attempt1.in","r",stdin);
	freopen("1.out","w",stdout);
	int t;
	cin >> t;
	for(int i = 0 ; i < t ; i++)
	{
	printf("Case #%d: ",i+1);
		solve();
	
	}
	
}
