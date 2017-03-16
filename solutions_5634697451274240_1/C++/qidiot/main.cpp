#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
#include <cmath>
using namespace std;
char str[110];
int main()
{
    freopen("B-large.in","r",stdin);
    freopen("B-large.out","w",stdout);
    int T , n;
    scanf( "%d" , &T );
    for( int cas = 1 ; cas <= T ; cas++ )
    {
        scanf( "%s" , str );
        int ln = strlen(str);
        int ans = 0;
        for( int i=1 ; i<ln ; i++ )
        {
            if( str[i-1] != str[i] ) ans++;
        }
        if( str[ln-1] == '-' ) ans++;
        printf( "Case #%d: %d\n" , cas , ans );
    }
    return 0;
}
