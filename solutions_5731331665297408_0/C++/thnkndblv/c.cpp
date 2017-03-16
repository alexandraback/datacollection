using namespace std;

#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

#include "iostream"
#include "string"
#include "stdio.h"
#include "algorithm"
#include "math.h"
#include "vector"
#include "string.h"
#include "stack"

int N, M;
vector< string > zipCode;
bool g[ 10 ][ 10 ];

int bitCount(int mask)
{
	int ret = 0;

	while ( mask != 0 )
	{
		if ( mask & 1 ) ret++;
		mask >>= 1;
	}

	return ret;
}

string Answer;
void backtrack(stack< int > S, int mask, string Current)
{
	if ( mask == 0 )
	{
		if ( Current < Answer ) Answer = Current;
	}
	else
	{
		while ( S.size() >= 1 )
		{
			int v = S.top();

			for (int w = 0; w < N; w++)
				if ( g[ v ][ w ] && (mask & (1 << w)) )
				{
					stack< int > nS = S;
					nS.push( w );
					backtrack( nS, mask ^ (1 << w), Current + zipCode[ w ] );
				}

			S.pop();
		}
	}
}

int main()
{
	int ntc;

	cin >> ntc;
	for (int tc = 1; tc <= ntc; tc++)
	{
		cin >> N >> M;

		zipCode.assign( N, "" );
		for (int i = 0; i < N; i++) cin >> zipCode[i];

		memset( g, 0, sizeof g );

		for (int i = 0; i < M; i++)
		{
			int u, v;
			scanf("%d %d", &u, &v);

			u--;
			v--;

			g[u][v] = g[v][u] = true;
		}

		Answer = string( 5 * N, 'X' );

		for (int v = 0; v < N; v++)
		{
			stack< int > stk;
			stk.push( v );
			backtrack( stk, ((1 << N) - 1) ^ (1 << v), zipCode[ v ] );
		}

		cout << "Case #" << tc << ": " << Answer << endl;
	}
	
    return 0;
}