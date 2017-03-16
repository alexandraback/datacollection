#include <cstdio>
#include <algorithm>
#include <iostream>

using namespace std ;
const int MAXN = 101 ;
int A , N , ans ;
int a[MAXN] ;

void dfs( int i , int sum , int step )
{
    if ( sum > a[N-1] || i >= N )
    {
        ans = min( ans , step );
        return ;
    }
    if ( step > ans )
        return ;
    
    if ( sum > a[i] )
        dfs( i+1 , sum+a[i] , step ) ;
    else
    {
        if ( sum > 1 )
            dfs( i , sum*2-1 , step+1 ) ;
        dfs( i+1 , sum , step+1 ) ;
    }
}

int main()
{
    int test , testnum = 0 ;
    
    cin >> test ;
    while ( test-- )
    {
        cin >> A >> N ;
        for ( int i = 0 ; i < N ; ++i )
            cin >> a[i] ;
        sort( a , a+N ) ;
        
        ans = N ;
        dfs( 0 , A , 0 );
        
        printf( "Case #%d: %d\n" , ++testnum ,ans );
    }
    
    return 0;
}
