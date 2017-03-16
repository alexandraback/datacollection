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
double solve(double C, double F, double X)
{
	int f = 0; // farm
	double t0 = 0; // time for the farm f-1 built
	double cps = 2; // cookie per second
	double time_needed = X/cps;
	debug("C=%.6g, F=%.6g, X=%.6g, cps=%.6g\n", C, F, X, cps);

	for (f = 1 ; true; ++f)
	{
		double t1 = t0 + (C/cps); // time for the farm f built
		t0 = t1;
		cps += F;
		double t2 = t1 + (X/cps); // total time needed for f farms;
		debug("Farm %d: t0=%.6g, t1=%.6g, t2=%.6g\n", f, t0, t1, t2);
		debug("Time needed with %d farms = %.6g\n", f, t2);
		if (t2 < time_needed)
			time_needed = t2;
		else
			break;
	}
	return time_needed;
}

int main()
{
	int tt, T;
	double C, F, X;

	scanf("%d\n", &T);
	
	for (tt = 1; tt <= T; ++tt)
	{
		scanf("%lf %lf %lf\n", &C, &F, &X);
		printf("Case #%d: %.7f\n", tt, solve(C, F, X));
	}
	return 0;
}
