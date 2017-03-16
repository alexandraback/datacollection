/*
PROB:msquare
NAME:chen_yu2
LANG:C++
*/
#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <cmath>
#include <map>
#include <algorithm>
#include <queue>
#define N 400005
using namespace std;


int n;
bool isCon( char c )
{
    return ( c != 'a' && c != 'e' && c != 'i' && c != 'o' && c != 'u' );
}
bool ok( string s )
{
    int res = 0;
    for ( int i = 0; i < s.length(); i++ )
    if ( isCon( s[ i ] ) )
    {
        res++;
        if ( res >= n )
        return true;
    }
    else
    res = 0;
    return false;
}
int casid;
int main()
{
    int cas;
    string s;
    freopen( "A-small-attempt2.in", "r", stdin );
    freopen( "A-small-attempt2.out", "w", stdout );
    scanf( "%d", &cas );
    while ( cas-- )
    {
        //scanf( "%s", str, &n );
        cin >> s >> n;
        int cnt = 0;
        for ( int size = n; size <= s.length(); size++ )
         for ( int i = 0; i <= s.length() - size; i++ )
         {
              string sub = s.substr( i, size );
              if ( ok( sub ) )
              cnt++;
         }
         printf( "Case #%d: ", ++casid );
         cout << cnt << endl;
    }

    return 0;
}

