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
#define SMALL_INPUT_FILE "C-small-attempt0.in"
#define OUTPUT_FILE "out.out1"


const int MAXN = 200 + 10 ;
const int LIMIT = 1 << 10 ;
const int MOD = 1000000007;

typedef vector<pair<LL,int> > VP; 
#define MP make_pair

void init( VP& A , int n , LL a[] , int b[]){

	A.push_back( MP(a[0],b[0]));
	FORE( i ,1, n-1){
		if( A[A.size()-1].second == b[i] ){
			A[A.size()-1].first += a[i];
		}else{
			A.push_back( MP(a[i],b[i]));
		}
	}


}

void update( LL& a , LL b){
	if( a==-1||a<b)a=b;
}
void show(VP& A){
	FOR( i , A.size() ) cout << A[i].first << " " << A[i].second << endl;
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
		int N , M ;
		cin >> N >> M ;
		LL Ai[ MAXN ] ,Bi[ MAXN ];
		int Ac[ MAXN ] , Bc[ MAXN ];
		bool kind[MAXN] ;fill(kind,kind+MAXN,false);
		FOR( i , N ) {cin >> Ai[ i ] >> Ac[ i ];kind[Ac[i]]=true;}
		FOR( i , M ) {cin >> Bi[ i ] >> Bc[ i ];kind[Bc[i]]=true;}
		
		VP A , B;
		
		init( A , N , Ai , Ac );
		init(B,M,Bi,Bc);
		
		//cout << "A:" << endl;
		//show(A);
		//cout << "B:" << endl;
		//show(B);
		
		LL dp[ MAXN ][ MAXN ] ;
		
		memset( dp , -1 , sizeof(dp) ) ;
		dp[0][0] = 0 ;
		
		N = A.size(); 
		M = B.size();

		LL ret = 0 ;
		FOR( i , N+1 )FOR( j , M+1 )if(dp[i][j] != -1 ){
			// keep first ;
			FORE( k , 1, 100 )if(kind[k]){
				
				LL na = 0;
				FORE( ni , i , N-1){
					if( A[ni].second == k ) na += A[ni].first;
					LL nb = 0 ;
					FORE( nj , j, M-1 ){
						if( B[nj].second == k ) nb += B[nj].first;
						update( dp[ni+1][nj+1] , dp[i][j] + min( na,nb) );
						
					}
				}

			
			}
			checkmax( ret , dp[i][j] );
		}
		cout << "Case #"<<tc<<": " << ret << endl;
		int a , b ;
		//while( cin >> a >> b ) cout<< dp[a][ b] << endl;
		//cout << dp[2][1] << endl;
	}
	
}