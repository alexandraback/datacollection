/*
TASK: B
LANG: C++
*/
#include <iostream>
#include <cstdio>
#include <queue>
#include <stack>
#include <algorithm>
#include <cstring>
#include <numeric>
#include <ext/hash_map>
#include <ext/hash_set>
#include <cmath>
#include <cassert>
#include <map>
#include <vector>
#include <ctime>
#include <string>
#define foreach(_var,_container) for( typeof( (_container).begin() ) _var = (_container).begin() ; _var != (_container).end() ; ++_var )
#define now() double( double( clock() ) / double( CLOCKS_PER_SEC ) )
#if 1
#define eprintf(msg, ... ) fprintf(stderr," %s:%d in %s at %.4lf :: " msg "\xA" , strrchr( __FILE__ , '\\' )+1 , __LINE__ , __FUNCTION__ , now() , ##__VA_ARGS__ )
#else
#define eprintf(msg, ... ) 0
#endif
#define pprintf(msg, ... ) fprintf(stderr," %s:%d in %s at %.4lf :: " msg "\xA" , strrchr( __FILE__ , '\\' )+1 , __LINE__ , __FUNCTION__ , now() , ##__VA_ARGS__ )

using namespace std;
using namespace __gnu_cxx;

typedef long long ll;
typedef pair<int,int> PII;

#define PB push_back
#define MP make_pair
#define CLEAR0(x) memset( (x) , 0 , sizeof((x)) )
#define CLEAR1(x) memset( (x) , -1 , sizeof((x)) )

const double EPS = 1e-9;
const ll INF = 1LL << 60;


const int MAXE = 1 << 4;
const int MAXN = 10001;

inline int epscmp( double a , double b ){
    if( fabs(a-b) < EPS )
        return 0;
    else if( a + EPS < b )
        return -1;
    else
        return 1;
}

int E, R, N;
int v[MAXN];


void clear(){
    ///Warning: Clear everything used by a test!
}

void read(){
    /// Input read goes here
    scanf("%d %d %d", &E, &R, &N);
    
    for( int i = 0 ; i < N ; i++ )
        scanf("%d", v + i);
}
/*
dp[act][e] = 
    max{
        dp[act + 1][ min( E , e + R ) ],
        dp[act + 1][ i + R ] + (e - i) * v[act]
            = dp[act + 1][ i + R ] + e v[act] - i v[act]
            = dp[act + 1][ e - de + R ] + de * v[act]
            for each i
    }
*/
int dp[MAXE][MAXN];

int get( int act , int e ){
    if( act == N )
        return 0;
    
    int &self = dp[act][e];
    
    if( self != -1 )
        return self;
    
    self = get( act + 1 , min ( E , e + R ) );
    
    for( int i = 0 ; i <= e ; i++ ){
        self = max( self , get( act + 1 , min( E , i + R ) ) + (e - i) * v[act] );
    }
    
    return self;
}

void solve( int testid ){
    /// Solution goes here
    
    CLEAR1( dp );
    
    /// Warning: The " " after : INCLUDED!!!
    printf("Case #%d: ", testid+1);
    /// Output goes here:
    
    printf("%d", get( 0 , E ));
    
    /// I take care of the newline!
    printf("\xA");
}

int main(){
    freopen( "B.in" , "r" , stdin );
    freopen( "B.out" , "w" , stdout );
    
    int numtests;
    
    scanf("%d", &numtests);
    
    for( int i = 0 ; i < numtests ; i++ ){
        clear();
        read();
        solve( i );
    }
    
    return 0;
}
