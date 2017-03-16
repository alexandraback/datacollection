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
		cin >> n ;
		int A[200] ;
		REP(i,n) cin >> A[i];
		int sum = 0;
		REP(i,n) sum += A[i];
		
		vector<double> vres = vector<double>();
		REP(i,n){
			double l = 0.0000001, r = 1.00000 ;
			while ( r - l > 1e-7 )
			{
				double mid = (l+r)/2 ;
				double percent = 1.0 - mid ;
				REP(j,n)
					if ( j != i && A[j] < A[i] + sum * mid ) {
						double them = ( A[i] + sum * mid - A[j] ) / sum ;
						percent -= them ;
					}
				
				if ( percent < 0 )
					r = mid ;
				else
					l = mid ;
			}
			vres.push_back(l);
		}	
		printf("Case #%d:", Case);
		REP(i,n) printf(" %.7lf", vres[i] * 100);
		printf("\n");
	}
}