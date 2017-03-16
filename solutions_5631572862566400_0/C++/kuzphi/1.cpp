#include <map>
#include <cmath>
#include <iostream>
#include <cstring>
#include <stdio.h>
#include <sstream>
#include <vector>
#include <algorithm>
#include <assert.h>
#include <cstring>
#define PB push_back
#define ll long long
#define MP make_pair
#define X first
#define Y second
#define LS k*2,l,mid
#define RS k*2+1,mid+1,r
using namespace std;

const int  Maxn = 1010 , Maxm = 30 , INF = 2100000000 >> 2, Mo = 1e9 + 7;
const double pi = acos(-1.0);
string st , s;
int N,a[Maxn], f[Maxn],vis[Maxn],w[Maxn][Maxn];
int d[Maxn],ck[Maxn];
int dfs(int root, int u , int dep){
	if (dep > 0 && u == root) return dep;
	if (vis[u]) return 0;
	vis[u] = 1;
	return dfs(root, f[u], dep + 1);
}
int maxlen(int u,int forbid){
	if (d[u] > -1) return d[u];
	d[u] = 0;
	for (int v=1;v<=N;v++){
		if(v == forbid) continue;
		if (w[u][v])
			d[u] = max(d[u] ,maxlen(v,forbid) + 1);
	}
	return d[u];
}
int main(){
	int T;
	cin >> T;
	for (int cas = 1;cas <= T;cas++){
		cout << "Case #"<<cas << ": ";
		cin >> N;
		memset(w,0,sizeof(w));
		for (int i=1;i<=N;i++) cin >> f[i], w[f[i]][i] = 1;
		int ans = 0;
		for (int i=1;i<=N;i++) {
			memset(vis,0,sizeof(vis));
			ans = max(dfs(i,i,0),ans);
		}
		for (int i=1;i<=N;i++) d[i] = -1;
		vector<int> cnt;
		memset(ck,0,sizeof(ck));
		for (int i=1;i<=N;i++){
			if (ck[i]) continue;
			if (f[f[i]] == i){
				ck[i] = ck[f[i]] = 1;
				cnt.push_back(2 + maxlen(i,f[i]) + maxlen(f[i],i));
			}
		}
		sort(cnt.begin(),cnt.end());
		int nn = cnt.size();		
		if (nn > 1) ans = max(cnt[nn - 1] + cnt[nn-2], ans);
		cout << ans << endl;
	}	
}

