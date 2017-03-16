#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <cstring>
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
#define SMALL_INPUT_FILE "A-small-attempt0.in"
#define OUTPUT_FILE "out.out1"


const int MAXN = 1000 + 10 ;
const int LIMIT = 1 << 10 ;
const int MOD = 1000000007;

typedef vector<pair<LL,int> > VP; 
#define MP make_pair


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
		int N ; cin >> N;
		VI edge[MAXN];

		FOR( i , N ){
			int M , t;
			cin >>  M ;
			FOR( j , M ) {cin >> t ; edge[i].push_back( t-1) ;}
		}

		bool fi = false;
		for( int i = 0 ; i < N ; i ++ ){
			
			queue<int> Q; Q.push( i ) ;
			
			bool vst[ MAXN ]; fill( vst , vst+MAXN , false);
			while( !Q.empty() ){
				int now = Q.front(); Q.pop();

				if( vst[ now ] ) {
					fi = true;
					break;
				}
				vst[now] = true;

				FOR( s , edge[now].size() ) Q.push( edge[now][s] ) ;
			} 
			if( fi ) break;
		}
		cout << "Case #" << tc << ": " ;
		if( fi ) cout << "Yes" << endl;
		else cout << "No" << endl;
	}
	
}