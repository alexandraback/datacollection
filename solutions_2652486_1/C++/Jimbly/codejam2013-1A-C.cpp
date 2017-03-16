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

int ri(int mx) {
	return rand() % mx;
}

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

	static char buf[8000*15] = "\n";
	int bi = 1;
	for (int i=0; i<R; i++) {
		static double p[9][13];
		for (int j=0; j<=M; j++) {
			for (int k=0; k<=N; k++) {
				p[j][k] = 0;
			}
		}
		static char buf2[15];
		bool perfect = false;
		for (int j=0; j<K && !perfect; j++) {
			for (int ii=0; ii<500 && !perfect; ii++) {
				U64 v = V[i][j];
				int nc[9] = {0};
				int nn=0;
				int r=0;
				while (v != 1 && nn <= N) {
					int k = ri(M - 2 + 1) + 2;
					if (v % k == 0) {
						v /= k;
						nc[k]++;
						nn++;
						r = 0;
					} else {
						r++;
						if (r == 20) {
							break;
						}
					}
				}
				if (v == 1 && nn <= N) {
					if (nn == N) {
						int ii = 0;
						for (int k=2; k<=M; k++) {
							for (int jj=0; jj<nc[k]; jj++) {
								buf2[ii++] = '0' + k;
							}
						}
						assert(ii == N);
						perfect = true;
					} else {
						for (int k=2; k<=M; k++) {
							p[k][nc[k]]+= nn*nn;
						}
					}
				}
			}
		}

		if (!perfect) {
			int ni = 0;
			int ns[12*8];
			for (int k=2; k<=M; k++) {
				int best = 0;
				double bestv = 0;
				int choices = 1;
				for (int j=1; j<=N; j++) {
					if (p[k][j] > bestv) {
						best = j;
						bestv = p[k][j];
						choices = 1;
					} else if (p[k][j] && p[k][j] == bestv) {
						choices++;
						if (!ri(choices)) {
							best = j;
						}
					}
				}
				for (int j=0; j<best; j++) {
					ns[ni++] = k;
				}
			}
			if (ni == 0) {
				ns[ni++] = 2;
			}
			while (ni < N) {
				ns[ni++] = ns[ri(ni)];
			}
			while (ni > N) {
				int idx = ri(ni);
				ns[idx] = ns[ni-1];
				--ni;
			}
			for (int j=0; j<N; j++) {
				buf2[j] = '0' + ns[j];
			}
		}
		buf2[N] = 0;
		memcpy(buf + bi, buf2, N);
		bi += N;
		buf[bi++] = '\n';
		buf[bi] = 0;
	}
	return buf;
}
