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

char *doC(char **&toks)
{
	int R = atoi(*toks++);
	int N = atoi(*toks++);
	int M = atoi(*toks++);
	int K = atoi(*toks++);
	U64 V[8000][12];
	for (int i=0; i<R; i++) {
		for (int j=0; j<K; j++) {
			V[i][j] = _atoi64(*toks++);
		}
	}
	doneParsingArgs(toks);

	int base = 4;
	int mx = 4*4*4;

	static double p[5*5*5][4*4*4];
	for (int i=0; i<5*5*5; i++) {
		for (int j=0; j<4*4*4; j++) {
			p[i][j] = 0;
		}
	}
	for (int i=2; i<=M; i++) {
		for (int j=2; j<=M; j++) {
			for (int k=2; k<=M; k++) {
				int v = i - 2 + base*(j-2) + base*base*(k-2);
				#define DO(ii, jj, kk) { \
					int pp = (ii ? i : 1) * (jj ? j : 1) * (kk ? k : 1); \
					p[pp][v] += 1; \
				}
				DO(1,1,1);
				DO(0,1,1);
				DO(1,0,1);
				DO(0,0,1);
				DO(1,1,0);
				DO(0,1,0);
				DO(1,0,0);
				DO(0,0,0);
			}
		}
	}
	for (int i=0; i<5*5*5; i++) {
		double c = 0;
		for (int j=0; j<4*4*4; j++) {
			c += p[i][j];
		}
		for (int j=0; j<4*4*4; j++) {
			if (c > 0.5) {
				p[i][j] = p[i][j] / c;
			}
		}
	}

	static char buf[8000*15] = "\n";
	int bi = 1;
	for (int i=0; i<R; i++) {
		U64 *vv = V[i];
		double prob[4*4*4];
		for (int j=0; j<mx; j++) {
			prob[j] = 1;
		}
		for (int j=0; j<K; j++) {
			double *pp = p[vv[j]];
			for (int k=0; k<mx; k++) {
				prob[k] *= pp[k];
			}
		}

		int best = 0;
		int bestchoices[8000];
		int bestci = 0;
		for (int j=1; j<mx; j++) {
			if (prob[j] > prob[best]) {
				best = j;
				bestci = 0;
				bestchoices[0] = j;
			} else if (prob[j] == prob[best]) {
				bestchoices[bestci++] = j;
			}
		}
		if (bestci > 1) {
			best = bestchoices[rand() % bestci];
		}

		static char buf2[15];
		int b = best;
		for (int j=0; j<N; j++) {
			int n = 2 + (b % base);
			b -= b % base;
			b /= base;
			buf2[j] = '0' + n;
		}
		buf2[N] = 0;
		int len = strlen(buf2);
		memcpy(buf + bi, buf2, len);
		bi += len;
		buf[bi++] = '\n';
		buf[bi] = 0;
	}

	return buf;
}
