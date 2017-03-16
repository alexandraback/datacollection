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
    static const int MAXS = 1012;
	int Result;
    int S;
    char C[ MAXS ];

public:
	void Work()
	{
        int sum = 0;
        Result = 0;
        for( int i = 0; i <= S; ++i )
        {
            if( Result + sum < i )
                Result = i - sum;
            sum += C[i] - '0';
        }
	}
	
	void Read()
	{
		scanf( "%d%s", &S, C );
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
