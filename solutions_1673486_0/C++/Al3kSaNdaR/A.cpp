#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <functional>
#include <numeric>
#include <sstream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
#include <utility>

using namespace std;

typedef long long int lld;

typedef pair < int, int > pii;

const int MaxA = 99999 + 5;
const int MaxB = 100000 + 5;

int T, A, B;
double p1[MaxA], p2[MaxA], Cnt[10];

int main ( void )
{
    freopen ( "A-small-attempt0.in", "r", stdin );
    freopen ( "A-small-attempt0.out", "w", stdout );

    //freopen ( "A-large.in", "r", stdin );
    //freopen ( "A-large.out", "w", stdout );

    cin >> T;

    for ( int TestCase = 0; TestCase < T; TestCase++ )
    {
        cin >> A >> B;

        for ( int i = 0; i < A; i++ )
        {
            cin >> p1[i];

            p2[i] = 1 - p1[i];
        }


        for ( int i = 0; i < 10; i++ ) Cnt[i] = 0.000000;

        for ( int i = 0; i < ( 1 << A ); i++ )
        {
            double P = 1.000000;

            for ( int j = 0; j < A; j++ )
            {
                if ( i & ( 1 << j ) )
                {
                    P *= p1[j];
                }
                else
                {
                    P *= p2[j];
                }
            }

            int CntKeepTyping = 0, CntBackSpaceOnce = 0, CntBackSpaceTwice = 0, CntBackSpaceThrice = 0, CntEnter = 0;

            CntEnter += B + 2;

            CntKeepTyping += B - A + 1;

            if ( i != ( 1 << A ) - 1 ) CntKeepTyping += B + 1;

            bool Ok = false;

            for ( int j = 0; j < A - 1; j++ )
            {
                if ( i & ( 1 << j ) ) continue;

                Ok = true;
            }

            CntBackSpaceOnce += 1 + ( B - ( A - 1 ) ) + 1;

            if ( Ok ) CntBackSpaceOnce += B + 1;

            Ok = false;

            for ( int j = 0; j < A - 2; j++ )
            {
                if ( i & ( 1 << j ) ) continue;

                Ok = true;
            }

            CntBackSpaceTwice += 2 + ( B - ( A - 2 ) ) + 1;

            if ( Ok ) CntBackSpaceTwice += B + 1;

            Ok = false;

            for ( int j = 0; j < A - 3; j++ )
            {
                if ( i & ( 1 << j ) ) continue;

                Ok = true;
            }

            CntBackSpaceThrice += 3 + ( B - ( A - 3 ) ) + 1;

            if ( Ok ) CntBackSpaceThrice += B + 1;

            Cnt[0] += P * CntKeepTyping;

            if ( A >= 1 ) Cnt[1] += P * CntBackSpaceOnce;

            if ( A >= 2 ) Cnt[2] += P * CntBackSpaceTwice;

            if ( A >= 3 ) Cnt[3] += P * CntBackSpaceThrice;

            Cnt[4] += P * CntEnter;
        }

        double Sol = 9e9;

        if ( Cnt[0] < Sol ) Sol = Cnt[0];
        if ( Cnt[4] < Sol ) Sol = Cnt[4];

        if ( A >= 1 ) if ( Cnt[1] < Sol ) Sol = Cnt[1];
        if ( A >= 2 ) if ( Cnt[2] < Sol ) Sol = Cnt[2];
        if ( A >= 3 ) if ( Cnt[3] < Sol ) Sol = Cnt[3];

        printf ( "Case #%d: %.6lf\n", TestCase + 1, Sol );
    }

    return 0;
}
