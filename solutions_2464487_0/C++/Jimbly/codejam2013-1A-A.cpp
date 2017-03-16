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

U64 P(U64 n) {
	return n*(n + 1)*(2*n + 1)/6;
}

// r^2 + r+1^2 + ... r+(n-1)^2
U64 F(U64 r, U64 n) {
	return n*r*r + 4*(n*(n-1)/2)*r + 4*P(n-1);
}

U64 cost(U64 r, U64 n) {
	return F(r+1, n) - F(r, n);
}

char *doA(char **&toks)
{
	U64 r = _atoi64(*toks++);
	U64 t = _atoi64(*toks++);
	doneParsingArgs(toks);

	U64 mn = 0;
	U64 mx = 1;
	do {
		U64 v = cost(r, mx);
		if (v > t) {
			break;
		}
		mx *= 2;
		mn *= 2;
	} while (true);
	do {
		U64 md = mn + (mx - mn) / 2;
		U64 v = cost(r, md);
		//printf("%I64d: %I64d (%I64d %I64d)\n", md, v, mn, mx);
		if (v > t) {
			mx = md;
		} else if (v <= t) {
			mn = md;
		}
		if (mn + 1 == mx) {
			static char buf[16384];
			sprintf(buf, "%I64d", mn);
			return buf;
		}
	} while (true);
	return "";
}
