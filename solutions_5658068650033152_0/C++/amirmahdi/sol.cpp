#include <iostream>
#include <cstdio>
#include <algorithm>
#include <set>
#include <map>
#include <vector>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <sstream>
#include <fstream>
#include <string>

#define rep(i,n) for(int i=0;i<n;i++)
#define VI vector<int>
#define pb(x) push_back(x)
#define ll long long
#define For(i,a,b) for(int i=a;i<b;i++)
#define sz(s) int(s.size())
using namespace std;

const int maxn = 22;

int ted;
int mark[maxn][maxn];
int a[maxn][maxn];

int n,m,k;
int w[4][2]={
	{0,1},
	{0,-1},
	{1,0},
	{-1,0}
};

int bit(int x, int y){
	return (x>>y)&1;
}

void dfs(int x, int y){
	if(mark[x][y] || a[x][y] == 0)
		return;
	mark[x][y] = 1;
	ted++;
	rep(i,4){
		int xx = x+w[i][0], yy = y+w[i][1];
		if(xx < 0 || xx >= n || yy < 0 || yy >= m || a[xx][yy] == 0)
			continue;
		dfs(xx, yy);
	}
}

int main() {
	int t;
	cin >> t;
	rep(g,t){
		cout << "Case #" <<g+1 << ": ";
		cin >> n >> m >> k;
		int nm = n*m;
		int best = nm;
		rep(i, 1<<(nm)){
			int cnt = 0;
			rep(j,n)
				rep(l,m)
					if(bit(i, j*m+l)){
						cnt++;
						a[j][l] = 0;
					}else
						a[j][l] = 1;
			if(cnt >= best)
				continue;
			memset(mark,0,sizeof(mark));
			ted = 0;
			rep(j,n){
				dfs(j, 0);
				dfs(j, m-1);
			}
			rep(j, m){
				dfs(0, j);
				dfs(n-1, j);
			}
			if(nm-ted >= k)
				best = cnt;
		}
		cout << best << endl;
	}
	return 0;
}
