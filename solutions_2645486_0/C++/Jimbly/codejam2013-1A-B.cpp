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

static U64 E, R, N, v[100001];

U64 doit(int idx, U64 e) {
	if (e > E) {
		e = E;
	}
	if (idx == N - 1) {
		return e * v[idx];
	}
	U64 best = 0;
	for (U64 i=0; i<=e; i++) {
		U64 vv = i * v[idx] + doit(idx + 1, e - i + R);
		if (vv > best) {
			best = vv;
		}
	}
	return best;
}

char *doB(char **&toks)
{
	E = atoi(*toks++);
	R = atoi(*toks++);
	N = atoi(*toks++);
	for (U64 i=0; i<N; i++) {
		v[i] = atoi(*toks++);
	}
	doneParsingArgs(toks);

	

	static char buf[16384];
	sprintf(buf, "%I64d", doit(0, E));
	return buf;
}
