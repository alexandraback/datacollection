#include<iostream>
#include<cstring>
#include<algorithm>
#include<cstdio>
#include<string>
#include<queue>
#include<cmath>

using namespace std;

#define mnx 10050
#define LL long long
#define inf 0x3f3f3f3f
#define MP make_pair
#define lson l, m, rt << 1
#define rson m+1, r, rt << 1 | 1
#define mod 9973

int n, R, C;
bool gao(){
    if( n == 1 ) return 0;
    if( n == 2 ){
        if( R * C % 2 ) return 0;
        else return 1;
    }
    if( n == 3 ){
        if( R * C % 3 ) return 0;
        else{
            if( (R%3==0&&C%2==0) || (R%2==0&&C%3==0) )
                return 1;
            else return 0;
        }
    }
    if( n == 4 ){
        if( R * C % 4 ) return 0;
        else{
            if( R * C == 4 ) return 0;
        }
    }
}
int main(){
    freopen( "tt.txt", "r", stdin );
    freopen( "out.txt", "w", stdout );
    int cas, kk = 1;
    scanf( "%d", &cas );
    while( cas-- ){
        scanf( "%d%d%d", &n, &R, &C );
        printf( "Case #%d: ", kk++ );
        if( gao() )
            puts( "GABRIEL" );
        else puts( "RICHARD" );
    }
    return 0;
}
