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

int a[mnx], n;
int calc( int v ){
    int ret = v;
    for( int i = 1; i <= n; ++i ){
        if( a[i] > v ){
            ret += ( a[i] + v - 1 ) / v - 1;
        }
    }
    return ret;
}
int main(){
    freopen( "tt.txt", "r", stdin );
    freopen( "out.txt", "w", stdout );
    int cas, kk = 1;
    scanf( "%d", &cas );
    while( cas-- ){
        int mx = 0, ans = inf;
        scanf( "%d", &n );
        for( int i = 1; i <= n; ++i ){
            scanf( "%d", &a[i] );
            mx = max( a[i], mx );
        }
        for( int i = 1; i <= mx; ++i ){
            ans = min( ans, calc( i ) );
        }
        printf( "Case #%d: %d\n", kk++, ans );
    }
    return 0;
}
