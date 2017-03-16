#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
#include <cmath>
using namespace std;
int BF[1010] , top[1010];
int num[1010] , to[1010];
int DFS( int root )
{
    int nt = BF[root];
    if( nt <= 0 ) return 0;
    if( num[nt] != -1 )
    {
        return num[root] - num[nt] + 1;
    }
    else
    {
        num[nt] = num[root] + 1;
        to[nt] = max( to[nt] , num[nt] );
        return DFS( nt );
    }
}
int cir[510][2];
int main()
{
    freopen("C-small-attempt1.in","r",stdin);
    freopen("C-small-attempt1.out","w",stdout);
    int T , n , m;
    scanf( "%d" , &T );
    for( int cas = 1 ; cas <= T ; cas++ )
    {
        scanf( "%d" , &n );
        for( int i=1 ; i<=n ; i++ ) scanf( "%d" , &BF[i] );
        int p = 0;
        for( int i=1 ; i<=n ; i++ )
            if( BF[i] > 0 )
            {
                if( BF[ BF[i] ] == i )
                {
                    cir[p][0] = i; cir[p][1] = BF[i];
                    BF[ BF[i] ] = 0; BF[i] = 0;
                    p++;
                }
            }
        for( int i=1 ; i<=n ; i++ ) to[i] = 0;
        int mx = 0;
        for( int i=1 ; i<=n ; i++ )
        {
            for( int j=1 ; j<=n ; j++ ) num[j] = -1;
            num[i] = 0;
            mx = max( mx , DFS( i ) );
            //for( int j=1 ; j<=n ; j++ ) cout << num[j] << " "; cout << endl;
        }
        int sum = 0;
        for( int i=0 ; i<p ; i++ )
        {
            sum += to[ cir[i][0] ] + to[ cir[i][1] ] + 2 ;
        }
        printf( "Case #%d: %d\n" , cas , max( sum , mx ) );
    }
    return 0;
}
