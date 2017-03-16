#include "stdio.h"
#include "string.h"
#include "math.h"
#include "set"
#include "deque"
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
int dwar(deque<double> n1, deque<double> n2)
{
	int score = 0;
	while (!n1.empty())
	{
		if (n1.front() < n2.front()) // cannot win anyway
		{
			n1.pop_front();
			n2.pop_back();
			continue;
		}
		if (n1.front() > n2.front())
		{
			n1.pop_front();
			n2.pop_front();
			score++;
			continue;
		}
	}
	return score;
}

int war(deque<double> n1, deque<double> n2)
{
	int score = 0;
	while (!n1.empty())
	{
		double b1 = n1.front();
		n1.pop_front();

		double b2 = -1;
		for (deque<double>::iterator it = n2.begin(); it != n2.end(); ++it)
		{
			if ((*it) > b1)
			{
				b2 = *it;
				n2.erase(it);
				break;
			}
		}
		if (b2 < 0)
		{
			b2 = n2.front();
			n2.pop_front();
		}

		if (b1 > b2)
			score++;
	}
	return score;
}

int main()
{
	int tt, T;
	int N;
	deque<double> n1, n2;

	scanf("%d\n", &T);
	
	for (tt = 1; tt <= T; ++tt)
	{
		n1.clear();
		n2.clear();
		scanf("%d\n", &N);
		for (int i = 0 ; i < N; ++i)
		{
			double temp;
			scanf("%lf\n", &temp);
			n1.push_back(temp);
		}
		for (int i = 0 ; i < N; ++i)
		{
			double temp;
			scanf("%lf\n", &temp);
			n2.push_back(temp);
		}
		sort (n1.begin(), n1.end());
		sort (n2.begin(), n2.end());
#ifdef DBG
		debug("n1: ");
		for (int i = 0; i < n1.size(); ++i)
			debug("%f ", n1[i]);
		debug("\n");
		debug("n2: ");
		for (int i = 0; i < n2.size(); ++i)
			debug("%f ", n2[i]);
		debug("\n");
#endif
		printf("Case #%d: %d %d\n", tt, dwar(n1, n2), war(n1, n2));
	}
	return 0;
}
