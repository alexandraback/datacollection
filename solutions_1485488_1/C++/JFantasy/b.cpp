#include <cstdio>
#include <cstring>
#include <queue>
#include <algorithm>

using namespace std;

const int maxn = 105;
const int dx[4] = {0,-1,0,1};
const int dy[4] = {-1,0,1,0};

struct node {
	int x , y;
	node( int a = 0 , int b = 0 ) : x(a) , y(b) {}
};

queue<node> que;
int mat[maxn][maxn][2] , n , m , k;
double dis[maxn][maxn];
bool view[maxn][maxn] , inque[maxn][maxn];

void init() {
	scanf( "%d%d%d" , &k , &n , &m );
	for ( int h = 0; h < 2; h++ ) {
		for ( int i = 0; i < n; i++ ) {
			for ( int j = 0; j < m; j++ ) {
				scanf( "%d" , &mat[i][j][h] );
			}
		}
	}
}

bool legal( int x , int y ) {
	return x>=0&&y>=0&&x<n&&y<m;
}

double cal( int x , int y , int flag ) {
	int tx = x + dx[flag] , ty = y + dy[flag];
	if ( !legal(tx,ty) ) return -1;
	if ( mat[tx][ty][0]-mat[x][y][1] < 50 || mat[x][y][0]-mat[tx][ty][1] < 50 || mat[tx][ty][0]-mat[tx][ty][1] < 50 ) return -1;
	double kk = max( double(k-mat[tx][ty][0]+50)/10 , dis[x][y] );
	if ( k-kk*10 >= mat[x][y][1]+20 ) kk += 1;
	else kk += 10;
	return kk;
}

void prepare() {
	memset( view , 0 , sizeof(view) );
	memset( inque , 0 , sizeof(inque) );
	que.push(node(0,0));
	view[0][0] = 1;
	while ( !que.empty() ) {
		node cnt = que.front();
		int x = cnt.x , y = cnt.y;
		que.pop();
		for ( int i = 0; i < 4; i++ ) {
			int tx = cnt.x+dx[i] , ty = cnt.y+dy[i];
			if ( !legal(tx,ty) ) continue;
			if ( view[tx][ty] ) continue;
			if ( mat[tx][ty][0]-mat[x][y][1] < 50 || mat[x][y][0]-mat[tx][ty][1] < 50 || mat[tx][ty][0]-mat[tx][ty][1] < 50 ) continue;
			if ( k+50 > mat[tx][ty][0] ) continue;
			view[tx][ty] = 1;
			que.push(node(tx,ty));
		}
	}
}

void work( int cas ) {
	memset( dis , 0 , sizeof(dis) );
	memset( view , 0 , sizeof(view) );
	prepare();
	for ( int i = 0; i < n; i++ ) {
		for ( int j = 0; j < m; j++ ) {
			if ( view[i][j] ) {
				que.push(node(i,j));
				inque[i][j] = 1;
			}
		}
	}
	while ( !que.empty() ) {
		node cnt = que.front();
		que.pop();
		inque[cnt.x][cnt.y] = 0;
		for ( int i = 0; i < 4; i++ ) {
			double t = cal(cnt.x,cnt.y,i);
			if ( t == -1 ) continue;
			if ( !view[cnt.x+dx[i]][cnt.y+dy[i]] || dis[cnt.x+dx[i]][cnt.y+dy[i]] > t ) {
				dis[cnt.x+dx[i]][cnt.y+dy[i]] = t;
				view[cnt.x+dx[i]][cnt.y+dy[i]] = 1;
				if ( !inque[cnt.x+dx[i]][cnt.y+dy[i]] ) {
					que.push(node(cnt.x+dx[i],cnt.y+dy[i]));
					inque[cnt.x+dx[i]][cnt.y+dy[i]] = 1;
				}
			}
		}
	}
	printf( "Case #%d: %.6lf\n" , cas , dis[n-1][m-1] );
}

int main() {
	int cas;
	scanf( "%d" , &cas );
	for ( int t = 1; t <= cas; t++ ) {
		init();
		work(t);
	}
	return 0;
}
