#include <algorithm>
#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstdlib>
#include <string>
#include <cstdio>
#include <vector>
#include <queue>
#include <cmath>
#include <set>
#include <map>

#define pb push_back
#define mp make_pair
#define vi vector <int>
#define vii vector <pair<int,int> >
#define ll long long
#define f first
#define s second

using namespace std;

int  t1,t,n,m,a,b,minz,ind;
vi zip,ans;
vii g [51];
bool us [51];

void dfs(int v){
	ans.pb(zip[v]);
	us[v] = true;
	sort(g[v].begin(), g[v].end());
	for(int i = 0; i < g[v].size(); i++){
		if(!us[g[v][i].second])dfs(g[v][i].second);
	}
}

int main(){
	freopen("C-small-attempt0.in", "r", stdin);
	freopen("D.out", "w", stdout);

	scanf ("%d", &t);
	for(t1 = 1; t1 <= t; ++t1){
		scanf ("%d %d",&n,&m);
		zip.clear();
		zip.resize(n+1);
		minz = 1000000;
		for(int i = 1; i <= n; i++){
			scanf("%d",&zip[i]);
			if(zip[i] < minz){
				minz = zip[i];
				ind = i;
			}
		}
		for(int i = 1; i <= m; i++){
			scanf("%d %d",&a,&b);
			g[a].pb(mp(zip[b],b));
			g[b].pb(mp(zip[a],a));
		}
		dfs(ind);
		printf("Case #%d: ",t1);
		for(int i = 0; i < ans.size(); i++)printf("%d", ans[i]);
		printf("\n");
		ans.clear();
		for(int i = 0; i < 51; i++){
			g[i].clear();
			us[i] = 0;
		}
	}

	return 0;
}