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

char **lines;

char *check(int x, int y, int dx, int dy) {
	char c = ' ';
	for (int i=0; i<4; i++) {
		char c2 = lines[x + dx * i][y + dy * i];
		if (c2 == '.') {
			return NULL;
		}
		if (c2 == 'T') {
			continue;
		}
		if (c == ' ') {
			c = c2;
		} else if (c != c2) {
			return NULL;
		}
	}
	static char buf[16384];
	sprintf(buf, "%c won", c);
	return buf;
}

char *doA(char **&toks)
{
	char *_lines[4] = {
		*toks++,
		*toks++,
		*toks++,
		*toks++
	};
	lines = _lines;
	doneParsingArgs(toks);

	char *r;
#define CHECK(x,y,dx,dy) { r = check(x, y, dx, dy); if (r) { return r; }; }

	for (int i=0; i<4; i++) {
		CHECK(0, i, 1, 0);
		CHECK(i, 0, 0, 1);
	}
	CHECK(0, 0, 1, 1);
	CHECK(0, 3, 1, -1);

	for (int i=0; i<4; i++) {
		for (int j=0; j<4; j++) {
			if (lines[i][j] == '.') {
				return "Game has not completed";
			}
		}
	}
	return "Draw";
}
