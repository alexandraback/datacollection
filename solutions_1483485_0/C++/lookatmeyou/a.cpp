#include <stdio.h>
char x[26] = {'y','h','e','s','o','c','v','x','d','u','i','g','l','b','k','r',
                'z','t','n','w','j','p','f','m','a','q'};
int main( int argc, char *argv[] )
{
    //freopen( "A-small-attempt0.in", "r", stdin );
    //freopen( "A-small-attempt0.out", "w", stdout );
    int t, i, cas = 0;
    char g[105];
    scanf( "%d", &t );
    getchar();
    while ( t-- ) {
        gets( g );
        for ( i = 0; g[i]; ++i ) {
            if ( g[i] == ' ' ) continue;
            g[i] = x[g[i]-'a'];
        }
        printf( "Case #%d: %s\n", ++cas, g );
    }
    return 0;
}
