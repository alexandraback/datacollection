#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
#include <cmath>
#include <queue>
#include <vector>
using namespace std;
double a[1010] , b[1010];
int cal1( int n )
{
    int p = 0;
    while( p < n )
    {
        int i = 0;
        for( ; i<n-p ; i++ )
            if( a[i+p] - b[i] > 1e-9 );
            else break;
        if( i >= n - p ) return n - p;
        p++;
    }
    return 0;
}
int cal2( int n )
{
    int ans = 0 , p = 0;
    for( int i=0 ; i<n ; i++ )
    {
        while( p < n && a[i] - b[p] > 1e-9 ) p++;
        if( p >= n ) break;
        ans++; p++;
    }
    return n - ans;
}
int main()
{
    freopen("D-small-attempt0.in" , "r", stdin);
    freopen("out.txt", "w", stdout);
    int t , n;
    scanf( "%d" , &t );
    for( int cas=1 ; cas<=t ; cas++ )
    {
        scanf( "%d" , &n );
        for( int i=0 ; i<n ; i++ ) scanf( "%lf" , &a[i] );
        for( int i=0 ; i<n ; i++ ) scanf( "%lf" , &b[i] );
        sort( a , a + n );
        sort( b , b + n );
        //for( int i=0 ; i<n ; i++ ) cout << a[i] << " "; cout << endl;
        //for( int i=0 ; i<n ; i++ ) cout << b[i] << " "; cout << endl;
        int ans1 = 0 , ans2 = 0;
        ans1 = cal1( n );
        ans2 = cal2( n );
        printf( "Case #%d: %d %d\n" , cas , ans1 , ans2 );
    }
    return 0;
}
