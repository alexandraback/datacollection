//============================================================================
// Name        : A-A.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <stdio.h>

int LR[60], n;
double position[60], speed[60];
double collision[60][60];
double check(int i, int j) {
	if (speed[i] == speed[j])
		return -1;
	if (position[i] > position[j])
		return (position[i] - position[j] - 5) / (speed[j] - speed[i]);
	else
		return (position[j] - position[i] - 5) / (speed[i] - speed[j]);
}
bool change(int id) {
	for (int i = 0; i < n; ++i) {
		if (id == i)
			continue;
		double d = position[i] - position[id];
		if (d < 5 && d > -5)
			return false;
	}
	//LR[id] = 1 - LR[id];
	return true;
}
double work() {
	double rv = 0;
	int cnt = 100000;
	while (cnt) {
		double mintime = -1;
		int idx, idy;
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < n; ++j) {
				if (LR[i] == LR[j]) {
					double t = check(i, j);
					if (t >= 0) {
						if (mintime < 0 || mintime > t) {
							mintime = t;
							idx = i;
							idy = j;
						}
					}
				}
			}
		}
		if (mintime < 0)
			return -1;
		//printf("%lf\n", mintime);
		rv += mintime;
		for (int i = 0; i < n; ++i)
			position[i] += speed[i] * mintime;
		bool cx = change(idx);
		bool cy = change(idy);
		if (cx)
			LR[idx] = 1 - LR[idx];
		else if (cy)
			LR[idy] = 1 - LR[idy];
		else
			break;
		cnt--;
	}
	return rv;
}
int main() {
	int nc, c;
	char ctmp;
	freopen("/home/panda/codejam/in", "r", stdin);
	freopen("/home/panda/codejam/out", "w", stdout);
	scanf("%d", &nc);
	for (c = 1; c <= nc; ++c) {
		scanf("%d", &n);
		for (int i = 0; i < n; ++i) {
			while (scanf("%c", &ctmp))
				if (ctmp == 'L' || ctmp == 'R')
					break;
			if (ctmp == 'L')
				LR[i] = 0;
			else
				LR[i] = 1;
			scanf("%lf%lf", &speed[i], &position[i]);
		}
		double ans = work();
		if (ans < 0)
			printf("Case #%d: Possible\n", c);
		else
			printf("Case #%d: %g\n", c, ans);
	}
	return 0;
}
