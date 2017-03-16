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

const int maxn = 55;

bool mark[6][6];
int place[maxn][maxn][maxn*maxn];
int d[maxn][maxn][maxn*maxn];

inline bool bit(int i, int j){
	return (i>>j)&1;
}

inline bool bit(int c, int x, int y, int p){
	return (p>>(c*x+y))&1;
}

int w[][2]={
	{0,1},
	{0,-1},
	{-1,1},
	{-1,0},
	{-1,-1},
	{1,0},
	{1,1},
	{1,-1},
};

bool iszero(int r, int c, int x, int y, int p){
	int m = x*c+y;
	if(!bit(p,m)){
		rep(k,8){
			int ii = x+w[k][0], jj = y+w[k][1];
			if(ii >=0 && ii < r && jj >=0 && jj < c && bit(c, ii, jj, p))
				return false;
		}
		return true;
	}
	return false;
}

int ecnt = 0;

void dfs(int r, int c, int x, int y, int p){
	mark[x][y] = 1;
	ecnt++;
	if(!iszero(r,c,x,y,p))
		return ;
	rep(k,8){
		int ii = x+w[k][0], jj = y+w[k][1];
		if(ii >=0 && ii < r && jj >=0 && jj < c && !bit(c, ii, jj, p) && !mark[ii][jj])
			dfs(r,c,ii,jj,p);
	}
}

bool isok(int r, int c, int x, int mines){
	if(mines == (r*c-1)){
		rep(i,r*c)
			if(!bit(x,i)){
				place[r][c][mines] = i;
				break;
			}
		return true;
	}
	rep(i,r)
		rep(j,c){
			if(iszero(r, c, i, j, x)){
				ecnt = 0;
				memset(mark,0,sizeof(mark));
				dfs(r, c, i, j, x);
				place[r][c][mines] = i*c+j;
				return ecnt == (r*c-mines);
			}
		}
	return false;
}

void solve(int r, int c){
	int n = r*c;
	rep(i, (1<<n)){
		int cnt=0;
		rep(j,n)
			if(bit(i,j))
				cnt++;
		if(d[r][c][cnt] == -1 && isok(r,c,i, cnt))
			d[r][c][cnt] = i;
	}
}

int main() {
	int t;
	cin >> t;
	memset(d, -1, sizeof(d));
	for(int i=1;i<=5;i++)
		for(int j=1;j<=5;j++)
			solve(i,j);
	rep(g,t){
		int r,c,m;
		cin >> r >> c >> m;
		cout << "Case #" << g+1 << ": " << endl;
		if(d[r][c][m] == -1)
			cout << "Impossible" << endl;
		else{
			int x= d[r][c][m];
			int u = place[r][c][m];
		//	cout << u/c << " " << (u%c) << endl;
			rep(i,r){
				rep(j,c)
					if(bit(c, i, j, x))
						cout << "*";
					else if(i*c+j == place[r][c][m])
						cout << "c";
					else
						cout << ".";
				cout << endl;
			}
		}
	}
	return 0;
}
