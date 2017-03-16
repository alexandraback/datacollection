#include <vector>
#include <map>
#include <algorithm>
#include <sstream>
#include <iostream>
#include <cstdio>
#include <cmath>
#include <queue>
#include <cstring>
#include <fstream>
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

int random( int n )
{
	return rand() % n ;
}

long long B[20] ;
vector<long long> xres;
vector<long long> yres;

void process(int n)
{
		vector< pair<long long, int> > vres = vector< pair<long long, int> >() ;
		REP(i,1<<n) {
			long long sum = 0 ;
			REP(j,n)
				if ( i & (1<<j) ) sum += B[j] ;
			vres.push_back( make_pair( sum, i ) ) ;
		}
		sort( all(vres) ) ;
		
		int X = -1 ;
		int Y = -1 ;
		REP(i, vres.size() ) 
		{
			if ( X > 0 || Y > 0 )
				break;
			FOR(j, i+1, vres.size()-1)
			{
				if ( vres[i].first != vres[j].first )
					break;
				if ( (vres[i].second & vres[j].second) != 0)
					continue;
				X = vres[i].second;
				Y = vres[j].second;
				break;
			}
		}
		if ( X < 0 )
			return;
		
		REP(i, n)
			if ( X & (1<<i) ) xres.push_back( B[i]) ;
		REP(i, n)
			if ( Y & (1<<i) ) yres.push_back( B[i]) ;
				
}

main()
{
	int test ;
	ofstream fout;
	fout.open("C-large.out");	
	cin >> test ;
	srand( 10 );
	FOR(Case,1,test)
	{
		int n ;
		long long A[507];
		cin >> n ;
		REP(i, n) cin >> A[i] ;
		xres = vector<long long> () ;
		yres = vector<long long> () ;
		REP(retry,50)
		{
			//REP(i, n)
				//B[i] = A[i] ;
			int dem = 15 ;
			DEP(i,n)
			{
				bool ok = random(100) < 4 && dem > 0 ;
				if ( ok || i < dem ) {
					dem -= 1 ;
					B[dem] = A[i] ;
				}
			}
			process( 15 );
			if ( xres.size() )
				break;
		}
		cout << "Case " << Case << endl ;
		if ( xres.size() ) 
		{
			fout << "Case #" << Case << ":" << endl ;
			REP(i, xres.size() )
			{
				if ( i ) fout << " " ;
				fout << xres[i] ;
			}
			fout << endl ;		
			
			REP(i, yres.size() )
			{
				if ( i ) fout << " " ;
				fout << yres[i] ;
			}
			fout << endl ;		
		}
		else
		{
			fout << "Case #" << Case << ": Impossible" << endl ;
		}
	}
	fout.close() ;
}