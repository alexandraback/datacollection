#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <vector>
#include <map>
#include <queue>
#include <stack>
#include <string>
#include <algorithm>
#define MAX 2500
using namespace std ;
double D , a ;
int A , n ;
struct P
{
    double Time , Pos ;
};
P p[ MAX ] ;
int main( )
{
    freopen( "B-small-attempt0.in" , "r" , stdin ) ;
    freopen( "B_M.out" , "w" , stdout ) ;
    int t , T = 1 ;
    scanf( "%d" , &t ) ;
    while( t-- )
    {
        scanf( "%lf%d%d" , &D , &n , &A ) ;
        for( int i = 0 ; i < n ; i++ )
            scanf( "%lf%lf" , &p[ i ].Time , &p[ i ].Pos ) ;
        double ans = 0.0 , dis , tp = 0.0 , tt , t2 , t3 , vt ;
        bool f ;
        printf( "Case #%d:\n" , T++ ) ;
        for( int i = 0 ; i < A ; i++ )
        {
            scanf( "%lf" , &a ) ;
            tp = 0.0 ;
            tt = 0 ;
            for( int j = 1 ; j < n ; j++ )
            {
                if( p[ j ].Pos <= D )
                    f = 1 ;
                else
                    f = 0 ;
                if( f )
                {
                    dis = p[ j ].Pos - tp ;
                    tt = sqrt( dis * 2.0 / a ) ;
                    if( tt < p[ j ].Time )
                        vt = a * tt , tt = p[ j ].Time ;
                    else
                        tt = 0.0 ;
                    //printf( "pp1 %d %d %lf %lf\n" , i , j , tt , vt ) ;
                }
                if( f == 0 )
                {
                    dis = p[ j ].Pos - p[ j-1 ].Pos ;
                    t2 = p[ j ].Time - p[ j-1 ].Time ;
                    t3 = ( D - p[ j-1 ].Pos ) * t2 / dis + p[ j-1 ].Time ;
                    if( tt == 0.0 )
                        tt = sqrt( D * 2.0 / a ) ;
                    else
                    {
                        double ttt = ( -vt + sqrt( vt*vt+2.0*a*(D-p[ j-1 ].Pos) ) ) / a ;
                        //printf( "ttt %lf %lf\n" , vt , ttt ) ;
                        tt += ttt ;
                    }

                    //printf( "pp2 %d %d %lf %lf\n" , i , j , tt , t3 ) ;
                    if( tt < t3 )
                        tt = t3 ;
                    break ;
                }
            }
            if( tt == 0.0 )
                tt = sqrt( D * 2.0 / a ) ;
            printf( "%.8lf\n" , tt ) ;
        }
    }
    return 0 ;
}
