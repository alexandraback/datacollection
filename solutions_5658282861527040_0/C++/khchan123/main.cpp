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
unsigned long long A, B, K;
unsigned long long solve()
{
	unsigned long long count = 0;
	for (unsigned long long a = 0; a < A; ++a)
	{
		for (unsigned long long b = 0; b < B; ++b)
		{
			debug("a(%llu) & b(%llu) = %llu\n", a, b, a&b);
			if ((a & b) < K)
			{
				debug ("counted!\n");
				count++;
			}
		}
	}
	return count;
}

int main()
{
	int tt, T;

	scanf("%d\n", &T);
	
	for (tt = 1; tt <= T; ++tt)
	{
		scanf("%d %d %d\n", &A, &B, &K);
		printf("Case #%d: %llu\n", tt, solve());
	}
	return 0;
}
