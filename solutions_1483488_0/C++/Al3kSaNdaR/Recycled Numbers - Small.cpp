/*
    Aleksandar "Al3kSaNdaR" Ivanovic

    Recycled Numbers - Small
*/
#include <cstdio>
#include <cstring>
#include <string>
#include <iostream>
#include <algorithm>
#include <set>

using namespace std;

int T, A, B;
string StrA, StrB;

inline int ToNumber ( string Number )
{
    int Ret = 0, Len = Number.length ( );

    for ( int i = 0; i < Len; i++ ) Ret = Ret * 10 + Number[i] - '0';

    return Ret;
}

inline string ToString ( int Number )
{
    string Ret = "";

    while ( Number )
    {
        char Digit = Number % 10 + '0';

        Number /= 10;

        Ret += Digit;
    }

    reverse ( Ret.begin ( ), Ret.end ( ) );

    while ( ( ! Ret.empty ( ) ) && ( Ret[0] == '0' ) ) Ret.erase ( 0, 1 );

    return Ret;
}

int main ( void )
{
    freopen ( "C-small-attempt0.in", "r", stdin );
    freopen ( "C-small-attempt0.out", "w", stdout );

    cin >> T;

    for ( int i = 0; i < T; i++ )
    {
        cin >> A >> B;

        StrA = ToString ( A );
        StrB = ToString ( B );

        int Cnt = 0, Len = StrA.length ( );

        for ( int j = A; j <= B; j++ )
        {
            string Str = ToString ( j );

            set < int > S;

            for ( int k = 1; k < Len; k++ )
            {
                string Curr = Str.substr ( k ) + Str.substr ( 0, k );

                int Number = ToNumber ( Curr );

                if ( S.find ( Number ) != S.end ( ) ) continue;

                S.insert ( Number );

                if ( ( A <= Number ) && ( Number <= B ) && ( Number > j ) ) Cnt++;
            }
        }

        cout << "Case #" << i + 1 << ": " << Cnt << endl;
    }

    return 0;
}
