/*
    Aleksandar "Al3kSaNdaR" Ivanovic

    Speaking in Tongues
*/
#include <cstdio>
#include <cstring>
#include <string>
#include <iostream>

using namespace std;

int T, Len;
string G;

inline char Decrypt ( const char &C )
{
    if ( C == 'a' ) return 'y';
    if ( C == 'b' ) return 'h';
    if ( C == 'c' ) return 'e';
    if ( C == 'd' ) return 's';
    if ( C == 'e' ) return 'o';
    if ( C == 'f' ) return 'c';
    if ( C == 'g' ) return 'v';
    if ( C == 'h' ) return 'x';
    if ( C == 'i' ) return 'd';
    if ( C == 'j' ) return 'u';
    if ( C == 'k' ) return 'i';
    if ( C == 'l' ) return 'g';
    if ( C == 'm' ) return 'l';
    if ( C == 'n' ) return 'b';
    if ( C == 'o' ) return 'k';
    if ( C == 'p' ) return 'r';
    if ( C == 'q' ) return 'z';
    if ( C == 'r' ) return 't';
    if ( C == 's' ) return 'n';
    if ( C == 't' ) return 'w';
    if ( C == 'u' ) return 'j';
    if ( C == 'v' ) return 'p';
    if ( C == 'w' ) return 'f';
    if ( C == 'x' ) return 'm';
    if ( C == 'y' ) return 'a';
    if ( C == 'z' ) return 'q';

    return C;
}

int main ( void )
{
    freopen ( "A-small-attempt0.in", "r", stdin );
    freopen ( "A-small-attempt0.out", "w", stdout );

    cin >> T;

    getline ( cin, G );

    for ( int i = 0; i < T; i++ )
    {
        getline ( cin, G );

        cout << "Case #" << i + 1 << ": ";

        Len = G.length ( );

        for ( int j = 0; j < Len; j++ ) cout << Decrypt ( G[j] );

        cout << endl;
    }

    return 0;
}
