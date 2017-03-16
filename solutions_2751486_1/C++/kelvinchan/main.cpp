#include "stdio.h"
#include "string.h"
#include "math.h"
#include "vector"
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
double solve(int N, int X, int Y)
{
	return 0;
}
int nCr(int n, int r)
{
	if (n < 0 || r > n)
	{
		printf("nCr(%d, %d): Error!!!!!!\n", n, r);
		return 0;
	}

	if ( r > n / 2)
		r = n - r;
	if (r == 0)
		return 1;
	else if (r == 1)
		return n;
	return nCr(n - 1, r - 1) + nCr(n - 1, r);
}

struct item
{
	bool isConsonents;
	int start;
	int length;
};

int main()
{
	int tt, T;
	int n;

	scanf("%d\n", &T);
	
	for (tt = 1; tt <= T; ++tt)
	{
		vector<item> all;
		char c;
		int consonents = 0;
		int length = 0;
		debug ("[ Case %d ]\n", tt);
		while (1)
		{
			scanf("%c", &c);
			if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
			{
				if (consonents > 0)
				{
					debug ("[%d, %d] (%d consonents)\n", length - consonents, length - 1 , consonents);
					item x = {true, length - consonents, consonents};
					all.push_back(x);
				}
				consonents = 0;
			}
			else if (c >= 'a' && c <= 'z')
			{
				consonents++;
			}
			else
			{
				if (consonents > 0)
				{
					debug ("[%d, %d] (%d consonents)\n", length - consonents, length - 1, consonents);
					item x = {true, length - consonents, consonents};
					all.push_back(x);
				}
				break;
			}
			++length;
		}
		debug("length: %d\n", length);
		scanf("%d\n", &n);

		unsigned int count = 0;
		int last_consonent_start = -1;
		for (vector<item>::iterator itr = all.begin(); itr != all.end(); ++itr)
		{
			if (itr->isConsonents && itr->length >= n)
			{
				unsigned int before = 1;
				if (last_consonent_start < itr->start)
					before = itr->start - last_consonent_start;
				unsigned int after = length - itr->length - itr->start + 1;
				debug("before:%d , after:%d\n", before, after);
				last_consonent_start = itr->start + itr->length - n;
				count += before * after;
				if (itr->length > n)
				{
					count += before * (itr->length - n);
					count += after * (itr->length - n);
					if (itr->length >= n + 2)
					{
						int r = itr->length - (n + 2) + 1;
						count += (r + 1) * r / 2;
					}
				}
			}
		}
		printf("Case #%d: %u\n", tt, count);

#if 0
		// stupid method
		int count2 = 0;
		for (int i = 0; i <= length; ++i)
		{
			for (int j = n ; i+j <= length; ++j)
			{
				bool done = false;
				for (vector<item>::iterator itr = all.begin(); !done && itr != all.end(); ++itr)
				{
					if (itr->isConsonents)
					{
						if (MIN(i + j, itr->start + itr->length) - MAX(i, itr->start) >= n)
						{
							//debug("[%d, %d]\n", i, j);
							done = true;
						}
					}
				}				
				if (done)
					count2++;
			}
		}
		if (count != count2)
			printf("Wrong!!! Case #%d: %d\n", tt, count2);
#endif
	}
	return 0;
}
