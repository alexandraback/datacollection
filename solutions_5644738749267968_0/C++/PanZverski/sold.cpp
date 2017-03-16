#include <stdio.h>
#include <string.h>
#include <set>

#define MAXN 1234

typedef std::set< int > Set;

int solve_deceitful_war( Set naomi, Set ken )
{
    int res = 0;
    while( true )
    {
        Set::iterator it = naomi.begin();
        for( ; it != naomi.end() && ken.lower_bound( *it ) == ken.begin(); ++ it );
        if( it == naomi.end() )
            break;
        
        ken.erase( ken.begin() );
        naomi.erase( it );
        ++ res;
    }
    return res;
}

int solve_war( Set naomi, Set ken )
{
    int res = 0;
    for( Set::reverse_iterator i = naomi.rbegin(); i != naomi.rend(); ++ i )
    {
        Set::iterator t = ken.lower_bound( *i );
        if( t != ken.end() )
            ken.erase(t);
        else
        {
            ken.erase( ken.begin() );
            ++ res;
        }
    }
    return res;
}

int read_block()
{
    char buf[23];
    scanf( "%s", buf );
    static int pow10[] = { 100000, 10000, 1000, 100, 10, 1 };
    int res = 0, i = 0;
    for( char *pc = buf; *pc; ++pc )
        if( *pc != '.' )
        {
            res += pow10[ i ] * ( *pc - '0' );
            ++i;
        }
    return res;
}

void read_blocks( Set & a, int n )
{
    for( int i = 0; i < n; ++ i )
        a.insert( read_block() );
}

int main()
{
    //freopen( "in.txt", "rt", stdin );
    int tc;
    scanf("%d", &tc );
    for( int test = 1; test <= tc; ++ test )
    {
        Set naomi;
        Set ken;
        int n;
        scanf( "%d", &n);
        read_blocks( naomi, n );
        read_blocks( ken, n );

        int a = solve_deceitful_war( naomi, ken );
        int b = solve_war( naomi, ken );

        printf( "Case #%d: %d %d\n", test, a, b );
    }

    return 0;
}

