/*
    Aleksandar "Al3kSaNdaR" Ivanovic

    Dancing With the Googlers
*/
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

const int MaxN = 100 + 5;
const int MaxSum = 30 + 5;

int T, N, S, p, t, CntSurprising[MaxSum], CntNormal[MaxSum], BestSurprising[MaxSum], BestNormal[MaxSum];
bool Mark[MaxN];

int main ( void )
{
    freopen ( "B-small-attempt0.in", "r", stdin );
    freopen ( "B-small-attempt0.out", "w", stdout );

    for ( int A = 0; A <= 10; A++ )
        for ( int B = A; B <= 10; B++ )
            for ( int C = B; C <= 10; C++ )
            {
                if ( B - A > 2 ) continue;
                if ( C - A > 2 ) continue;
                if ( C - B > 2 ) continue;

                bool Surprising = false;

                if ( B - A == 2 ) Surprising = true;
                if ( C - A == 2 ) Surprising = true;
                if ( C - B == 2 ) Surprising = true;

                if ( Surprising )
                {
                    CntSurprising[A + B + C]++;

                    BestSurprising[A + B + C] = max ( C, BestSurprising[A + B + C] );
                }
                else
                {
                    CntNormal[A + B + C]++;

                    BestNormal[A + B + C] = max ( C, BestNormal[A + B + C] );
                }
            }

    cin >> T;

    for ( int i = 0; i < T; i++ )
    {
        int Cnt = 0;

        vector < int > Numbers;

        cin >> N >> S >> p;

        for ( int j = 0; j < N; j++ )
        {
            cin >> t;

            if ( ! CntSurprising[t] )
            {
                if ( BestNormal[t] < p ) continue;

                Cnt++;

                continue;
            }

            Numbers.push_back ( t );
        }

        sort ( Numbers.begin ( ), Numbers.end ( ) );

        memset ( Mark, false, sizeof ( Mark ) );

        N = Numbers.size ( );

        if ( S ) for ( int j = 0; j < N; j++ )
                 {
                     if ( BestSurprising[Numbers[j]] < p ) continue;

                     Cnt++;

                     S--;

                     Mark[j] = true;

                     if ( ! S ) break;
                 }

        if ( S ) for ( int j = 0; j < N; j++ )
                 {
                     if ( Mark[j] ) continue;

                     Mark[j] = true;

                     S--;

                     if ( ! S ) break;
                 }

        for ( int j = 0; j < N; j++ )
        {
            if ( Mark[j] ) continue;

            if ( BestNormal[Numbers[j]] < p ) continue;

            Cnt++;
        }

        cout << "Case #" << i + 1 << ": " << Cnt << endl;
    }

    return 0;
}
