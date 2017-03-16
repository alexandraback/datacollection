#include<stdio.h>
#include<algorithm>
#include<vector>
#include<set>
#include<map>
#include<string>
#include<iostream>
#include<cstring>

#define maxdim 25
#define INF (1<<30)

using namespace std;

int n,m,k,viz[maxdim][maxdim],inq[maxdim][maxdim];
int dir = 4;
int dx[] = {-1,0,1,0};
int dy[] = {0,1,0,-1};

void dfs ( int x , int y ){
	inq[x][y] = 1;
	
	for ( int d = 0 ; d < dir ; ++d ){
		int xv = x+dx[d],yv = y+dy[d];
		if ( xv < 1 || xv > n || yv < 1 || yv > m || viz[xv][yv] || inq[xv][yv] )	continue ;
		dfs(xv,yv);
	}
}

inline int solve () {
	
	int sol = INF;
	for ( int conf = 0 ; conf < (1<<(n*m)) ; ++conf ){
		
		int b = 0,stones = 0;
		for ( int i = 1 ; i <= n ; ++i ){
			for ( int j = 1 ; j <= m ; ++j ){
				viz[i][j] = (conf & (1<<b)) > 0;
				inq[i][j] = 0;
				stones += (conf & (1<<b)) > 0;
				++b;
			}
		}
		
		for ( int i = 1 ; i <= n ; ++i ){
			if ( !viz[i][1] && !inq[i][1] ){
				dfs(i,1);
			}
			if ( !viz[i][m] && !inq[i][m] ){
				dfs(i,m);
			}
		}
		for ( int j = 1 ; j <= m ; ++j ){
			if ( !viz[1][j] && !inq[1][j] ){
				dfs(1,j);
			}
			if ( !viz[n][j] && !inq[n][j] ){
				dfs(n,j);
			}
		}
		
		int inside = 0;
		for ( int i = 1 ; i <= n ; ++i ){
			for ( int j = 1 ; j <= m ; ++j ){
				inside += inq[i][j];
			}
		}
		inside = n*m - inside;
		
		if ( inside == k ){
			sol = min(sol,stones);
		}
	}
	
	return sol;
}

int main () {
	
	freopen("c.in","r",stdin);
	freopen("c.out","w",stdout);
	
	int tests;
	scanf("%d",&tests);
	
	for ( int t = 1 ; t <= tests ; ++t) {
		
		scanf("%d %d %d",&n,&m,&k);
		printf("Case #%d: %d\n",t,solve());
	}
	
	return 0;
}