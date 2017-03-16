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
#define SMALL_INPUT_FILE "C-small-attempt0.in"
#define OUTPUT_FILE "out.out1"


const int MAXN = 200 + 10 ;
const int LIMIT = 1 << 10 ;
const int MOD = 1000000007;

int S[ MAXN ] , n ;

void out(VI a){
	FOR(i,a.size()){
		if(i) cout << " " ;
		cout << a[i] ;
	}
	cout << endl;
}
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
		
		FOR( i , n ) cin >> S[i] ;
		
		int limit = 1 << n ;
		
		VI a , b ;
		bool fi = false;
		FOR( i , limit ){
			if( i == 0 || i == limit-1 ) continue;
			
			int sum = 0 ;
			a.clear();
			
			for( int j = 0 ; j < n ; j ++ ) if( i & (1<<j) ){
				a.push_back( S[j] ) ;
				sum += S[j] ;
			}
			
			int mask = (~i) & (limit-1);
			for( int o = mask ; o > 0 ;  o = (o-1)& mask ){
				int t = 0 ;
				b.clear();
				for( int j = 0 ; j < n ; j ++ ) if( o & (1<<j) ){
					t += S[j] ;
					b.push_back( S[j] );
				}
				if( sum == t ){ fi = true; break;}
			}
			if(fi)break;
			
		}
		

		cout << "Case #"<<tc<<":" << endl;
		if( fi ){
			out(a);
			out(b);
		}else{
			cout << "Impossible" << endl;
		}

	}
}

