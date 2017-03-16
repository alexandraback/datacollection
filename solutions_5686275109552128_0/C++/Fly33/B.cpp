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
    static const int MAXP = 1001;
	int Result;
    int D;
    int P[ MAXP ];

public:
	void Work()
	{
        int i, k;
        Result = MAXP;
        for( k = 1; k <= MAXP; ++k )
        {
            int r = k;
            for( i = 0; i < D; ++i )
            {
                r += (P[i]-1) / k;
            }
            if( Result > r )
                Result = r;
        }
	}
	
	void Read()
	{
        int i;
		scanf( "%d", &D );
        for( i = 0; i < D; ++i )
        {
            scanf( "%d", &P[i] );
        }
	}

	void Write( int t )
	{
		printf( "Case #%d: %d\n", t, Result );
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
