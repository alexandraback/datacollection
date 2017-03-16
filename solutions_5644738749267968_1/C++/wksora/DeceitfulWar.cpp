/*
 * Deceitful War Google code jam
 *
 *  Created on: 2014Äê4ÔÂ12ÈÕ
 *      Author: Bevoid
 */
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <queue>

using namespace std;

double naomi[1010];
double ken[1010];
int N;

int main() {
	freopen("D:/Downloads/D-large.in", "r", stdin);
	freopen("d:/out1.out", "w", stdout);
	int T;
	while (scanf("%d", &T) != EOF) {
		int cases = 0;
		
		while (cases++ < T) {
			scanf("%d", &N);
			for (int i = 0; i < N; i++) {
				scanf("%lf", naomi + i);
			}
			for (int i = 0; i < N; i++) {
				scanf("%lf", ken + i);
			}

			sort(naomi, naomi + N);
			sort(ken, ken + N);

			int points = 0;
			int orginPoints = 0;
			
			int ni = 0, ki = 0;
			while (ni < N) {
				while (ni < N && naomi[ni] < ken[ki]) ni++;
				if (ni != N) {
					points++;
					ni++;
					ki++;
				}
			}

			ni = 0;
			ki = 0;
			while (ki < N) {
				while (ki < N && ken[ki] < naomi[ni]) ki++;
				if (ki != N) {
					orginPoints++;
					ni++;
					ki++;
				}
			}

			printf("Case #%d: %d %d\n", cases, points, N - orginPoints);
		}



	}
	return 0;
}
