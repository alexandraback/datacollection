#include <bits/stdc++.h>
#define fr(i,a,b) for(int i = (a); i < (b); ++i)
#define pb push_back

using namespace std;

int dx[]={0,1,0,-1};
int dy[]={1,0,-1,0};

int grid[110][110];

int n,m;

bool f(int x, int y, int dir, int num) {
	while(1) {
		x=x+dx[dir];
		y=y+dy[dir];
		if(x==n||y==m||x==-1||y==-1) return 1;
		if(grid[x][y]>num) return 0;
	}
}

bool foo(int x, int y, int num) {
	bool ok1=(f(x,y,1,num)&f(x,y,3,num));
	bool ok2=(f(x,y,0,num)&f(x,y,2,num));
	return ok1|ok2;
}

int main() {
	int tc; cin>>tc;++tc;
	fr(_,1,tc) {
		printf("Case #%d: ",_);
		cin>>n>>m;
		fr(i,0,n) {
			fr(j,0,m) {
				cin>>grid[i][j];
			}
		}
		bool ok = 1;
		fr(i,0,n) fr(j,0,m) {
			ok&=foo(i,j,grid[i][j]);
		}
		printf(ok?"YES\n":"NO\n");
	}
	return 0;
}


