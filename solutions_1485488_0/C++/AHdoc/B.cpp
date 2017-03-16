#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std ;

#define fo(i,a,b) for(int i=a;i<=b;i++)
#define INF 100000000.000

double H , F[109][109] , Up[109][109] , Dw[109][109] ;
int N , M ;

void Init() {
	cin >> H >> N >> M ;
	fo(i,1,N) fo(j,1,M) cin >> Up[i][j] ;
	fo(i,1,N) fo(j,1,M) cin >> Dw[i][j] ;
}

const int Dx[4] = {-1,0,0,1} ;
const int Dy[4] = {0,-1,1,0} ;

bool Check( double d1 , double u1 , double d2 , double u2 ) {
	return ( min(u1,u2) - max(d1,d2) >= 50.000 ) ;
}

void Dfs( int x , int y ) {
	fo(k,0,3) {
		int xx = x+Dx[k] , yy = y+Dy[k] ;
		if ( xx < 1 || xx > N || yy < 1 || yy > M ) continue ;
		
		if ( min(Up[xx][yy],Up[x][y]) - max(Dw[xx][yy],Dw[x][y]) < 50.000 ) continue ;
		
		double h = H - F[x][y] * 10.000 ;
		if ( F[x][y] == 0.000 ) {
			if ( Check( max(Dw[x][y],h) , Up[x][y] , max(Dw[xx][yy],h) , Up[xx][yy] ) ) {
				if ( F[xx][yy] > F[x][y] ) {
					F[xx][yy] = F[x][y] ;
					Dfs(xx,yy) ;
				}
			} else {
				double h1 = ( min(Up[x][y],Up[xx][yy]) - 50.000 ) ;
				// cout << "h1=" << h1 << "\n" ;
				double vv = (h-h1)/10.000 ;
				if ( Dw[x][y] <= h1-20.000 ) {
					if ( F[xx][yy] > F[x][y] + 1.000 + vv ) {
						F[xx][yy] = F[x][y] + 1.000 + vv ;
						Dfs(xx,yy) ;
					}
				} else {
					if ( F[xx][yy] > F[x][y] + 10.000 + vv ) {
						F[xx][yy] = F[x][y] + 10.000 + vv ;
						Dfs(xx,yy) ;
					}
				}
			}
		} else {
			if ( Check( max(Dw[x][y],h) , Up[x][y] , max(Dw[xx][yy],h) , Up[xx][yy] ) ) {
				if ( Dw[x][y] <= h-20.000 ) {
					if ( F[xx][yy] > F[x][y] + 1.000 ) {
						F[xx][yy] = F[x][y] + 1.000 ;
						Dfs(xx,yy) ;
					}
				} else {
					if ( F[xx][yy] > F[x][y] + 10.000 ) {
						F[xx][yy] = F[x][y] + 10.000 ;
						Dfs(xx,yy) ;
					}
				}
			} else {
				double h1 = ( min(Up[x][y],Up[xx][yy]) - 50.000 ) ;
				double vv = (h-h1)/10.000 ;
				if ( Dw[x][y] <= h1-20.000 ) {
					if ( F[xx][yy] > F[x][y] + 1.000 + vv ) {
						F[xx][yy] = F[x][y] + 1.000 + vv ;
						Dfs(xx,yy) ;
					}
				} else {
					if ( F[xx][yy] > F[x][y] + 10.000 + vv ) {
						F[xx][yy] = F[x][y] + 10.000 + vv ;
						Dfs(xx,yy) ;
					}
				}
			}
		}
	}
}

void Solve() {
	fo(i,1,N) fo(j,1,M) F[i][j] = INF ;
	F[1][1] = 0.000 ;
	Dfs( 1 , 1 ) ;
	cout.precision(8) ;
	cout << fixed << F[N][M] << "\n" ;
}

int	main() {
	freopen("B.in" ,"r" , stdin ) ;
	freopen("B.out","w" , stdout) ;
	int T ; cin >> T ;
	fo(i,1,T) {
		Init() ;
		cout << "Case #" << i << ": " ;
		Solve() ;
	}
}