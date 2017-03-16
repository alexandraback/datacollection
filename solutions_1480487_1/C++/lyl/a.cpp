/*
 * a.cpp
 *
 *  Created on: May 6, 2012
 *      Author: lyl
 */

#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <cmath>
using namespace std;

int n, a[100];
double score[100];

int main() {
	int ca;
	cin >> ca;
	for (int tt = 0; tt < ca; tt++) {
		cin >> n;
		double tot = 0;
		for (int i = 0; i < n; i++) {
			cin >> a[i];
			tot += a[i];
		}

		printf("Case #%d:", tt + 1);
		for (int i = 0; i < n; i++) {
			double l = 0, r = 1, mid;
			while (abs(r - l) > 1e-10) {
				mid = (l + r) / 2;

				double my = a[i] + tot * mid, tmp = 1 - mid;
				bool flag = false;
				for (int j = 0; j < n; j++) {
					if (i == j)
						continue;

					if (a[j] < my) {
						tmp -= (my - a[j]) / tot;
						if (tmp < 0)
							flag = true;
					}
				}

				if (flag)
					r = mid;
				else
					l = mid;
			}

			printf(" %.7lf", mid * 100.0);
		}
		printf("\n");
	}
}
