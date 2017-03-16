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

main()
{
	int test ;
	cin >> test ;
	FOR(Case,1,test)
	{
		int n ;
		int A[100];
		cin >> n ;
		REP(i, n) cin >> A[i] ;
		
		vector< pair<int, int> > vres = vector< pair<int, int> >() ;
		REP(i,1<<n) {
			int sum = 0 ;
			REP(j,n)
				if ( i & (1<<j) ) sum += A[j] ;
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
			cout << "Case #" << Case << ":" << endl <<  "Impossible" << endl ;
		else {
			cout << "Case #" << Case << ":" << endl ;
			int dem = 0;
			REP(i, n)
				if ( X & (1<<i) ) {
					dem += 1 ;
					if ( dem > 1 ) cout << " " ;
					cout << A[i] ;
				}
			cout << endl ;
			dem = 0 ;
			REP(i, n)
				if ( Y & (1<<i) ) {
					dem += 1 ;
					if ( dem > 1 ) cout << " " ;
					cout << A[i] ;
				}
			cout << endl ;
		}
	}
}