#include <iostream>
#include <cstring>
using namespace std;

#define MAXNM  100

int N, M;
int pt[MAXNM][MAXNM] ;
int mhx[MAXNM], mhy[MAXNM];
int mxh ;

void input()
{
	cin >> N >> M ;
	memset ( mhx, 0, sizeof mhx ) ;
	memset ( mhy, 0, sizeof mhy ) ;
	mxh = 0;
	for ( int i=0;i<N;++i ) {
		for ( int j=0;j<M;++j ) {
			cin >> pt[i][j] ;
			int v = pt[i][j] ;
			if ( v > mhx[i] ) mhx[i] = v ;
			if ( v > mhy[j] ) mhy[j] = v ;
			if ( v > mxh ) mxh = v ;
		}
	}
}

#define YES "YES"
#define NO "NO"

bool resetX ( int x, int y, int h ) 
{
	if ( mhx[x] > h ) return false ;
	for ( int j=0;j<M;++j ) pt[x][j] = 0; 
	return true;
}

bool resetY ( int x, int y, int h ) 
{
	if ( mhy[y] > h ) return false ;
	for ( int i=0;i<M;++i ) pt[i][y] = 0; 
	return true;
}

const char * solve()
{
	for ( int h=1;h<=mxh; ++h ) {
		for ( int i=0;i<N;++i ) {
			for ( int j=0;j<M;++j ) {
				if ( pt[i][j] == h ) {
					bool tryx = resetX ( i, j, h ) ;
					bool tryy = resetY ( i, j, h ) ;
					if ( !tryx && !tryy ) return NO ;
				}
			}
		}
	}
	return YES;
}

int T, nCase = 1 ;

int main()
{
	cin >> T ;
	while(T--){
		input();
		cout << "Case #"<<nCase++<<": "<<solve() <<endl;
	}
	return 0;
}