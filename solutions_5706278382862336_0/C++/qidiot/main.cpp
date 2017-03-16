#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
#include <cmath>
#include <queue>
#include <vector>
using namespace std;
bool check2( long long n )
{
    long long x = n;
    if( x <= 1 ) return false;
    while( x % 2 == 0 )
    {
        x /= 2;
    }
    if( x != 1 ) return false;
    return true;
}
long long gcd( long long a , long long b )
{
    if( b == 0 ) return a;
    while( a % b != 0 )
    {
        long long c = a % b;
        a = b; b = c;
    }
    return b;
}
int solve( long long a , long long b )
{
    long long c = gcd( a , b );
    a /= c; b /= c;
    if( a * 2 >= b ) return 1;
    if( a <= 1 )
    {
        int ans = 0;
        while( b % 2 == 0 )
        {
            b /= 2; ans++;
        }
        return ans;
    }
    return min( solve( 1 , b / 2 ) , solve( a - 1 , b / 2 ) ) + 1;
}
int main()
{
    freopen("A-small-attempt3.in" , "r", stdin);
    freopen("out.txt", "w", stdout);
    int T;
    long long a , b;
    scanf( "%d" , &T );
    for( int cas=1 ; cas<=T ; cas++ )
    {
        scanf( "%I64d/%I64d" , &a , &b );
        //cout << a << " " << b << endl;
        if( a == 0 )
        {
            printf( "Case #%d: impossible\n" , cas ); continue;
        }
        long long c = gcd( a , b );
        a /= c; b /= c;
        if( a == b ) printf( "Case #%d: 0\n" , cas );
        else if( !check2(b) ) printf( "Case #%d: impossible\n" , cas );
        else printf( "Case #%d: %d\n" , cas , solve( a , b ) );
    }
    return 0;
}
