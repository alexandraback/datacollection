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

U64 doit(int i0, int i1, U64 e0, U64 e1) {
	if (i0 == i1) {
		return 0;
	}
	if (e0 > E) {
		e0 = E;
	}
	int besti = i0;
	for (int i=i0; i<i1; i++) {
		if (v[i] > v[besti]) {
			besti = i;
		}
	}
	U64 n = besti - i0;
	U64 maxe = e0 + n * R;
	if (maxe > E) {
		maxe = E;
	}
	n = i1 - besti;
	S64 smine = e1 - n * R;
	if (smine < 0) {
		smine = 0;
	}
	U64 mine = smine;
	if (mine > maxe) {
		printf("fail!");
	}
	U64 spent = maxe - mine;
	U64 vv = spent * v[besti];
	vv += doit(i0, besti, e0, maxe);
	vv += doit(besti+1, i1, maxe - spent + R, e1);
	return vv;
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

	if (R > E) {
		R = E;
	}

	static char buf[16384];
	sprintf(buf, "%I64d", doit(0, N, E, 0));
	return buf;
}
