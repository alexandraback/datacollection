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

#define INF 100000

// bool timesOverlap(double *t0, double *t1, double *t2, double &t) {
// 	double tt[2] = {t0[0], t0[1]};
// 	MAX1(tt[0], t1[0]);
// 	MIN1(tt[1], t1[1]);
// 	MAX1(tt[0], t2[0]);
// 	MIN1(tt[1], t2[1]);
// 	if (tt[0] >= tt[1]) {
// 		return false;
// 	}
// 	t = tt[0];
// 	return true;
// }
bool timesOverlap(double *t0, double *t1) {
	if (MAX(t0[0], t1[0]) >= MIN(t0[1], t1[1])) {
		return false;
	}
	return true;
}

char *doC(char **&toks)
{
	int lane[51];
	int s[51];
	int p[51];
	int N = atoi(*toks++);
	for (int i=0; i<N; i++) {
		lane[i] = ((*toks++)[0] == 'L') ? 0 : 1;
		s[i] = atoi(*toks++);
		p[i] = atoi(*toks++);
	}
	doneParsingArgs(toks);

	double overlap[51][51][2];
	for (int i=0; i<N; i++) {
		for (int j=0; j<N; j++) {
			if (i == j) {
				overlap[i][j][0] = INF;
				overlap[i][j][1] = INF;
			} else if (s[i] == s[j]) {
				if (ABS(p[i] - p[j]) < 5) {
					overlap[i][j][0] = 0;
					overlap[i][j][1] = INF;
				} else {
					overlap[i][j][0] = INF;
					overlap[i][j][1] = INF;
				}
			} else {
				double t1 = (p[j] - p[i] - 5) / (double)(s[i] - s[j]);
				double t2 = (p[j] - p[i] + 5) / (double)(s[i] - s[j]);
				if (t2 < t1) {
					double t = t2;
					t2 = t1;
					t1 = t;
				}
				if (t2 < 0.00000001) {
					overlap[i][j][0] = INF;
					overlap[i][j][1] = INF;
				} else {
					overlap[i][j][0] = t1;
					overlap[i][j][1] = t2;
				}
			}
		}
	}

 	bool crash = false;
 	double ret = INF;
// 	for (int i=0; i<N; i++) {
// 		for (int j=0; j<N; j++) {
// 			printf("%10.2f-%10.2f ", overlap[i][j][0], overlap[i][j][1]);
// // 			if (overlap[i][j][0] == INF) {
// // 				continue;
// // 			}
// // 			for (int k=0; k<N; k++) {
// // 				if (overlap[i][k][0] == INF || overlap[j][k][0] == INF) {
// // 					continue;
// // 				}
// // 				double t;
// // 				if (timesOverlap(overlap[i][j], overlap[i][k], overlap[j][k], t)) {
// // 					if (t < ret) {
// // 						ret = t;
// // 						crash = true;
// // 					}
// // 				}
// // 			}
// 		}
// 		printf("\n");
// 	}

	int lanes[51][51];
	memset(lanes, 0, sizeof(lanes));
	do {
		// Assign the first unassigned time slice to a lane
		bool jep[51][51];
		memset(jep, 0, sizeof(jep));
		bool b = false;
		for (int i=0; i<N; i++) {
			for (int j=0; j<N; j++) {
				if (overlap[i][j][0] == INF) {
					continue;
				}
				if (lanes[i][j] != 0) {
					for (int k=0; k<N; k++) {
						if (overlap[i][k][0] == INF) {
							continue;
						}
						if (lanes[i][k] == 0) {
							if (timesOverlap(overlap[i][j], overlap[i][k])) {
								jep[i][k] = true;
								b = true;
							}
						}
					}
				}
			}
		}
		int ii, jj;
		double t;
		bool any_jep = b;
		b = false;
		for (int i=0; i<N; i++) {
			for (int j=0; j<N; j++) {
				if (overlap[i][j][0] == INF) {
					continue;
				}
				if (lanes[i][j] == 0 && (!any_jep || jep[i][j])) {
					if (!b || overlap[i][j][0] < t) {
						ii = i;
						jj = j;
						b = true;
						t = overlap[i][j][0];
					}
				}
			}
		}
		if (!b) {
			break;
		}
		if (!any_jep) {
			lanes[ii][jj] = 1;
			assert(lanes[jj][ii] == 0);
			lanes[jj][ii] = 2;
		} else {
			int i = ii;
			b = false;
			int ll;
			for (int j=0; j<N; j++) {
				if (overlap[i][j][0] == INF) {
					continue;
				}
				if (lanes[i][j] && j != jj) {
					if (timesOverlap(overlap[i][j], overlap[i][jj])) {
						if (b) {
							if (lanes[i][j] != ll) {
								// crash at t
								crash = true;
								MIN1(ret, MAX(overlap[i][j][0], overlap[i][jj][0]));
							}
						} else {
							b = true;
							ll = lanes[i][j];
							lanes[ii][jj] = lanes[i][j];
							assert(lanes[jj][ii] == 0);
							lanes[jj][ii] = 3 - lanes[i][j];
							// check other lane valid
							for (int k=0; k<N; k++) {
								if (k != jj) {
									if (lanes[jj][k] && timesOverlap(overlap[jj][k], overlap[jj][ii])) {
										if (lanes[jj][k] != lanes[jj][ii]) {
											crash = true;
											MIN1(ret, MAX(overlap[jj][k][0], overlap[jj][ii][0]));
										}
									}
								}
							}
						}
					}
				}
			}
		}
	} while (true);


	if (!crash) {
		return "Possible";
	}

	static char buf[16384];
	sprintf(buf, "%1.6f", ret);
	return buf;
}

