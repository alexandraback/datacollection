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

bool isPalindrome(U64 v) {
	static int vv[200];
	int n = 0;
	while (v) {
		vv[n++] = v % 10;
		v /= 10;
	}
	for (int i=0, j=n-1; i<j; i++, j--) {
		if (vv[i] != vv[j]) {
			return false;
		}
	}
	return true;
}

char *doC(char **&toks)
{
	U64 A = _atoi64(*toks++);
	U64 B = _atoi64(*toks++);
	doneParsingArgs(toks);

	U64 aa = (U64)sqrt((double)A);
	U64 bb = (U64)sqrt((double)B) + 1;

	int c = 0;
	for (U64 i=aa; i<bb; i++) {
		if (isPalindrome(i)) {
			U64 sq = i * i;
			if (sq >= A && sq <= B) {
				if (isPalindrome(sq)) {
					//printf("%d %I64d (%I64d)\n", c, i, sq);
					c++;
				}
			}
		}
	}
	static char buf[16384];
	sprintf(buf, "%d", (int)c);
	return buf;
}
