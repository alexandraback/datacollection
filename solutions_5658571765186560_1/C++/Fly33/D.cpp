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
    bool Result;
    int X, R, C;
public:
	void Work()
	{
        Result = true;

        if( X == 1 )
            ;
        else if( X == 2 )
        {
            if( R * C % 2 != 0 )
                return;
        }
        else if( X == 3 )
        {
            if( R * C % 3 != 0 )
                return;
            if( R < 2 )
                return;
            if( C < 2 )
                return;
        }
        else if( X == 4 )
        {
            if( R * C % 4 != 0 )
                return;
            if( R < 3 )
                return;
            if( C < 3 )
                return;
        }
        else if( X == 5 )
        {
            if( R * C % 5 != 0 )
                return;
            if( R < 3 )
                return;
            if( C < 3 )
                return;
            if( C == 3 && R == 5 )
                return;
            if( R == 3 && C == 5 )
                return;
        }
        else if( X == 6 )
        {
            if( R * C % 6 != 0 )
                return;
            if( R < 4 )
                return;
            if( C < 4 )
                return;
        }
        else
            return;

        Result = false;
    }
	
	void Read()
	{
        scanf( "%d%d%d", &X, &R, &C );
	}

	void Write( int t )
	{
		printf( "Case #%d: %s\n", t, Result ? "RICHARD" : "GABRIEL" );
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
