#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
#include <cmath>
using namespace std;
int num[2510];
int main()
{
    freopen("B-large.in","r",stdin);
    freopen("B-large.out","w",stdout);
    int T , n , m;
    scanf( "%d" , &T );
    for( int cas = 1 ; cas <= T ; cas++ )
    {
        scanf( "%d" , &n );
        memset( num , 0 , sizeof(num) );
        for( int i=0 ; i<2*n-1 ; i++ )
        {
            for( int j=0 ; j<n ; j++ )
            {
                scanf( "%d" , &m );
                num[m]++;
            }
        }
        printf( "Case #%d:" , cas );
        for( int i=1 ; i<=2500 ; i++ )
        {
            if( num[i] % 2 == 1 ) printf( " %d" , i );
        }
        printf( "\n" );
    }
    return 0;
}
