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
	int lawn[100][100];
	int N = atoi(*toks++);
	int M = atoi(*toks++);
	for (int i=0; i<N; i++) {
		for (int j=0; j<M; j++) {
			lawn[i][j] = atoi(*toks++);
		}
	}
	doneParsingArgs(toks);

#define dof(arr, x, y, mx, dx, dy) \
	arr[i] = lawn[x][y];\
	for (int j=1; j<mx; j++) {\
		int v = lawn[x + dx*j][y + dy*j];\
		arr[i] = max(arr[i], v);\
	}
	
	int maxr[100], maxc[100];
	for (int i=0; i<N; i++) {
		dof(maxr, i, 0, M, 0, 1);
	}
	for (int i=0; i<M; i++) {
		dof(maxc, 0, i, N, 1, 0);
	}

	for (int i=0; i<N; i++) {
		for (int j=0; j<M; j++) {
			int v = lawn[i][j];
			if (v < maxr[i] && v < maxc[j]) {
				return "NO";
			}
		}
	}

	return "YES";
}
