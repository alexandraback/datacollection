#include <bits/stdc++.h>
#define fr(i,a,b) for(int i = (a); i < (b); ++i)
#define pb push_back

using namespace std;

int dx[]={0,1,0,-1};
int dy[]={1,0,-1,0};

int grid[12][12];

int n,m;

bool f(int x, int y, int dir) {
	while(1) {
		x=x+dx[dir];
		y=y+dy[dir];
		if(x==n||y==m||x==-1||y==-1) return 1;
		if(grid[x][y]==2) return 0;
	}
}

bool foo(int x, int y) {
	bool ok1=(f(x,y,1)&f(x,y,3));
	bool ok2=(f(x,y,0)&f(x,y,2));
	return ok1|ok2;
}

int main() {
	int tc; cin>>tc;++tc;
	fr(_,1,tc) {
		printf("Case #%d: ",_);
		cin>>n>>m;
		fr(i,0,n) fr(j,0,m) {
			cin>>grid[i][j];
		}
		bool ok = 1;
		bool aux = 1;
		fr(i,0,n) {
			if(grid[i][0]==1)aux=0,ok&=(foo(i,0));
			if(!ok) { goto lol; }
		}
		fr(i,0,n) {
			if(grid[i][m-1]==1)aux=0,ok&=(foo(i,m-1));
			if(!ok) {  goto lol; }
		}
		fr(i,0,m) {
			if(grid[0][i]==1)aux=0,ok&=(foo(0,i));
			if(!ok) { goto lol; }
		}
		fr(i,0,m) {
			if(grid[n-1][i]==1)aux=0,ok&=(foo(n-1,i));
			if(!ok) {  goto lol; }
		}
		if(aux) {
			bool oi = 0;
			fr(i,0,n) fr(j,0,m) {
				oi|=(grid[i][j]==1);
			}
			if(oi) printf("NO\n");
			else printf("YES\n");
			continue;
		}
		lol:;
		printf(ok?"YES\n":"NO\n");
	}
}


