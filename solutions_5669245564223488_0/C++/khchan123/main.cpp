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
int N;
unsigned long long ways;
string car[128];

void solve ()
{
	ways = 0;
	int index[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17};
	do
	{
		int checked [26] = {0};
		char last = car[index[0]][0];
		bool valid = true;
		for (int i = 0; valid && i < N; ++i)
		{
			debug(">>> Checking car[%d]: %s\n", i, car[index[i]].c_str());
			for (int j = 0; valid && j < car[index[i]].size(); ++j)
			{
				if (car[index[i]][j] != last)
				{
					if (checked[car[index[i]][j] - 'a'])
					{
						debug(">>> Checkpoint 1\n");
						valid = false;
					}
				}
				checked[car[index[i]][j] - 'a'] = 1;
				last = car[index[i]][j];
				debug(">>> Checking: %c\n", car[index[i]][j]);
			}
		}
		if (valid)
		{
			debug(">>> Pattern is valid\n");
			ways++;
		}
		else
			debug(">>> Pattern is NOT valid\n");
	}
	while ( std::next_permutation(index, index+N) );
	return;
}

int main()
{
	int tt, T;

	scanf("%d\n", &T);
	
	for (tt = 1; tt <= T; ++tt)
	{
		scanf("%d\n", &N);
		for (int i = 0; i < N; ++i)
		{
			char buf[128] = {0};
			scanf("%s", buf);
			car[i] = buf;
		}
		solve();
		printf("Case #%d: %d\n", tt, ways);
	}
	return 0;
}
