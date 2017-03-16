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
#define MAX_COUNT 1000001
int cnt[MAX_COUNT];

void compute()
{
	for (int i = 0; i < MAX_COUNT; ++i)
		cnt[i] = 1e9;
	cnt[1] = 1;

	char str[16];
	for (int i = 2; i < MAX_COUNT; ++i)
	{
		if ( cnt[i] > i )
		{
			int rev = 0;
			if (i % 10 == 0)
				rev = 0;
			else
			{
				sprintf(str, "%u", i);
				for (int j = strlen(str)-1; j >= 0; --j)
					rev = rev*10 + str[j]-'0';
				if (rev >= MAX_COUNT)
					rev = 0;
			}
			debug("cnt[%d] cnt[%d] = %d  || cnt[%d] = %d\n", i, i-1, cnt[i-1], rev, cnt[rev]);

			cnt[i] = MIN(cnt[i-1] + 1, cnt[rev] + 1);
			debug("cnt[%d] => %d\n", i, cnt[i]);
		}
	}
}
int solve(int N)
{
	debug("%d %d\n", N, cnt[N]);
	return cnt[N];
}

int main()
{
	int tt, T;
	int N;

	compute();
	scanf("%d\n", &T);
	
	for (tt = 1; tt <= T; ++tt)
	{
		scanf("%d\n", &N);
		printf("Case #%d: %d\n", tt, solve(N));
	}
	return 0;
}
