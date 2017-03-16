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

char *doB(char **&toks)
{
	int N = atoi(*toks++);
	int stars[1001][2];
	for (int i=0; i<N; i++) {
		stars[i][0] = atoi(*toks++);
		stars[i][1] = atoi(*toks++);
	}
	doneParsingArgs(toks);
	
	int b[1001];
	memset(b, 0, sizeof(b));
	int nstars = 0;
	int ret = 0;
	while (true) {
		int best = -1;
		int bestv = 0;
		bool done = true;
		bool did2 = false;
		for (int i=0; i<N; i++) {
			if (b[i] < 2 && stars[i][1] <= nstars) {
				done = false;
				did2 = true;
				nstars += 2 - b[i];
				b[i] = 2;
				ret++;
			} else if (!b[i] && stars[i][0] <= nstars) {
				if (best == -1 || stars[i][1] > bestv) {
					best = i;
					bestv = stars[i][1];
				}
				done = false;
			} else if (b[i] != 2) {
				done = false;
			}
		}
		if (did2) {
			continue;
		}
		if (done) {
			break;
		}
		if (best == -1) {
			return "Too Bad";
		}
		b[best] = 1;
		nstars++;
		ret++;
	}

	static char buf[16384];
	sprintf(buf, "%d", ret);
	return buf;
}

