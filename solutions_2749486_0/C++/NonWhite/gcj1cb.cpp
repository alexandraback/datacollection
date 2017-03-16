#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
#define f(_a,_b,_c) for( int _a = _b; _a < _c; _a++)

int dx[]= {1,-1,0,0};
int dy[]= {0,0,-1,1};
int dir[] ={'E','W','S','N'};
int xf,yf;
int dp[232][232][505];
bool done;
bool dfs(int x, int y, int j){
	if ( done ) return false;
	if ( x == xf && y == yf ) {
		return dp[x+100][y+100][j] = done = true;
	}
	if ( dp[x+100][y+100][j] != -1) return dp[x+100][y+100][j];
	int &ret = dp[x+100][y+100][j];
	ret = false;
	f(i,0,4){
		int nx = x + dx[i]*j;
		int ny = y + dy[i]*j;
		if ( nx > 100 || nx < -100 || ny > 100 || ny < -100 ) continue;
		if ( j > 500 ) continue;
		ret |=  dfs(nx,ny,j+1) ;
		if ( ret ) return true;
	}
	return dp[x+100][y+100][j] ;
}

void path( int x, int y , int j ){
	if ( x == xf && y == yf ) return ;
	f(i,0,4){
		int nx = x + dx[i]*j;
		int ny = y + dy[i]*j;
		if ( nx > 100 || nx < -100 || ny > 100 || ny < -100 ) continue;
		if ( j > 500 ) continue;
		if ( dp[nx+100][ny+100][j+1] == 1 ){
			putchar(dir[i]);
			path( nx, ny, j+ 1);
			break;
		}
	}
}

int main(){
	int runs;
	cin >> runs;
	f(r,1,runs+1){
		cin >> xf >> yf;
		memset( dp, -1, sizeof dp);
		cout <<"Case #"<<r<<": ";
		done = false;
		dfs( 0 , 0 , 1 );
		path( 0 , 0 , 1 );
		cout << endl;
	}
}
