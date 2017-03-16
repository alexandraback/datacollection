#include <bits/stdc++.h>
using namespace std ;

string c , g , ag, ac;
int x , y, t ;
int ck[4] , gk[4] , n ;
int cse , ans ;
int my_abs( int x )
{
    if( x < 0 ) return -x ;
    return x ;
}

int convo( string s )
{
    int res = 0 , x ;
    for( int i = 0 ; i < n ; i++ )
    {
        res = res * 10 ;
        x = s[i] - '0' ;
        res += x ;
    }
    return res ;
}

void permutation( int a , int nn )
{
    int i ;
    if( a == nn  )
    {
        x = convo( c ) ;
        y = convo( g ) ;

        if( abs( x - y ) < ans )
        {
            //cout << "x " << x << endl ;
            //cout << "y " << y << endl ;
            ans = abs( x - y ) ;
            ag = g ;
            ac = c ;
        }
        else if ( abs( x - y ) == ans  )
        {
            if( c < ac ) ag = g , ac = c ;
            else if( c == ac && g < ag ) ag = g , ac = c ;
        }
        return ;

    }

    for( i = 0 ; i <= 9 ; i++)
    {

        if( a >= n )
        {
            if( gk[a%n] )g[a%n] = i + '0' ;
        }
        else
        {
            if( ck[a] )c[a] = i + '0' ;
        }

        permutation( a + 1, nn  ) ;
    }
}

int main()
{
    freopen("B-small-attempt1.txt", "r" , stdin ) ;
    freopen("ansBs.txt", "w+" , stdout ) ;
    cin >> t ;

    while(t--)
    {

        ans = 10000 ;
        cin >> c >> g ;
        n = c.size() ;
        memset( ck, 0 , sizeof(ck) ) ;
        memset( gk, 0 , sizeof(gk) ) ;
        for( int i = 0 ; i < n ; i++ )
        {
            if( c[i] == '?' ) ck[i] = 1 , c[i] = '0' ;
            if( g[i] == '?' ) gk[i] = 1 , g[i] = '0' ;
        }
        permutation(0 , 2 * n ) ;
        cout << "Case #"<<++cse<< ": " ;
        cout << ac << " "<< ag << endl ;
    }






    return 0 ;
}
