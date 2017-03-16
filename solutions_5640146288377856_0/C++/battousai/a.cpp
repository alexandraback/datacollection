#pragma warning (disable: 4786)
#pragma comment (linker, "/STACK:26777216")
#include <bits/stdc++.h>

using namespace std;
typedef long long lint;
typedef unsigned long long ulint;
#define NN 25
#define MM 1000002
#define CLR( a ) memset( a , 0 , sizeof ( a ) )
#define negCLR( a ) memset( a , -1 , sizeof( a ) )
#define lld I64d
#define FOR(i,s,t) for(int i = (s); i <= (t); i++)
#define ROF(i,t,s) for(int i = (t); i >= (s); i--)

const lint MOD =  100000007;
const lint LINF = 1000000097999999903LL;
lint boundz = 10000000001LL;
const int INF = (1 << 29);
struct vert { int u, v; vert(){} vert( int a, int b ){ u = a; v = b; } };
int R, C, W, lena, lenb;
int arr[ NN ][ NN ];

void reset() {
    CLR( arr );
}
bool isValid( int a, int b ) { return a >= 1 && b >= 1 && a <= R && b <= C; }
int curr = 0;

int f( int a, int b ) {
     if( !isValid( a, b ))return 0;

     return 1;
}
int main() {
  //freopen("A-small-attempt1.in","r",stdin);
  //freopen("out.txt","w",stdout);
  int cases, caseno = 0; scanf("%d",&cases);
  while( cases-- ) {
    scanf("%d %d %d",&R, &C, &W);
    reset();
    int ret = 0;
    int  ith = 1, jth = 1;
    FOR( i, 1 , R ) {
        int j = 1;
        while( 1 ) {
            if( j + W - 1 <= C ) {
                j = j + W - 1;
                arr[ i ][ j ] = 1;
                ith = i;
                jth = j;
                j++;
                ret++;
            } else {
                break;
            }
        }
    }

    int rightRem = 0, leftRem = 0;
    int k = jth;
    while( 1 ) {
        k++;
        if( k > C || arr[ ith ][ k ]  ) { break; }
        rightRem++;
    }
    k = jth;
    while( 1 )  {
        k--;
        if( k < 1 || arr[ ith ][ k ] )break;
        leftRem++;
    }

    ret = ret + W - 1;
    if( leftRem > 0 && rightRem > 0 ) {
        ret++;
    }

    printf("Case #%d: %d\n",++caseno, ret);
  }
  return 0;
}
