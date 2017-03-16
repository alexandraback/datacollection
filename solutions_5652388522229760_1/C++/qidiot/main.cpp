#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
#include <cmath>
using namespace std;
bool ck[11];
int main()
{
    freopen("A-large.in","r",stdin);
    freopen("A-large.out","w",stdout);
    int T , n;
    scanf( "%d" , &T );
    for( int cas = 1 ; cas <= T ; cas++ )
    {
        scanf( "%d" , &n );
        memset( ck , 0 , sizeof(ck) );
        int sum = 0;
        if( n == 0 )
        {
            printf( "Case #%d: INSOMNIA\n" , cas );
            continue;
        }
        long long round = 0;
        while( sum < 10 )
        {
            round++;
            long long y = round * n;
            while( y )
            {
                int x = y % 10;
                if( !ck[x] )
                {
                    ck[x] = 1; sum++;
                }
                y /= 10;
            }
        }
        printf( "Case #%d: %I64d\n" , cas , round * n );
    }
    return 0;
}
