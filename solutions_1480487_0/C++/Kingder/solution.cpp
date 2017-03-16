#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <string>
#include <vector>
#include <climits>
#include <queue>

#define FOR(i,n) for(int i=0;i<n;i++)
#define FORE(i,a,b) for(int i=(a);i<=(b);i++)

using namespace std;

typedef long long LL;
typedef vector<int> VI;

template<class T> void checkmin(T& a,T b){if(a>b)a=b;}
template<class T> void checkmax(T& a,T b){if(a<b)a=b;}
LL gcd(LL a,LL b){return b?gcd(b,a%b):a;}

#define FILE_IN_OUT
//#define LARGE
//#define DEBUG
#define LARGE_INPUT_FILE "A-small-attempt0.in"
#define SMALL_INPUT_FILE "A-small-attempt4.in"
#define OUTPUT_FILE "out.out1"


const int MAXN = 200 + 10 ;
const int LIMIT = 1 << 10 ;
const int MOD = 1000000007;

int S[ MAXN ] , n ;

int main(){


#ifdef FILE_IN_OUT
	#ifdef LARGE
		freopen( LARGE_INPUT_FILE,"r",stdin);
	#else
		freopen( SMALL_INPUT_FILE,"r",stdin);
	#endif
		
	freopen( OUTPUT_FILE,"w",stdout);
#endif
	
	int T ; cin >> T ;
	FORE( tc , 1 , T){
		cin >> n ;
		
		int sum = 0 ;
		double lo = 0 ;
		FOR( i , n ) {cin >> S[i] ;sum += S[i]; if(lo<S[i])lo=S[i];}

		cout << "Case #"<<tc<<":";
		FOR( i , n ){

			double l = 0 , h = 1;
			for( int ii = 0 ; ii < 400 ; ii ++){
				double m = ( l + h ) / 2;
				double dest = S[i] + m*sum;
				double x = (1-m)*sum;
				double lo = 0 , hi = 1e30;
				for( int iii = 0 ; iii < 300 ; iii ++ ){
					double md = ( lo + hi ) / 2;
					double s = 0 ;
					for( int k = 0 ; k < n ; k ++ )if( k != i ){
						s += md - S[k];
					}
					if( s > x ) hi = md;
					else lo = md;
				}
				if( dest < (lo+hi)/2 ) l = m;
				else h = m;
			}
			printf(" %.10lf", (l+h)*100/2);

		}
		cout << endl;
		/*
		double  hi = 1e30;
		for( int i = 0 ; i < 1000  ; i ++ ){
			double mid = ( lo + hi ) / 2;
			double x = 0;
			FOR( k , n )x += mid - S[k] ;
			if(x<sum) lo = mid;
			else hi = mid;
			
		}
		//printf("%.10lf %.10lf\n" , lo , hi);
		lo = (lo+hi)/2;
		cout << "Case #"<<tc<<":";
		FOR( i , n ){
			printf(" %.10lf" , (lo - S[i]) * 100 / sum );
		}
		cout << endl;
		*/

	}
	
}