#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
#include <cmath>
#include <queue>
#include <vector>
using namespace std;
double cal( double c , double f , double x , int t )
{
    double ans = 0.0 , p = 2.0;
    for( int i=0 ; i<t ; i++ )
    {
        ans += c / p;
        if( c / p < 1e-10 ) break;
        p += f;
    }
    return ans + x / ( t * f + 2.0 );
}
int main()
{
    freopen("B-small-attempt0.in", "r", stdin);
    freopen("out.txt", "w", stdout);
    int t;
    double c , f , x;
    scanf( "%d" , &t );
    for( int cas=1 ; cas<=t ; cas++ )
    {
        scanf( "%lf %lf %lf" , &c , &f , &x );
        double tt = x / c - 2.0 / f - 1.0;
        int pt = (int)tt;
        if( pt < 0 ) pt = 0;
        double a1 = cal( c , f , x , pt );
        double a2 = cal( c , f , x , pt+1 );
        if( a1 - a2 < 1e-9 ) a2 = a1;
        printf( "Case #%d: %.7lf\n" , cas , a2 );
    }
    return 0;
}
