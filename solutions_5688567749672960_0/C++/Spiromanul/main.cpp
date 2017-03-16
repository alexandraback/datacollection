/*
 * Code by Spiromanul
 */

# include "fstream"
# include "cstring"
# include "vector"
# include "queue"
# include "bitset"
# include "algorithm"
# include "map"
# include "unordered_map"
# include "deque"
# include "string"
# include "iomanip"
# include "cmath"
# include "stack"
# include "cassert"

const char IN [ ] =  "input" ;
const char OUT [ ] = "output" ;
const int MAX = 3333014 ;

# define pb push_back
# define mp make_pair
# define FORN( a , b , c ) for ( int a = b ; a <= c ; ++ a )
# define FORNBACK( a , b , c ) for ( int a = b ; a >= c ; -- a )

using namespace std ;

ifstream cin ( IN ) ;
ofstream cout ( OUT ) ;

int dist [ MAX ] ;

int revers ( int n )
{
    int x = 0 ;
    while ( n ){
        x = x * 10 + n % 10 ;
        n /= 10 ;
    }
    return x ;
}
queue < int > Q ;
int main()
{
    memset ( dist , 0x3f , sizeof ( dist ) ) ;
    dist [ 1 ] = 1 ;
    Q.push ( 1 ) ;
    while ( !Q.empty ( ) )
    {
        int nod = Q.front ( ) ;
        Q.pop ( ) ;
        if ( dist [ nod ] + 1 < dist [ nod + 1 ] )
        {
            dist [ nod + 1 ] = dist [ nod ] + 1 ;
            Q.push ( nod + 1 ) ;
        }
        int aux = revers( nod ) ;
        if ( aux > 1000000 ) continue ;
        if ( dist [ nod ] + 1 < dist [ aux ] )
        {
            dist [ aux ] = dist [ nod ] + 1 ;
            Q.push ( aux ) ;
        }
    }

    int t ;
    cin >> t ;
    FORN ( i , 1 , t )
    {
        int n ;
        cin >> n ;
        cout << "Case #" << i << ": " << dist [ n ] << '\n' ;
    }
    return 0;
}
