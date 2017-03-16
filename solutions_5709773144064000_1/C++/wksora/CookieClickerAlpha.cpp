/*
 * Magic Trick  Google code jam
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

double C,F,X;

double calcTime(int n) {
	double total = 0;
	int x = n;
	while (x!=0) {
		total = total + C/((x - 1) * F + 2);
		x--;
	}
	return total;
}

int main() {
	freopen("D:/Downloads/B-large.in", "r", stdin);
	freopen("d:/out1.out", "w", stdout);
	int T;
	while (scanf("%d", &T) != EOF) {
		int cases = 0;
		while (cases++ < T) {
			printf("Case #%d: ", cases);

			
			scanf("%lf%lf%lf", &C, &F, &X);

			double minTime = X / 2;
			for (int i = 1;; i++) {
				double tmp = calcTime(i);
				double tmp2 = X / (i * F + 2);
				if (tmp + tmp2 < minTime) {
					minTime = tmp + tmp2;
				} else {
					break;
				}
			}
			printf("%.7lf\n", minTime);

		}
	}
	return 0;
}
