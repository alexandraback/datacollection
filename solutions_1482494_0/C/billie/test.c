#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

#define MAX_T (100)
#define MAX_N (1000)

struct data {
    unsigned int a, b;
} data[MAX_N];
unsigned int games;
unsigned int stars;

#define MAX_A  10000

int compar(const void *vy, const void *vx)
{
    const struct data *x = (struct data *)vx;
    const struct data *y = (struct data *)vy;
    if (x->b < y->b) {
        return (-1);
    }
    if (x->b > y->b) {
        return (1);
    }
    if (x->a < y->a) {
        return (-1);
    }
    if (x->a > y->a) {
        return (1);
    }
    return (0);
}

int compar2(const void *vy, const void *vx)
{
    const struct data *x = (struct data *)vx;
    const struct data *y = (struct data *)vy;
    if (x->a < y->a) {
        return (-1);
    }
    if (x->a > y->a) {
        return (1);
    }
    if (x->b < y->b) {
        return (-1);
    }
    if (x->b > y->b) {
        return (1);
    }
    return (0);
}

void dump(int k, const char *fmt)
{
/*
fprintf(stderr, "with %d stars; %s\n", stars, fmt);
for (int j=0; j < k; j++) {
    fprintf(stderr, "  %d,%d\n", data[j].a, data[j].b);
}
*/
}

int
compute (unsigned int k)
{
    for (;k;) {
	qsort(data, k, sizeof(data[0]), compar);
dump(k, "by b,a descending");
    
	int j = k - 1;
        /* Play as many 2 star games as possible */
        while (data[j].b <= stars) {
            if (data[j].b == MAX_A) {
                return (1);
            }
            if (data[j].a == MAX_A) {
                stars++;
	    } else {
		stars += 2;
	    }
	    data[j].b = MAX_A;
	    games++;
    
	    if (!j) return (1);
	    j--;
        }
	int needed = data[j].b;
if (needed == MAX_A) {
    return (1);
}

	qsort(data, k, sizeof(data[0]), compar2);
//fprintf(stderr, "needed %d\n", needed);
dump(k, "by a,b descending");
	/* Play as many single 1 star game as needed */
	j = k - 1;
	while ((data[j].a <= stars) && (needed > stars)) {
	    stars++;
	    games++;
	    data[j].a = MAX_A;	/* already played */
	    if (!j) break;
	    j--;
	}
	if (needed > stars) {
	    return (0);
	}
    }
	return (1);
}

int
main (int argc, char *argv[])
{
    int max_tc;

    if (1 != scanf("%d\n", &max_tc)) {
        fprintf(stderr, "failed to scan # test cases\n");
	return (1);
    }
    for (int tc = 1; tc <= max_tc; ++tc) {
	unsigned int N;
        if (1 != scanf("%d\n", &N)) {
	     fprintf(stderr, "failed to scan N; test case %d\n", tc);
	     return (1);
	}
	stars = games = 0;
        int k = 0;
	for (int j = 0; j < N; j++) {
	    if (2 != scanf("%d %d\n", &data[k].a,&data[k].b)) {
	        fprintf(stderr, "failed to scan a,b; %d on tc %d\n", j, tc);
		return (1);
	    }

	    k++;
	}
	if (compute(k)) {
	    printf("Case #%d: %d\n", tc, games);
        } else {
	    printf("Case #%d: Too Bad\n", tc);
        }
    }
    return(0);
}
