#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_T (20)
#define MAX_A (100001)

static double p[MAX_A];
static double pbest[MAX_A];
static double pworst[MAX_A];

#define EPSILON 0.0000001

int
equal (double a, double b)
{
    if (a < b) {
	    return ((b - a) < EPSILON);
	}  
	return ((a - b) < EPSILON);
}

double
compute (unsigned int A, unsigned int B)
{
    double m;

    /* haven't typed anything yet */
    if (!A) {
       return (B + 1.0);
    }
    /* typed everything correctly so far */
    if (equal(pbest[A], 1.0)) {
        return (B - A + 1.0);
    }
    /* compute best case so far */
    m = B + 2.0;  /* return + B + return */
    int to_type = B - A; 
    int bs = 0;
    while (A > 0) {
		/* to go forward */
	    double cur = (pbest[A] * (to_type + 1))  +
	                   ((1 - pbest[A]) * (to_type + B + 2)) 
			+ bs;
	    if (cur < m) {
	        m = cur;
	    }
	    --A;
to_type++;
bs++;
    }
    return (m);
}

int
main (int argc, char *argv[])
{
    int max_tc;

    if (1 != scanf("%d\n", &max_tc)) {
        fprintf(stderr, "failed to scan # test cases\n");
	return (1);
    }
    p[0] = 1.0;
    pbest[0] = 1.0;
    pworst[0] = 1.0;
    for (int tc = 1; tc <= max_tc; ++tc) {
	unsigned int A, B;
        if (2 != scanf("%d %d\n", &A, &B)) {
	     fprintf(stderr, "failed to scan A,b test case %d\n", tc);
	     return (1);
	}
	for (int j = 0; j < A; j++) {
	    double d;
	    if (1 != scanf("%lg ", &d)) {
	        fprintf(stderr, "failed to scan p #%d on tc %d\n", j, tc);
		return (1);
	    }
	    p[j+1] = d;
	    pbest[j+1] = pbest[j] * d;
	    //pworst[j+1] = (1.0 - pbest[j]) * (1.0 - d);
	}
	double keys = compute(A, B);
	printf("Case #%d: %.6g\n", tc, keys);
    }
    return(0);
}
