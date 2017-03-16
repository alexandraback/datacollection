/*
 * Google Code Jam
 * Round 1A 2012
 * Problem B. Kingdom Rush
 */

#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;

struct level {
	int one, two;
	bool done1, done2;
};

bool operator <(level a, level b) {
	return a.two < b.two || a.two == b.two && a.one < b.one;
}

int main() {
	int tt;
	cin >> tt;
	for (int t = 1; t <= tt; t++) {
		int n;
		cin >> n;
		level lvl[1001];
		for (int i = 0; i < n; i++) {
			cin >> lvl[i].one >> lvl[i].two;
			lvl[i].done1 = false;
			lvl[i].done2 = false;
		}
		sort(lvl, lvl + n);
		int starts = 0, done2_count = 0, done1_count = 0;
		while (true) {
			bool improvement = false;
			int i = 0;
			while (i < n && lvl[i].two <= starts) {
				if (!lvl[i].done2) {
					lvl[i].done2 = true;
					starts = starts + (lvl[i].done1 ? 1 : 2);
					done2_count++;
					improvement = true;
				}
				i++;
			}
			for (i=n-1; i>= 0; i--) {
				if (!lvl[i].done1 && !lvl[i].done2 && lvl[i].one <= starts) {
					lvl[i].done1 = true;
					starts = starts + 1;
					done1_count++;
					improvement = true;
					break;
				}
			}
			if (!improvement)
				break;
		}
		if (done2_count == n)
			printf("Case #%d: %d\n", t, done1_count + done2_count);
		else
			printf("Case #%d: Too Bad\n", t);
	}
	return 0;
}
