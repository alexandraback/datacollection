/*
TASK: C
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

inline int epscmp( double a , double b ){
    if( fabs(a-b) < EPS )
        return 0;
    else if( a + EPS < b )
        return -1;
    else
        return 1;
}

const int MAXR = 1 << 10;

int R, N, M, K;

int pr[MAXR];

void clear(){
    ///Warning: Clear everything used by a test!
}

void read(){
    /// Input read goes here
    
    for( int i = 0 ; i < K ; i++ )
        scanf("%d", pr + i);
}

void solve( int testid ){
    /// Solution goes here
    
    vector< vector<int> > sol;
    
    for( int i = 2 ; i <= M ; i++ ){
        for( int j = 2 ; j <= M ; j++ ){
            for( int k = 2 ; k <= M ; k++ ){
                int mypr[] = { 1 , i , j , i * j , k , k * i , k * j , k * i * j };
                
                bool ok = true;
                
                for( int t = 0 ; t < K and ok ; t++ ){
                    if( find( mypr , mypr + 8 , pr[t] ) == mypr + 8 )
                        ok = false;
                }
                
                if( ok ){
                    vector<int> mysol;
                    mysol.push_back(i);
                    mysol.push_back(j);
                    mysol.push_back(k);
                    sol.push_back( mysol );
                }
            }
        }
    }
    
    /// Warning: The " " after : INCLUDED!!!
    //printf("Case #%d: ", testid+1);
    /// Output goes here:
    
    if( sol.empty() ){
        for( int i = 0 ; i < N ; i++ )
            printf("222");
    }else{
        printf("%d%d%d", sol[0][0], sol[0][1], sol[0][2]);
    }
    
    /// I take care of the newline!
    printf("\xA");
}

int main(){
    freopen( "C.in" , "r" , stdin );
    freopen( "C.out" , "w" , stdout );
    
    int numtests;
    
    scanf("%*d %d %d %d %d", &R, &N, &M, &K); /// skip T = 1
    
    printf("Case #1:\n");
    
    for( int i = 0 ; i < R ; i++ ){
        clear();
        read();
        solve( 1 );
    }
    
    return 0;
}
