#include <vector>
#include <map>
#include <algorithm>
#include <sstream>
#include <iostream>
#include <cstdio>
#include <cmath>
#include <queue>
#include <cstring>
using namespace std ;

#define FOREACH(it,c) for( __typeof((c).begin()) it=(c).begin();it!=(c).end();it++)
#define FOR(i,a,b) for( int i=(a),_b=(b);i<=_b;i++) 
#define DOW(i,b,a) for( int i=(b),_a=(a);i>=_a;i--)
#define REP(i,n) FOR(i,0,(n)-1)
#define DEP(i,n) DOW(i,(n)-1,0)
#define all(a) (a).begin() , (a).end()

typedef vector<int> VI ;
typedef vector<string> VS ;
template<class T> inline int size(const T&c) { return c.size(); }  

int H, N, M ;
int Ceil[107][107] ;
int Floor[107][107] ;
double C[107][107] ;
int mark[107][107] ;
priority_queue< pair<double, pair<int, int> > > Q;

int inside( int x, int y)
{
	return x > 0 && x <= N && y > 0 && y <= M ;
}

int h0[4] = {0, -1, +0, +1};
int h1[4] = {-1, +0, +1, +0};

main()
{
	int test ;
	scanf("%d",&test);
	FOR(Case,1,test)
	{
		memset( mark, 0, sizeof(mark) ) ;
		scanf("%d%d%d", &H, &N, &M) ;
		FOR(i,1,N)
			FOR(j,1,M) scanf("%d", &Ceil[i][j]) ;
		FOR(i,1,N)
			FOR(j,1,M) scanf("%d", &Floor[i][j]) ;
		
		FOR(i,1,N)
			FOR(j,1,M) C[i][j] = 1000000000;
		C[1][1] = 0 ;
		vector< pair<int, int> > q = vector< pair<int, int> >();
		q.push_back( make_pair(1, 1) ) ;
		
		Q = priority_queue< pair<double, pair<int, int> > >();
		Q.push( make_pair( 0, make_pair( 1, 1) ) );

		while ( Q.size() )
		{
			double time = -Q.top().first ;
			int x = Q.top().second.first ;
			int y = Q.top().second.second ;			
			Q.pop() ;			
			if ( mark[x][y] )
				continue;			
			mark[x][y] = 1;
			
			if ( x == N && y == M )
				break;
			
			REP(z,4)
			{
				int dd = x + h0[z] ;
				int cc = y + h1[z] ;
				
				if ( !inside(dd,cc) || mark[dd][cc])
					continue;				
				
				if ( max( Floor[x][y], Floor[dd][cc] ) + 50 > Ceil[dd][cc] )
					continue;
				if ( Floor[dd][cc] + 50 > Ceil[x][y] )
					continue;
								
				double newTime = time ;
				if ( H - time * 10 + 50 > Ceil[dd][cc] ) newTime = ( H - ( Ceil[dd][cc] - 50 ) ) / 10.0 ;
				double mucNuoc = H - newTime * 10 ;
				
				double charge = 1000 ;
				if ( mucNuoc - Floor[x][y] < 20 ) charge = 10;
				else
					charge = 1;
				if ( abs(newTime) < 1e-7 ) charge = 0;
				
				if ( C[dd][cc] > newTime + charge )
				{
					C[dd][cc] = newTime + charge;
					Q.push( make_pair( -newTime - charge, make_pair(dd, cc)));
				}
			}
		}
		cout << "Case #" << Case << ": " ;
		printf("%.6lf\n", C[N][M]);
	}
}