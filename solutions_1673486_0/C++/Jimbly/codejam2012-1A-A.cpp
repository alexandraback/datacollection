// Using libUtil from libGlov (Game Library of Victory) available at http://bigscreensmallgames.com/libGlov
// Some solutions may use BigInteger from http://mattmccutchen.net/bigint/
#include "bigint/BigIntegerAlgorithms.hh"
#include "bigint/BigIntegerUtils.hh"
#include "utilUtils.h"
#include "utilFile.h"
#include "utilString.h"
#include "assert.h"
#include "utilArray.h"
#include <string.h>
#include <stdio.h>
#include <stdarg.h>
#include <conio.h>
#include "utilRand.h"
#include "utilHashTable2.h"
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <algorithm>
using namespace std;
#pragma warning(disable:4018)
extern void doneParsingArgs(char **&toks);

char *doA(char **&toks)
{
	int A = atoi(*toks++);
	int B = atoi(*toks++);
	double p[100001];
	for (int i=0; i<A; i++) {
		p[i] = atof(*toks++);
	}
	doneParsingArgs(toks);

	double pp = 1.0;
	for (int i=0; i<A; i++) {
		pp *= p[i];
		p[i] = pp;
	}

	double best = B + 2;
	for (int i=0; i<A; i++) {
		double myp = p[A - 1 - i];
		double myexpected = (i*2 + B - A + 1) + (1 - myp) * (B + 1);
		//printf("bs %d : %1.2f\n", i, myexpected);
		if (myexpected < best) {
			best = myexpected;
		}
	}

	static char buf[16384];
	sprintf(buf, "%1.6f", best);
	return buf;
}

