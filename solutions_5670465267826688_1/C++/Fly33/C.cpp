#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <vector>
#include <set>
#include <string>
#include <map>
#include <cctype>
#include <cstdlib>
#include <cstring>
#include <functional>
#include <list>
#include <deque>
#include <algorithm>

using namespace std;

class Solution
{
    static const int MAXL = 10012;
	bool Result;
    int L;
    long long X;
    char S[ MAXL + 1 ];

    int Mlt( int i, int j )
    {
        static const int M[][5] = 
        {
            { 0,  0,  0,  0,  0 },
            { 0,  1,  2,  3,  4 },
            { 0,  2, -1,  4, -3 },
            { 0,  3, -4, -1,  2 },
            { 0,  4,  3, -2, -1 }
        };
        if( i > 0 )
            if( j > 0 )
                return M[i][j];
            else
                return -M[i][-j];
        else
            if( j > 0 )
                return -M[-i][j];
            else
                return M[-i][-j];
    };

    int CtoI( char s )
    {
        switch( s )
        {
        case 'i':
            return 2;
        case 'j':
            return 3;
        case 'k':
            return 4;
        default:
            return 0;
        }
    }

    int Pow( int x, long long y )
    {
        int i;
        int r = 1;
        int p = ( int )( y % 4 );
        for( i = 0; i < p; ++i )
            r = Mlt(r, x);
        return r;
    }

public:
	void Work()
	{
        int i, j;
        int r = 1;
        for( i = 0; i < L; ++i )
        {
            r = Mlt(r, CtoI(S[i]));
        }

        Result = false;

        if( Pow( r, X ) != -1 )
            return;

        int left = 1;
        for( j = 0; j < 4; ++j )
        {
            for( i = 0; i < L; ++i )
            {
                left = Mlt(left, CtoI(S[i]));
                if( left == 2 )
                    break;
            }
            if( i < L )
                break;
        }
        if( j == 4 )
            return;
        left = j * L + i + 1;

        int right = 1;
        for( j = 0; j < 4; ++j )
        {
            for( i = 0; i < L; ++i )
            {
                right = Mlt(CtoI(S[L-i-1]), right);
                if( right == 4 )
                    break;
            }
            if( i < L )
                break;
        }
        if( j == 4 )
            return;
        right = j * L + i + 1;


        if( left + right >= L * X )
            return;

        Result = true;
    }
	
	void Read()
	{
		scanf( "%d%lld", &L, &X );
        scanf( "%s", S );
	}

	void Write( int t )
	{
		printf( "Case #%d: %s\n", t, Result ? "YES" : "NO" );
	}
};

vector< Solution > solution;

int main()
{
	int i, t;
	scanf( "%d", &t );
	solution.resize( t );
	for( i = 0; i < t; ++i )
		solution[ i ].Read();
#pragma omp parallel for schedule(dynamic, 1)
	for( i = 0; i < t; ++i )
		solution[ i ].Work();
	for( i = 0; i < t; ++i )
		solution[ i ].Write( i + 1 );
	return 0;
}
