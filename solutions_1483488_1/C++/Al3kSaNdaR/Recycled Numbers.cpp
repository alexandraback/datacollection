/*
    Aleksandar "Al3kSaNdaR" Ivanovic

    Recycled Numbers
*/
#include <cstdio>
#include <cstring>
#include <string>
#include <iostream>
#include <algorithm>
#include <set>

using namespace std;

const int MaxN = 10 + 5;
const int MaxNumber = 2000000 + 5;

int T, A, B, N, Numbers[MaxN];
bool Mark[MaxNumber];

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
    freopen ( "C-large.in", "r", stdin );
    freopen ( "C-large.out", "w", stdout );

    cin >> T;


    for ( int i = 0; i < T; i++ )
    {
        cin >> A >> B;

        string StrA = ToString ( A ), StrB = ToString ( B );

        int Cnt = 0, Len = StrA.length ( ), Pow = 1;

        for ( int j = 0; j < Len - 1; j++ ) Pow *= 10;

        for ( int j = A; j <= B; j++ )
        {
            int Pow1 = Pow, Pow2 = 10;

            N = 0;

            for ( int k = 0; k < Len - 1; k++ )
            {
                int Number = j / Pow2 + ( j % Pow2 ) * Pow1;

                Pow1 /= 10;
                Pow2 *= 10;

                if ( ( Number < A ) || ( Number > B ) || ( Number <= j ) ) continue;

                if ( Mark[Number] ) continue;

                Mark[Number] = true;

                Numbers[N++] = Number;

                Cnt++;
            }

            for ( int k = 0; k < N; k++ ) Mark[Numbers[k]] = false;
        }

        cout << "Case #" << i + 1 << ": " << Cnt << endl;
    }

    return 0;
}
