#include "stdio.h"
#include "string.h"
#include "math.h"
#include "set"
#include "algorithm"
#include <gmpxx.h>

using namespace std;

/**************** debug ***************/
//#define DBG 1
#ifdef DBG
#define chkpoint(...) { fprintf(stderr, "[%s:%d]", __func__, __LINE__);fprintf(stderr, __VA_ARGS__); };
#define debug(...) { fprintf(stderr, __VA_ARGS__); };
#else
#define chkpoint(...) 
#define debug(...) 
#endif
/**************** debug ***************/

/**************** Useful macro ***************/
#define MIN(a, b) (((a)<(b))?(a):(b))
#define MAX(a, b) (((a)>(b))?(a):(b))
#define SET_MIN(a, b) a = MIN(a, b)
#define SET_MAX(a, b) a = MAX(a, b)
#define MPZ2STR(x) (x.get_str(10).c_str())
/**************** Useful macro ***************/
int N, M, K;
int solve()
{
	if (K <= 4)
	{
		return K;
	}
	if (N>M) // N is always smaller
	{
		N = N+M; M = N-M; N = N-M;
	}

	if (N <= 2)
		return K;

	if (K == N*M)
		return 2*N + 2*M - 4;
	else if (K == N*M - 1)
		return 2*N + 2*M - 4 - 1;
	else if (K == N*M - 2)
		return 2*N + 2*M - 4 - 2;
	else if (K == N*M - 3)
		return 2*N + 2*M - 4 - 3;
	else if (K == N*M - 4)
		return 2*N + 2*M - 4 - 4;

	if (N == 3)
	{
		switch (K)
		{
			case 4:
				return 4;
			case 5:
				return 4;
			case 6:
				return 5;
			case 7:
				return 6;
			case 8:
				return 6;
			case 9:
				return 7;
			case 10:
				return 8;
			case 11:
				return 8;
			case 12:
				return 9;
			case 13:
				return 10;
			case 14:
				return 10;
			case 15:
				return 11;
			case 16:
				return 12;
			case 17:
				return 12;
			case 18:
				return 13;
		}
	}
	if (N == 4)
	{
		switch (K)
		{
			case 4:
				return 4;
			case 5:
				return 4;
			case 6:
				return 5;
			case 7:
				return 6;
			case 8:
				return 6;
			case 9:
				return 7;
			case 10:
				return 7;
			case 11:
				return 8;
			case 12:
				return 8;
			case 13:
				return 9;
			case 14:
				return 9;
			case 15:
				return 10;
			case 16:
				return 10;
			case 17:
				return 11;
			case 18:
				return 11;
		}
	}
	return 0;
}

int main()
{
	int tt, T;

	scanf("%d\n", &T);
	
	for (tt = 1; tt <= T; ++tt)
	{
		scanf("%d %d %d\n", &N, &M, &K);
		printf("Case #%d: %d\n", tt, solve());
	}
	return 0;
}
