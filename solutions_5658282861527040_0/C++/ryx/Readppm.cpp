/*#include "stdafx.h"
#include <time.h>
#include "ryx_bignum.h"8?
/**/
#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdio.h>
#include <queue>
using namespace std;
#define INPUT fi
#define OUTPUT fo
FILE *fi, *fo;
#define NUM 105
#define LEN 105
int comp(const void *a1, const void *a2)
{
	char *p1, *p2;
	p1 = (char *)a1;
	p2 = (char *)a2;
	return strcmp(p1, p2);
}
int main()
{
	fi = fopen("B-small-attempt0.in", "r");
	fo = fopen("result.txt", "wb");
	int i, t, r, j, re;
	fscanf(INPUT, "%d", &t);
	int a, b, k;
	for(r=0; r<t; r++) {
		fscanf(INPUT, "%d %d %d", &a, &b, &k);
		re = 0;
		for(i=0; i<a; i++)
			for(j=0; j<b; j++)
				if ((i&j) < k)
					re++;
		fprintf(OUTPUT, "Case #%d: ", r+1);
		fprintf(OUTPUT, "%d\n", re);
	}
	return 0;
}	