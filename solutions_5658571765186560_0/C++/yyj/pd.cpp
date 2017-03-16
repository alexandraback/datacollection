/*
 * pd.cpp
 *
 *  Created on: 2015年4月12日
 *      Author: ying
 */

#include<iostream>
#include<cstdio>
using namespace std;

int X, R, C;

bool solve () {
	if ((R * C) % X != 0)
		return false;
	if ((R == 1 || C == 1) && X > 2)
		return false;
	if (X == 4 && (R == 2 || C == 2))
		return false;
	return true;
}

int main () {
	int t;
	scanf ("%d", &t);
	for (int i = 1; i <= t; i++) {
		scanf ("%d %d %d", &X, &R, &C);
		if (solve ()) {
			printf("Case #%d: GABRIEL\n", i);
		} else {
			printf("Case #%d: RICHARD\n", i);
		}
	}
	return 0;
}


