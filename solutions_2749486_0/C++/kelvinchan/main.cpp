#include "stdio.h"
#include "string"
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
int X, Y;

string solve(int step, int x, int y)
{
	string result ="";
	if (x < X)
	{
		for (x; x<X; ++x)
			result = result + "WE";
	}
	else if (x > X)
	{
		for (x; x>X; --x)
			result = result + "EW";
	}

	if (y < Y)
	{
		for (y; y<Y; ++y)
			result = result + "SN";
	}
	else if (y > Y)
	{
		for (y; y>Y; --y)
			result = result + "NS";
	}
	return result;
}
#if 0
string solve2(int step, int x, int y)
{
	debug("(%d, %d)\n", x, y);
	if (step > 500)
		return "";
	if (x == X && y == Y)
		return " ";
	string result;
	result = solve(step+1, x + step, y);
	if (! result.empty())
		return "E" + result;
	
	result = solve(step+1, x - step, y);
	if (! result.empty())
		return "W" + result;
	}
	
	result = solve(step+1, x, y + step);
	if (! result.empty())
		return "N" + result;

	result = solve(step+1, x, y - step);
	if (! result.empty())
		return "S" + result;
	
	return "";
}
#endif

int main()
{
	int tt, T;

	scanf("%d\n", &T);
	
	for (tt = 1; tt <= T; ++tt)
	{
		scanf("%d %d\n", &X, &Y);
		printf("Case #%d: %s\n", tt, solve(1, 0, 0).c_str());
	}
	return 0;
}
